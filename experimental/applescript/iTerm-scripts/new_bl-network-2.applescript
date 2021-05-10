tell application "iTerm 2"
	activate
	
	set myterm to (make new «class Ptrm»)
	tell myterm
		«event ITRMLNCH» given «class Pssn»:"Panes"
		set columns to 100
		set rows to 30
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "-" using command down
		
		tell the 1st «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.dca2.plx"
		tell the 1st «class Pssn» to «event ITRMWrte» given «class iTxt»:"echo | nc 0 7070"
		delay 1
		tell the 2nd «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.sjc2.plx"
		tell the 2nd «class Pssn» to «event ITRMWrte» given «class iTxt»:"echo | nc 0 7070"
		delay 1
		tell the 3rd «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.lon2.plx"
		tell the 3rd «class Pssn» to «event ITRMWrte» given «class iTxt»:"echo | nc 0 7070"
		delay 1
		tell the 4th «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.fra2.plx"
		tell the 4th «class Pssn» to «event ITRMWrte» given «class iTxt»:"echo | nc 0 7070"
		delay 1
		tell the 5th «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.hkg2.plx"
		tell the 5th «class Pssn» to «event ITRMWrte» given «class iTxt»:"echo | nc 0 7070"
		delay 1
		tell the 6th «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.tyo2.plx"
		tell the 6th «class Pssn» to «event ITRMWrte» given «class iTxt»:"echo | nc 0 7070"
	end tell
	
end tell
