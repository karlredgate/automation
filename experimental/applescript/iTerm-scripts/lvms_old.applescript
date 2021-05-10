tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "lvm-virginia"
			«event ITRMExec» given «class Cmnd»:"ssh lvm-virginia.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "lvm-california"
			«event ITRMExec» given «class Cmnd»:"ssh lvm-california.plx"
		end tell
		
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "lvm-oregon"
			«event ITRMExec» given «class Cmnd»:"ssh lvm-oregon.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "lvm-ireland"
			«event ITRMExec» given «class Cmnd»:"ssh lvm-ireland.plx"
		end tell
		
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "lvm-singapore"
			«event ITRMExec» given «class Cmnd»:"ssh lvm-singapore.plx"
		end tell
		
		set SI1f to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1f
			set name to "lvm-tokyo"
			«event ITRMExec» given «class Cmnd»:"ssh lvm-tokyo.plx"
		end tell
		
		set SI1g to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1g
			set name to "lvm-saopaulo"
			«event ITRMExec» given «class Cmnd»:"ssh lvm-saopaulo.plx"
		end tell
		
		«event ITRMSlct» the first «class Pssn» of SI1terminal
		
	end tell
end tell
