tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "ms3.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh ms3.dca2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "ms3.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh ms3.sjc2.plx"
		end tell
		
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "ms3.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh ms3.lon2.plx"
		end tell
		
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "ms3.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh ms3.fra2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "ms3.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh ms3.hkg2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "ms3.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh ms3.tyo2.plx"
		end tell
	end tell
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
