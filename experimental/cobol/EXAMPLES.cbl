
       IDENTIFICATION DIVISION.
       PROGRAM-ID.      EXAMPLES.
      *
       ENVIRONMENT DIVISION.
      * EXAMPLES.cbl: 3: error: syntax error, unexpected ENVIRONMENT,
      * expecting COMMON or EXTERNAL or RECURSIVE or INITIAL
       CONFIGURATION SECTION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
           SELECT SYSIN
               ASSIGN TO DA-S-SYSIN.
           SELECT SYSPRINT
               ASSIGN TO UT-S-SYSPRINT.
      *
       DATA DIVISION.
       FILE SECTION.
       FD SYSIN
           RECORD CONTAINS 80 CHARACTERS
           BLOCK CONTAINS 0 RECORDS
           LABEL RECORDS ARE OMITTED
           RECORDING MODE IS F.
       01 CARDREC PIC X(80).
       WORKING-STORAGE SECTION.
       01       WORKAREA-IND.
           02   WORKIND PIC S9(4) COMP OCCURS 750 TIMES.
      *
       PROCEDURE DIVISION.
       MAIN.
           DISPLAY 'Hello, world.'.
           STOP RUN.
