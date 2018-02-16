package main

import (
        "database/sql"
        "fmt"
        _ "github.com/mattn/go-sqlite3"
        "log"
)

func main() {
    db, err := sql.Open("sqlite3", "./foo.db")
    if err != nil { log.Fatal(err) }
    defer db.Close()

    sqlStmt := `
SELECT
datetime(visit_time / 1000000 + (strftime('%s', '1601-01-01')), 'unixepoch','localtime'),
  urls.title, urls.url
FROM visits join urls on visits.url = urls.id
ORDER BY visit_time DESC
LIMIT 25000;
`

    rows, err := db.Query(sqlStmt)
    if err != nil {
        log.Fatal(err)
    }
    defer rows.Close()

    previous := ""
    last_ts := ""
    count := 0

    for rows.Next() {
        var timestamp string
        var title string
        var url string

        err = rows.Scan(&timestamp, &title, &url)
        if err != nil { log.Fatal(err) }

        if previous == url {
            count += 1
            last_ts = timestamp
            continue
        }
        if count != 0 {
            fmt.Println( "   last repeated ", count, " times until ", last_ts )
            count = 0
        }
        fmt.Println( timestamp, title )
        previous = url
    }
    err = rows.Err()
    if err != nil {
        log.Fatal(err)
    }

}

/* vim: set autoindent expandtab sw=4 : */
