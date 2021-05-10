
tell application "Microsoft Outlook"

    set theContent to ""
    set theMessages to messages of folder "Inbox" of default account
    repeat with theMessage in theMessages
        if subject of theMessage contains "match this string" then
            set theContent to theContent & plain text content of theMessage
        end if
    end repeat

    set theMessage to make new outgoing message with properties {subject:"the subject line", plain text content:theContent}
    make new recipient with properties {email address:{address:"recipient@somewhere.com", name:"Lumpkin Skinbark"}} at end of to recipients of theMessage
    open theMessage -- for further editing

end tell
