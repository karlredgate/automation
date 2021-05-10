tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		
		set SI1a to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1a
			set name to "Asia Pacific (Tokyo)"
			«event ITRMExec» given «class Cmnd»:"ssh -o PasswordAuthentication=yes -2 soc-user@lvm-ap-northeast-1.scoe-sil.net"
		end tell
		
		set SI1b to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1b
			set name to "Asia Pacific (Singapore)"
			«event ITRMExec» given «class Cmnd»:"ssh -o PasswordAuthentication=yes -2 soc-user@lvm-ap-southeast-1.scoe-sil.net"
		end tell
		
		set SI1c to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1c
			set name to "Asia Pacific (Sydney)"
			«event ITRMExec» given «class Cmnd»:"ssh -o PasswordAuthentication=yes -2 soc-user@lvm-ap-southeast-2.scoe-sil.net"
		end tell
		
		set SI1d to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1d
			set name to "EU (Frankfurt)"
			«event ITRMExec» given «class Cmnd»:"ssh -o PasswordAuthentication=yes -2 soc-user@lvm-eu-central-1.scoe-sil.net"
		end tell
		
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "EU (Ireland)"
			«event ITRMExec» given «class Cmnd»:"ssh -o PasswordAuthentication=yes -2 soc-user@lvm-eu-west-1.scoe-sil.net"
		end tell
		
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "US East (N. Virginia)"
			«event ITRMExec» given «class Cmnd»:"ssh -o PasswordAuthentication=yes -2 soc-user@lvm-us-east-1.scoe-sil.net"
		end tell
		
		set SI1e to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1e
			set name to "US West (Oregon)"
			«event ITRMExec» given «class Cmnd»:"ssh -o PasswordAuthentication=yes -2 soc-user@lvm-us-west-2.scoe-sil.net"
		end tell
		
		«event ITRMSlct» the first «class Pssn» of SI1terminal
		
	end tell
end tell
