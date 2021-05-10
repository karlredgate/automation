tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "lr1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.dca2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n1.dca2"
		end tell
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "lr1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.dca2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n2.dca2"
		end tell
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "lr1.dca2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.dca2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n3.dca2"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "lr1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.sjc2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n1.sjc2"
		end tell
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "lr1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.sjc2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n2.sjc2"
		end tell
		set SI1f to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1f
			set name to "lr1.sjc2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.sjc2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n3.sjc2"
		end tell
		
		set SI1g to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1g
			set name to "lr1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.lon2.plx "
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n1.lon2"
		end tell
		set SI1h to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1h
			set name to "lr1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.lon2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n2.lon2"
		end tell
		set SI1i to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1i
			set name to "lr1.lon2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.lon2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n3.lon2"
		end tell
		
		set SI1g to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1g
			set name to "lr1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.fra2.plx "
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n1.fra2"
		end tell
		set SI1h to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1h
			set name to "lr1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.fra2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n2.fra2"
		end tell
		set SI1i to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1i
			set name to "lr1.fra2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.fra2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n3.fra2"
		end tell
		
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "lr1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.hkg2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n1.hkg2"
		end tell
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "lr1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.hkg2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n2.hkg2"
		end tell
		set SI1l to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1l
			set name to "lr1.hkg2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.hkg2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n3.hkg2"
		end tell
		
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "lr1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.tyo2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n1.tyo2"
		end tell
		set SI1k to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1k
			set name to "lr1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.tyo2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n2.tyo2"
		end tell
		set SI1l to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1l
			set name to "lr1.tyo2"
			«event ITRMExec» given «class Cmnd»:"ssh lr1.tyo2.plx"
			«event ITRMWrte» given «class iTxt»:"/usr/local/scripts/nstop.pl n3.tyo2"
		end tell
		
	end tell
	
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
