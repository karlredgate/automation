tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "n5.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh n5.dca2.plx"
		end tell
		set SI1f to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1f
			set name to "n5.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh n5.sjc2.plx"
		end tell
		set SI1i to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1i
			set name to "n5.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh n5.lon2.plx"
		end tell
		set SI1i to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1i
			set name to "n5.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh n5.fra2.plx"
		end tell
		set SI1l to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1l
			set name to "n5.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh n5.hkg2.plx"
		end tell
		set SI1l to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1l
			set name to "n5.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh n5.tyo2.plx"
		end tell
	end tell
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
