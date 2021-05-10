tell application "iTerm 2"
	activate
	
	set myterm to (make new «class Ptrm»)
	tell myterm
		set columns to 250
		set rows to 60
		«event ITRMLNCH» given «class Pssn»:"Panes"
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		
		
	end tell
	
	
end tell
