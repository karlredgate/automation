// click on robot name to open page about robot
// update each cell - table of cells to update, or does the UI provide access to cells

package main

import (
    // "os"
    "fmt"
    "time"

    "github.com/gdamore/tcell/v2"
    "github.com/rivo/tview"
)

func newTextPrim( text string ) (tview.Primitive) {
    widget := tview.NewTextView()
    widget.SetTextAlign( tview.AlignCenter )
    widget.SetText( text )
    return widget
}

var names [32]*tview.TableCell

var content *tview.TextView

func update( app *tview.Application ) {
    i := 0
    for {
        time.Sleep( 1 * time.Second )
	i += 3
	name := fmt.Sprintf( "STUFFandnonsense.%d object tyupe etc\n", i )
	names[20].SetText(name)
	fmt.Fprintf( content, name )
    }
}

func main() {
    grid := tview.NewGrid()
    grid.SetRows( 1, 0, 10 ).SetColumns( 37, 0 ).SetBorders( true )

    content = tview.NewTextView()
    content.SetDynamicColors( true )

    tbl := tview.NewTable()
    tbl.SetFixed(1,1)

    tbl.SetCell( 0, 0, tview.NewTableCell("Robot") )
    tbl.SetCell( 0, 1, tview.NewTableCell("Address") )
    tbl.SetCell( 0, 2, tview.NewTableCell("State") )

    names[1] = tview.NewTableCell( "beta46" )
    names[1].SetTextColor( tcell.ColorGreen )
    tbl.SetCell( 1, 0, names[1] )

    cell_2 := tview.NewTableCell( "10.10.60.60" )
    tbl.SetCell( 1, 1, cell_2 )
    cell_3 := tview.NewTableCell( "WAITING" )
    tbl.SetCell( 1, 2, cell_3 )

    names[2] = tview.NewTableCell( "[green]corgi86" )
    tbl.SetCell( 2, 0, names[2] )

    cell_5 := tview.NewTableCell( "LIVE" )
    tbl.SetCell( 2, 2, cell_5 )

    names[20] = tview.NewTableCell( "beta99" )
    tbl.SetCell( 20, 0, names[20] )

    app := tview.NewApplication()
    content.SetChangedFunc( func () { app.Draw() } )

    handler := func (event *tcell.EventKey) (*tcell.EventKey) {
	switch event.Key() {
	case tcell.KeyCtrlL:
	    app.Sync()
	    return nil
	case tcell.KeyCtrlC:
	    app.Stop()
	    return nil
	case tcell.KeyRune:
	    switch event.Rune() {
	    case 'q': app.Stop(); return nil
	    // have tab shift focus
	    }
	}
	fmt.Println( "KEY", event.Key() )
	return event
    }
    app.SetInputCapture( handler )

    menu := tview.NewList()
    menu.AddItem( "01234567-0123-0123-0123-012345678900", "ObjectType", 0, nil )
    menu.AddItem( "12345670-0123-0123-0123-012345678900", "ObjectType", 0, nil )
    // menu.AddItem( "Quit", "Press to exit", 'q', func () {app.Stop()} )

    // row,col,rspan,cspan,minheight,minwidth,focus
    grid.AddItem( newTextPrim("Protostore Status"), 0, 0, 1, 2, 0, 0, false)
    grid.AddItem( menu,    1, 0, 1, 1, 0, 0, false)
    grid.AddItem( tbl,     1, 1, 1, 1, 0, 0, false)
    grid.AddItem( content, 2, 0, 1, 2, 0, 0, false)
    fmt.Fprint( content, "[green]green[white] more" )

    app.SetRoot( grid, true ).EnableMouse( true )
    go update( app )
    err := app.Run()
    if err != nil {
	panic(err)
    }
}
