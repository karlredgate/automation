tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	tell SI1terminal
		set SI1g to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1g
			set name to "lmon1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh lmon1.dca2.plx"
		end tell
		set SI1i to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1i
			set name to "lmon1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh lmon1.sjc2.plx"
		end tell
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "lmon1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh lmon1.lon2.plx"
		end tell
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "lmon1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh lmon1.fra2.plx"
		end tell
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "lmon1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh lmon1.hkg2.plx"
		end tell
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "lmon1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh lmon1.tyo2.plx"
		end tell
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "lmon1.syd2"
			«event ITRMExec» given «class Cmnd»:"ssh lmon1.syd2.plx"
		end tell
	end tell
	
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
