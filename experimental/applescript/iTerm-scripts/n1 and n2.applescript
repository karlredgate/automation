tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "n1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh n1.dca2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "n2.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh n2.dca2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "n1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh n1.sjc2.plx"
		end tell
		
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "n2.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh n2.sjc2.plx"
		end tell
		
		set SI1g to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1g
			set name to "n1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh n1.lon2.plx"
		end tell
		
		set SI1h to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1h
			set name to "n2.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh n2.lon2.plx"
		end tell
		
		set SI1g to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1g
			set name to "n1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh n1.fra2.plx"
		end tell
		
		set SI1h to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1h
			set name to "n2.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh n2.fra2.plx"
		end tell
		
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "n1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh n1.hkg2.plx"
		end tell
		
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "n2.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh n2.hkg2.plx"
		end tell
		
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "n1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh n1.tyo2.plx"
		end tell
		
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "n2.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh n2.tyo2.plx"
		end tell
	end tell
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
