tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "MIA-LR1"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.mia2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "DCA-LR1"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.dca2.plx"
		end tell
		
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "SJC-LR1"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.sjc2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "LON-LR1"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.lon2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "FRA-LR1"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.fra2.plx"
		end tell
		
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "HKG-LR1"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.hkg2.plx"
		end tell
		
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "TYO-LR1"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.tyo2.plx"
		end tell
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "SYD-LR1"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.syd2.plx"
		end tell
	end tell
	
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
