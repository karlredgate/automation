
set theFile to (POSIX file "/Users/Shared/test.eml")
open for access theFile
set fileContents to (read theFile)
close access theFile

tell application "/Applications/Microsoft Outlook.app"
    set SelectedMessages to current messages
    repeat with theMsg in SelectedMessages
        set msgID to id of theMsg
        set theAccount to account of the message id msgID
        set theSender to sender of the message id msgID
        set theDt to time received of the message id msgID
        set theMsg to make new incoming message at (deleted items of theAccount) with properties {sender:theSender, source:fileContents, account:theAccount}
        set replyWindow to reply to theMsg
        permanently delete theMsg
        exit repeat
    end repeat
end tell
