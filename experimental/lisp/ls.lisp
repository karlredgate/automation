#!/opt/local/bin/sbcl --script

; (sb-ext:run-program "/bin/ls" '(".") :output :stream)
; (sb-ext:run-program "/bin/ls" '("..") :output *standard-output*)
(run-program "/bin/ls" '("..") :output *standard-output*)

; vim: set autoindent expandtab sw=4
