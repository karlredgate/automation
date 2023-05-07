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

var focus     int = 0
var widgets   [3]tview.Primitive

var names     [32]*tview.TableCell
var addresses [32]*tview.TableCell
var states    [32]*tview.TableCell

var content *tview.TextView

func update( app *tview.Application ) {
    i := 0
    for {
        time.Sleep( 1 * time.Second )
	i += 3
	name := fmt.Sprintf( "beta-%d", i )
	names[20].SetText(name)
	line := fmt.Sprintf( "STUFFandnonsense.%d object tyupe etc\n", i )
	fmt.Fprintf( content, line )
    }
}

func addShortcuts(app *tview.Application) (*tview.Application) {
    handler := func (event *tcell.EventKey) (*tcell.EventKey) {
	switch event.Key() {
	case tcell.KeyTab:
	    focus = (focus + 1) % 3
	    app.SetFocus( widgets[focus] )
	    app.Sync()
	    return nil
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
	// fmt.Println( "KEY", event.Key() )
	return event
    }
    app.SetInputCapture( handler )
    return app
}

func createLogWidget(app *tview.Application) (*tview.TextView, error) {
    widget := tview.NewTextView()
    widget.SetDynamicColors( true )
    widget.SetChangedFunc( func () { app.Draw() } )
    return widget,nil
}

func createCells(table *tview.Table, column int, list []*tview.TableCell) {
    for i := 0; i < 32; i++ {
	list[i] = tview.NewTableCell("")
        list[i].SetTextColor( tcell.ColorGreen )
        table.SetCell( i+1, column, list[i] )
    }
}

func createRobotTableWidget(app *tview.Application) (*tview.Table, error) {
    widget := tview.NewTable()
    widget.SetFixed(1,1)

    widget.SetCell( 0, 0, tview.NewTableCell("Idx") )
    widget.SetCell( 0, 1, tview.NewTableCell("Robot") )
    widget.SetCell( 0, 2, tview.NewTableCell("Address") )
    widget.SetCell( 0, 3, tview.NewTableCell("State") )

    for i := 0; i < 32; i++ {
	cell := tview.NewTableCell( string(i) )
        cell.SetTextColor( tcell.ColorGreen )
        widget.SetCell( i, 0, cell )
    }
    createCells( widget, 1, names[:] )
    createCells( widget, 2, addresses[:] )
    createCells( widget, 3, states[:] )

    return widget,nil
}

// menu.AddItem( "Quit", "Press to exit", 'q', func () {app.Stop()} )
func createObjListWidget(app *tview.Application) (*tview.List, error) {
    widget := tview.NewList()
    widget.AddItem( "01234567-0123-0123-0123-012345678900", "ObjectType", 0, nil )
    widget.AddItem( "12345670-0123-0123-0123-012345678900", "ObjectType", 0, nil )
    widget.AddItem( "23456701-0123-0123-0123-012345678900", "ObjectType", 0, nil )
    return widget,nil
}

func createApp() (*tview.Application,error) {
    var err error

    app := tview.NewApplication()
    grid := tview.NewGrid()
    grid.SetRows( 1, 0, 10 ).SetColumns( 37, 0 ).SetBorders( true )
    app.SetRoot( grid, true ).EnableMouse( true )

    content,err = createLogWidget( app )
    if err != nil { return nil,err }
    widgets[0] = content
    addShortcuts( app )
    tbl,err := createRobotTableWidget( app  )
    if err != nil { return nil,err }
    widgets[1] = tbl
    menu,err := createObjListWidget( app )
    if err != nil { return nil,err }
    widgets[2] = menu

    // row,col,rspan,cspan,minheight,minwidth,focus
    grid.AddItem( newTextPrim("Protostore Status"), 0, 0, 1, 2, 0, 0, false)
    grid.AddItem( menu,    1, 0, 1, 1, 0, 0, false)
    grid.AddItem( tbl,     1, 1, 1, 1, 0, 0, false)
    grid.AddItem( content, 2, 0, 1, 2, 0, 0, false)
    fmt.Fprint( content, "[green]green[white] more" )

    app.SetFocus( tbl )

    return app,nil
}

func main() {
    app,err := createApp()
    if err != nil { panic(err) }

    names[1].SetText( "beta46" )
    addresses[1].SetText( "10.10.60.60" )
    states[2].SetText( "WAITING" )
    names[2].SetText( "corgi86" )
    names[20].SetText( "beta99" )

    go update( app )
    err = app.Run()
    if err != nil { panic(err) }
}
