tell application "iTerm 2"
	activate
	
	set SI1terminal to (make new «class Ptrm»)
	
	tell SI1terminal
		set SI0 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI0
			set name to "Bot0"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-asia-1.scoe-sil.net"
		end tell
		
		
		set SI1 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI1
			set name to "Bot1"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-asia-2.scoe-sil.net"
		end tell
		
		
		set SI2 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI2
			set name to "Bot2"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-asia-3.scoe-sil.net"
		end tell
		
		
		set SI3 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI3
			set name to "Bot3"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-asia-4.scoe-sil.net"
		end tell
		
		
		set SI4 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI4
			set name to "Bot4"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-asia-5.scoe-sil.net"
		end tell
		
		
		set SI5 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI5
			set name to "Bot5"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-east-1.scoe-sil.net"
		end tell
		
		
		set SI6 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI6
			set name to "Bot6"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-east-2.scoe-sil.net"
		end tell
		
		
		set SI7 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI7
			set name to "Bot7"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-east-3.scoe-sil.net"
		end tell
		
		
		set SI8 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI8
			set name to "Bot8"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-east-4.scoe-sil.net"
		end tell
		
		
		set SI9 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI9
			set name to "Bot9"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-east-5.scoe-sil.net"
		end tell
		
		
		set SI10 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI10
			set name to "Bot10"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-emea-1.scoe-sil.net"
		end tell
		
		
		set SI11 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI11
			set name to "Bot11"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-emea-2.scoe-sil.net"
		end tell
		
		
		set SI12 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI12
			set name to "Bot12"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-emea-3.scoe-sil.net"
		end tell
		
		
		set SI13 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI13
			set name to "Bot13"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-emea-4.scoe-sil.net"
		end tell
		
		
		set SI14 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI14
			set name to "Bot14"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-emea-5.scoe-sil.net"
		end tell
		
		
		set SI15 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI15
			set name to "Bot15"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-west-1.scoe-sil.net"
		end tell
		
		
		set SI16 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI16
			set name to "Bot16"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-west-2.scoe-sil.net"
		end tell
		
		
		set SI17 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI17
			set name to "Bot17"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-west-3.scoe-sil.net"
		end tell
		
		
		set SI18 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI18
			set name to "Bot18"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-west-4.scoe-sil.net"
		end tell
		
		
		set SI19 to (make new «class Pssn» at the end of every «class Pssn»)
		tell SI19
			set name to "Bot19"
			«event ITRMExec» given «class Cmnd»:"ssh soc-attacker-west-5.scoe-sil.net"
		end tell
		
		«event ITRMSlct» the first «class Pssn» of SI1terminal
		
	end tell
end tell
