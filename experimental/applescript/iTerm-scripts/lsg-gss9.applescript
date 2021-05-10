tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "lsg-gss9"
			«event ITRMExec» given «class Cmnd»:"ssh -2A lsg-gss9.netmgmt.akamai.com"
		end tell
		
	end tell
	
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
