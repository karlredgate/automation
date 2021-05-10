tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI1i to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1i
			set name to "route-views.routeviews.org"
			«event ITRMExec» given «class Cmnd»:"telnet route-views.routeviews.org"
		end tell
		set SI1j to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1j
			set name to "route-views3.routeviews.org"
			«event ITRMExec» given «class Cmnd»:"telnet route-views3.routeviews.org"
		end tell
	end tell
	
	
	«event ITRMSlct» the first «class Pssn» of SI1terminal
	
end tell
