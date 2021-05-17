*> ** >>SOURCE FORMAT IS FREE

*> TECTONICS
*>   cobc -x -fdebugging-line testsqlite3.cob -lsqlite3

identification division.

  program-id.                          testsqlite3.

environment division.

  configuration section.

    repository.

      function all intrinsic.

data division.

  working-storage section.

    01  db-name                        pic x(256).
    01  db-handle                      pic s9(09) comp value zero.
    01  db-message                     pic x(256).

    01  sql-statement                  pic x(1024). *> use max 1023 characters.
    01  num-bytes                      pic s9(04) comp.
    01  num-columns                    pic s9(04) comp.
    01  pStmt                          usage pointer.
    01  zTail                          pic s9(04) comp.
    01  column-number                  pic s9(04) comp.

    01  column-type                    pic s9(04) comp.
      88  sqlite-integer               value 1. *> 64-bit signed integer.
      88  sqlite-float                 value 2. *> 64-bit IEEE floating point number.
      88  sqlite-text                  value 3. *> string.
      88  sqlite-blob                  value 4. *> BLOB
      88  sqlite-null                  value 5. *> NULL

    01  db-status                      pic s9(04) comp.
      88  sqlite-ok                    value zero.
            *> Operation successful and there were no errors.
      88  sqlite-error                 value 1.
            *> Generic error code used when no more specific one is available.
      88  sqlite-internal              value 2.
            *> Internal malfunction. Indicates a bug in the database engine.
      88  sqlite-perm                  value 3.
            *> Requested access mode for newly created database is unavailable.
      88  sqlite-abort                 value 4.
            *> Operation aborted prior to completion by application request.
      88  sqlite-busy                  value 5.
            *> Database could not be read/written because of concurrent activity.
      88  sqlite-locked                value 6.
            *> Write operation could not continue because of an access conflict.
      88  sqlite-nomem                 value 7.
            *> Database engine unable to allocate needed memory.
      88  sqlite-readonly              value 8.
            *> Attempt to alter data without write permission.
      88  sqlite-interrupt             value 9.
            *> Operation was interrupted by user. Transaction rolled back.
      88  sqlite-ioerr                 value 10.
            *> Operation terminated because of an operating system I/O error.
      88  sqlite-corrupt               value 11.
            *> Database file has been corrupted.
      88  sqlite-notfound              value 12.
            *> You should not see this error code reported.
      88  sqlite-full                  value 13.
            *> Disk holding the main database and/or temporary files is full.
      88  sqlite-cantopen              value 14.
            *> Unable to open primary database and/or temporary files.
      88  sqlite-protocol              value 15.
            *> Problem with file locking protocol. Should appear very, very rarely.
      88  sqlite-empty                 value 16.
            *> Code not currently used.
      88  sqlite-schema                value 17.
            *> The database schema has changed.
      88  sqlite-toobig                value 18.
            *> An sql statement, string or BLOB exceeded the compile and/or runtime limit.
      88  sqlite-constraint            value 19.
            *> An sql statement generated a constraint violation.
      88  sqlite-mismatch              value 20.
            *> Datatype mismatch.
      88  sqlite-misuse                value 21.
            *> Attempting to use an SQLite interface in an undefined/unsupported way.
      88  sqlite-nolfs                 value 22.
            *> Database file too large and Large File Support not available.
      88  sqlite-auth                  value 23.
            *> The sql statement being compiled is not authorised.
      88  sqlite-format                value 24.
            *> Code not currently used.
      88  sqlite-range                 value 25.
            *> Parameter number argument to a bind routine is out of range.
      88  sqlite-notadb                value 26.
            *> Attempting to open a non-SQLite database file.
      88  sqlite-notice                value 27.
            *> This code is only used by the log() callback routine.
      88  sqlite-warning               value 28.
            *> This code is only used by the log() callback routine.
      88  sqlite-row                   value 100.
            *> Indicates that another row of output is available.
      88  sqlite-done                  value 101.
            *> Indicates that the sql statement has run to completion.

procedure division.

testsqlite3-mainline.

  move "test.sdb" to db-name
  perform s001-open-database

  move "SELECT * from foo;" to sql-statement
  perform s003-sql-compile

  perform s002-close-database

  goback
  .

*> *****************************************************************************
*>  Internal subroutines.

s000-sqlite-error.
  *> ---------------------------------------------------------------------------
  *>  Converts the last API call error, for the specified SQLite3 database, to a
  *>  human readable message.
  *> ---------------------------------------------------------------------------

  *> call "sqlite3_errmsg" using by reference db-handle
                    *> returning db-message
  *> end-call

  display "SQLite3 ERROR: ", db-status end-display
  .

*> ***** OPEN & CLOSE of DATABASE

s001-open-database.
  *> ---------------------------------------------------------------------------
  *>  Opens the specified SQLite3 database.
  *> ---------------------------------------------------------------------------

  call "sqlite3_open" using concatenate(trim(db-name), x"00"),
                            by reference db-handle
                  returning db-status
  end-call

  evaluate true

    when sqlite-ok
>>D   display "DEBUG: database opened" end-display
>>D   display "DEBUG: database handle [", db-handle, "]" end-display
      continue

    when other
>>D   display "DEBUG: database not opened" end-display
      perform s000-sqlite-error
      goback

  end-evaluate
  .

