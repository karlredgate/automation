tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "a1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh a1.dca2.plx"
		end tell
		
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "a2.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh a2.dca2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "a1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh a1.sjc2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "a2.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh a2.sjc2.plx"
		end tell
		
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "a1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh a1.fra2.plx"
		end tell
		
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "a2.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh a2.fra2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "a1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh a1.lon2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "a2.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh a2.lon2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "a1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh a1.hkg2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "a2.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh a2.hkg2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "a1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh a1.tyo2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "a2.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh a2.tyo2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "a1.syd2"
			«event ITRMExec» given «class Cmnd»:"ssh a1.syd2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "a2.syd2"
			«event ITRMExec» given «class Cmnd»:"ssh a2.syd2.plx"
		end tell
		
	end tell
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
