tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "b1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh b1.dca2.plx"
		end tell
		
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "b2.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh b2.dca2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "b1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh b1.sjc2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "b2.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh b2.sjc2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "b1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh b1.fra2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "b2.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh b2.fra2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "b1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh b1.lon2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "b2.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh b2.lon2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "b1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh b1.hkg2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "b2.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh b2.hkg2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "b1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh b1.tyo2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "b2.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh b2.tyo2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "b1.syd2"
			«event ITRMExec» given «class Cmnd»:"ssh b1.syd2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "b2.syd2"
			«event ITRMExec» given «class Cmnd»:"ssh b2.syd2.plx"
		end tell
		
	end tell
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
