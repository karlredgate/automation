tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "lbackup1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh lbackup1.dca2.plx"
		end tell
		set SI1f to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1f
			set name to "lbackup1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh lbackup1.sjc2.plx"
		end tell
		set SI1f to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1f
			set name to "lbackup1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh lbackup1.fra2.plx"
		end tell
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "lbackup1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh lbackup1.lon2.plx"
		end tell
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "lbackup1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh lbackup1.hkg2.plx"
		end tell
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "lbackup1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh lbackup1.tyo2.plx"
		end tell
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "lbackup1.syd2"
			«event ITRMExec» given «class Cmnd»:"ssh lbackup1.syd2.plx"
		end tell
		set columns to 200
		set rows to 40
	end tell
	
	«event ITRMSlct» the 1st «class Pssn» of SI1terminal
	tell application "System Events" to keystroke "-" using command down
	tell application "System Events" to keystroke "]" using {command down, shift down}
	tell application "System Events" to keystroke "-" using command down
	tell application "System Events" to keystroke "]" using {command down, shift down}
	tell application "System Events" to keystroke "-" using command down
	tell application "System Events" to keystroke "]" using {command down, shift down}
	tell application "System Events" to keystroke "-" using command down
	tell application "System Events" to keystroke "]" using {command down, shift down}
	tell application "System Events" to keystroke "-" using command down
	tell application "System Events" to keystroke "]" using {command down, shift down}
	tell application "System Events" to keystroke "-" using command down
	tell application "System Events" to keystroke "]" using {command down, shift down}
	tell application "System Events" to keystroke "-" using command down
end tell
