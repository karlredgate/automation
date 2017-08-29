;
; 8 byte stack and return stack items, but 4 byte cell for
; code fields
;
;       +- - - - - - -+
; NFA-->|  name field |
;       +-------------+
; LFA-->|  link field |
;       +-------------+
; CFA-->|  code field |
;       +-------------+
; PFA-->| param field |
;       +-------------+
;

[BITS 64]
        global  main
        extern  printf
        extern  trap_error_signals

%define CELL_SIZE  8  ; sizeof ACF
%define TOKEN_SIZE 4  ; sizeof ACF

%define IP rsi  ; instruction pointer
%define RP rsp  ; return stack pointer
%define SP rbp  ; parameter stack pointer
%define TOS rbx ; top of the stack - value
%define SCR r14 ; scratch

%define lastacf 0

        section .text

;
; NEXT is called at the end of each CODE word to
; fetch the next PF from the current word and call
; its code word.
;
%macro NEXT 0
        lodsd    ; mov eax, [rsi]
        jmp rax
        align 4
%endmacro

%macro PLACE 1
        dd cfa_%1
%endmacro

%macro NAMEFIELD 1
        align 16
        %strlen len %1
        %assign pad (4 - ((len+1) % 4))
        times pad db 0xAB
        db %1
        db len
%endmacro

%macro LINKFIELD 0
        dd lastacf
%endmacro

%macro CODEFIELD 1
        jmp %1
        db 0xDE,0xAD,0xFF
;        dd %1
%endmacro

%macro CODE 2
        section .text
        NAMEFIELD %1
        LINKFIELD
%2:
cfa_%2:
        %define lastacf cfa_%2
%endmacro

;
; do_colon (DOCOL) pushes the current words IP on the
; return stack and sets the IP to call the next word
; in the PF of the requested word.
;

docolon:
        ; push current IP on return stack
        push    IP
        ; load next body pointer
        lea     IP, [rax+8]
        NEXT

; do_colon as a codefield
%macro DOCOLON 0
        jmp docolon
        db 0xDE,0xAD,0xFF
%endmacro

%macro COLON 2
        section .text
        NAMEFIELD %1
        LINKFIELD
cfa_%2:
        %define lastacf cfa_%2
        DOCOLON
%endmacro

%macro END 0
        dd cfa_unnest
%endmacro

;
; Constant loads an 8 byte value from the PFA
; Since the PFA only points to the 4 byte address - add 4
;
do_constant:
        push    TOS
        mov     TOS, [rax+8]
        NEXT

; CONSTANT "foo", foo, 0xdeadbeef
%macro CONSTANT 3
        section .text
        NAMEFIELD %1
        LINKFIELD
cfa_%2:
        %define lastacf cfa_%2
        CODEFIELD do_constant
        dq %3
%endmacro


;
; _do_does( apf, does ) APF apf, does; {
;     push( (Cell)apf );
;     *(++rp) = (Cell)ip;
;     ip = does;
; }
;
; : (does>)  ( -- )  ip@ ta1+ codefield  ;
; : does>    ( -- )
;    compile (does>)
;    compile unnest
;    do-does ,  ]
; ; immediate
;


;
; Interpreter words
;

        CODE "exit", unnest
        mov     IP, [RP]
        lea     RP, [RP+8]
        NEXT

        CODE "lit", lit
        push    TOS
        lodsq
        mov     TOS, rax
        NEXT

        CODE "ip@", ip_fetch ; ( -- x )
        push    TOS
        ; mov     TOS, IP
        NEXT

        CODE ">ip", to_ip ; ( ip -- )
        ; mov     IP, TOS
        pop     TOS
        NEXT

        CODE "r@", r_fetch ; ( -- x )
        push    TOS
        mov     TOS, [RP]
        NEXT

        CODE "r>", r_from
        lea     RP, [RP-8]
        mov     [RP], TOS
        NEXT

        CODE ">r", to_r  ; ( x -- R: x )
        mov     TOS, [RP]
        lea     RP, [RP+8]
        NEXT

        CODE "@", fetch  ; ( addr -- val )
        mov     TOS, [TOS]
        NEXT

        CODE "!", store  ; ( value addr -- )
        pop     rax
        mov     [TOS], rax
        pop     TOS
        NEXT

