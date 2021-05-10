tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "ledns1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns1.dca2.plx"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "ledns2.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns2.dca2.plx"
		end tell
		
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "ledns3.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns3.dca2.plx"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "ledns1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns1.sjc2.plx"
		end tell
		
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "ledns2.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns2.sjc2.plx"
		end tell
		
		set SI1f to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1f
			set name to "ledns3.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns3.sjc2.plx"
		end tell
		
		set SI1g to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1g
			set name to "ledns1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns1.lon2.plx"
		end tell
		
		set SI1h to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1h
			set name to "ledns2.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns2.lon2.plx"
		end tell
		
		set SI1i to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1i
			set name to "ledns3.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns3.lon2.plx"
		end tell
		
		set SI1g to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1g
			set name to "ledns1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns1.fra2.plx"
		end tell
		
		set SI1h to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1h
			set name to "ledns2.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns2.fra2.plx"
		end tell
		
		set SI1i to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1i
			set name to "ledns3.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns3.fra2.plx"
		end tell
		
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "ledns1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns1.hkg2.plx"
		end tell
		
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "ledns2.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns2.hkg2.plx"
		end tell
		
		set SI1l to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1l
			set name to "ledns3.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns3.hkg2.plx"
		end tell
		
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "ledns1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns1.tyo2.plx"
		end tell
		
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "ledns2.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns2.tyo2.plx"
		end tell
		
		set SI1l to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1l
			set name to "ledns3.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh ledns3.tyo2.plx"
		end tell
		
	end tell
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
