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
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		tell application "System Events" to keystroke "d" using command down
		tell application "System Events" to keystroke "-" using command down
		
		delay 1
		tell the 1st «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.dca2.plx"
		delay 1
		tell the 2nd «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.sjc2.plx"
		delay 1
		tell the 3rd «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.lon2.plx"
		delay 1
		tell the 4th «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.fra2.plx"
		delay 1
		tell the 5th «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.hkg2.plx"
		delay 1
		tell the 6th «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.tyo2.plx"
		delay 1
		tell the 7th «class Pssn» to «event ITRMWrte» given «class iTxt»:"ssh lmon1.syd2.plx"
		
	end tell
	
	
end tell