;
; Stack manipulation
;

        CODE "drop", drop ; ( x -- )
        pop     TOS
        NEXT

        CODE "nip", nip ; ( x y -- y )
        pop     rax
        NEXT

        COLON "2drop", _2drop
        PLACE drop
        PLACE drop
        END

        CODE "swap", swap ; ( x y -- y x )
        mov     rax, [SP]
        mov     [SP], TOS
        mov     TOS, rax
        NEXT

        CODE "dup", dup  ; ( x -- x x )
        push    TOS
        NEXT

        CODE "over", over  ; ( x y -- x y x )
        push    TOS
        mov     TOS, [SP+8]
        NEXT

        CODE "under", under  ; ( x y -- y x y )
        pop     rax
        push    TOS
        push    rax
        NEXT

        CODE "tuck", tuck  ; ( x y -- y x y )
        pop     rax
        push    TOS
        push    rax
        NEXT

        CODE "rot", rot  ; ( x y z -- y z x )
        pop     rax     ; pop y
        pop     rcx     ; pop x
        push    rax     ; push y
        push    TOS     ; push z
        mov     TOS, rcx ; x -> TOS
        NEXT

        CODE "-rot", minus_rot  ; ( x y z -- z x y )
        pop     rax     ; pop y
        pop     rcx     ; pop x
        push    TOS     ; push z
        push    rcx     ; push x
        mov     TOS, rax
        NEXT

;
; Math words
;

        CODE "+", plus ; ( x y -- z )
        pop     rax
        add     TOS, rax
        NEXT

        CODE "*", multiply  ; ( x y -- z )
        imul    TOS, [SP]
        add     SP, CELL_SIZE
        NEXT

        CODE "1+", one_plus  ; ( x -- x+1 )
        inc     TOS
        NEXT

        CODE "1-", one_minus  ; ( x -- x-1 )
        dec     TOS
        NEXT

        CODE "0", zero  ; ( -- 0 )
        push    TOS
        mov     TOS, 0
        NEXT

        CODE "1", one  ; ( -- 1 )
        push    TOS
        mov     TOS, 1
        NEXT

        CODE "2", two  ; ( -- 2 )
        push    TOS
        mov     TOS, 2
        NEXT

        CONSTANT "3", three, 3
        CONSTANT "4", four,  4
        CONSTANT "5", five,  5
        CONSTANT "6", six,   6
        CONSTANT "7", seven, 7
        CONSTANT "8", eight, 8
        CONSTANT "9", nine,  9

;
; Logic words
;

        CODE "and", and
        pop     rax
        and     TOS, rax
        NEXT

        CODE "or", or
        pop     rax
        or      TOS, rax
        NEXT

        CODE "xor", xor
        pop     rax
        xor     TOS, rax
        NEXT

;
; System words
;

        CODE "die", die  ; ( -- )
        mov     ebx, 0
        mov     eax, 60
        syscall
        NEXT

        COLON "cold", _cold
cold_start:
        PLACE one
        PLACE two
        PLACE plus
        PLACE nine
        PLACE tuck
        PLACE lit
        dq      0xdeadbeeffeedface
        PLACE die
        END

        section .text
main:
        push    rbp
        mov     rbp, rsp
        call    trap_error_signals
        ; mov     RP, returnstack         ; Setup return stack
        ; mov     SP, stack               ; setup param stack
boot:
        mov     IP, cold_start
        NEXT
        rdtsc
        mov     rsi, rdx        ; arg1
        mov     rdx, rax        ; arg2
        mov     rdi, message    ; arg0
        mov     eax, 0
        call    printf
        leave
        ret


        section .data

message:
        db      'TSC = 0x%08x.%08x', 10, 0

        section .bss

stack:  resq      1024

returnstack:
        resq      1024

; vim:autoindent
; vim:expandtab
