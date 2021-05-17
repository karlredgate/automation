        IDENTIFICATION DIVISION.
        PROGRAM-ID. HELLO-WORLD.
        DATA DIVISION.
        WORKING-STORAGE SECTION.
        01 HTTP_OK   PIC X(4)  VALUE "200".
        01 OUTPUT_TEXT PIC X(14) VALUE "Hello, World!".
        PROCEDURE DIVISION.
            CALL "set_http_status" USING HTTP_OK.
            CALL "append_http_body" USING OUTPUT_TEXT.
        STOP RUN.