s002-close-database.
  *> ---------------------------------------------------------------------------
  *>  Closes the specified SQLite3 database.
  *> ---------------------------------------------------------------------------

  call "sqlite3_close" using by reference db-handle
                   returning db-status
  end-call

  evaluate true

    when sqlite-ok
>>D   display "DEBUG: database closed" end-display
      continue

    when sqlite-busy
>>D   display "DEBUG: database remains open" end-display
      continue

    when other
>>D   display "DEBUG: database close error" end-display
      perform s000-sqlite-error
      goback

  end-evaluate
  .

*> ***** COMPILE, EXECUTE, RESET & DELETE of SQL STATEMENTS

  s003-sql-compile.
  *> ---------------------------------------------------------------------------
  *>  Compiles an SQL statement into a byte-code program.
  *> ---------------------------------------------------------------------------

  move length(trim(sql-statement)) to num-bytes
  add 1 to num-bytes end-add

  move zero to zTail

  call "sqlite3_prepare_v2" using by reference db-handle,
                                  concatenate(trim(sql-statement), x"00")
                                  num-bytes,
                                  by reference pStmt,
                                  zTail
                        returning db-status
  end-call

  evaluate true

    when sqlite-ok
>>D   display "DEBUG: sql statement compiled" end-display
      continue

    when other
>>D   display "DEBUG: sql statement compile failed" end-display
      perform s000-sqlite-error
      goback

  end-evaluate
  .

snnn-sql-execute.
  *> ---------------------------------------------------------------------------
  *>  Executes a compiled SQL statement.
  *> ---------------------------------------------------------------------------

  call "sqlite3_step" using by reference pStmt
                  returning db-status
  end-call

  evaluate true

    when sqlite-row
>>D   display "DEBUG: execute of compiled sql statement returned data" end-display
      *> Access the returned row using the DB_COLUMN_x 'access functions' and
      *>  then call this subroutine again to retrieve the next ROW of data.
      continue

    when sqlite-done
>>D   display "DEBUG: execute of compiled sql statement finished successfully" end-display
      *> The SQL statement finished executing successfully.
      *> Do not call this subroutine again without first calling snnn-sql-reset
      *> to return the virtual machine back to its initial state.
      continue

    when sqlite-busy
>>D   display "DEBUG: database locks could not be applied" end-display
      *> If the SQL statement is a COMMIT then you can retry the statement.
      *> For any other SQL statement you should rollback the transaction.
      continue

    when sqlite-ok
>>D   display "DEBUG: execute of compiled sql statement returned SQLITE-OK" end-display
      *> Not sure if we should ever get this.
      *> If we do then what should be done?
      continue

    when other
>>D   display "DEBUG: execute of compiled sql statement failed" end-display
      perform s000-sqlite-error
      goback

  end-evaluate
  .

snnn-sql-reset.
  *> ---------------------------------------------------------------------------
  *>  Resets a compiled SQL statement back to its initial state.
  *> ---------------------------------------------------------------------------

  call "sqlite3_reset" using by reference pStmt
                   returning db-status
  end-call

  evaluate true

    when sqlite-ok
>>D   display "compiled sql statement reset" end-display
      continue

    when other
>>D   display "reset of sql statement compile failed" end-display
      perform s000-sqlite-error
      goback

  end-evaluate
  .

snnn-sql-delete.
  *> ---------------------------------------------------------------------------
  *>  Deletes a compiled sql statement.
  *>
  *>  Note: Every compiled SQL statement must be deleted when it has been
  *>        finished with in order to avoid resource leaks.
  *> ---------------------------------------------------------------------------

  call "sqlite3_finalize" using by reference pStmt
                      returning db-status
  end-call

  evaluate true

    when sqlite-ok
>>D   display "compiled sql statement deleted" end-display
      continue

    when other
>>D   display "delete of sql statement compile failed" end-display
      perform s000-sqlite-error
      goback

  end-evaluate
  .

*> *****

snnn-get-column-bytes.
  *> ---------------------------------------------------------------------------
  *>  Returns the number of bytes in a TEXT or BLOB column.
  *> ---------------------------------------------------------------------------

  call "sqlite3_column_bytes" using by reference pStmt,
                                    column-number
                          returning num-bytes
  end-call
  .

snnn-get-column-count.
  *> ---------------------------------------------------------------------------
  *>  Returns the number of columns found in the result set (ROW).
  *>
  *>  Note: A value of zero indicates that no data was returned (for example an
  *>        SQL UPDATE statement was executed).
  *> ---------------------------------------------------------------------------

  call "sqlite3_column_count" using by reference pStmt
                          returning num-columns
  end-call
  .

snnn-get-column-type.
  *> ---------------------------------------------------------------------------
  *>  Returns the datatype for the specified column in the result set (ROW).
  *>
  *>  Note: The returned value is only meaningful if no type conversion has
  *>        occurred. After a type conversion, the value returned is undefined.
  *> ---------------------------------------------------------------------------

  call "sqlite_column_type" using by reference pStmt,
                                  column-number
                        returning column-type
  end-call.

snnn-get-column-value.
  *> ---------------------------------------------------------------------------
  *>
  *> ---------------------------------------------------------------------------

  .

end program testsqlite3.
