# https://apple.stackexchange.com/questions/290639/invoke-applescript-from-outlook

Many commands have parameters that specify locations.
A location can be either an insertion point or another object.
An insertion point is a location where an object can be added.

direct param
object specifiers
target

tell Application "iTerm 2"
    third document of application "TextEdit"
    paragrpah 1 of text of document 1
    paragrpah 1 of document 1
    folder "Applications" of startup disk
    first item of first folder of first disk
    first window's name
    version of application "Finder"
    name of item 1 of disk 2
    set docRef to a reference to the first document
    name of docRef
    set docRef to a reference to document "Report.rtf"
    set myWindow to a ref to window "Q1.rtf" of application "TextEdit"
    contents of myWindow
    get myWindow
    set myText to 1 as text
    # cmd - direct param == target(obj)
    get     name of first window
    duplicate last file of window 1 of application "Finder"
    get current application --result: current application
    name of current application --result: "Script Editor"
    
end tell

A scripting addition is a file or bundle that provides handlers you can use in scripts to perform commands and coercions.
Many of the commands described in this guide are defined in the Standard Additions scripting addition in Mac OS X. These commands are stored in the file StandardAdditions.osax in /System/Library/ScriptingAdditions, and are available to any script. You can examine the terminology for the Standard Additions by opening this file in Script Editor.

path to scripting additions as text
    --result: "Hard_Disk:System:Library:ScriptingAdditions:"

Scripting additions can be embedded within bundled script applets by placing them in a folder named ScriptingAdditions(notethespacebetween“Scripting”and“Additions”)insidethebundle’ s Contents/Resources/ folder. Note that Script Editor does not look for embedded scripting additions when editing bundled applets. During script development, any required scripting additions must be properly installed in /System/ScriptingAdditions, /Library/ScriptingAdditions, or ~/Library/ScriptingAdditions so that Script Editor can find them.

Developers can create their own scripting additions, as described in Technical Note TN1164, Scripting Additions for Mac OS X . For related conceptual information, see AppleScript Overview , particularly the section “Extending AppleScript with Coercions, Scripting Additions, and Faceless Background Applications” in the chapter Open Scripting Architecture.


A tell statement specifies a default target for all commands contained within it, so the direct parameter is optional.

tell last file of window 1 of application "Finder"
    duplicate
end tell
tell front document of application "TextEdit"
    duplicate paragraph 1 to before paragraph 4
end tell


AppleScript provides the text item delimiters property for use in processing text. This property consists of a list of strings used as delimiters by AppleScript when it coerces a list to text or gets text items from text strings. AppleScript currently uses only the first delimiter in the list.
Because text item delimiters respect considering and ignoring attributes in AppleScript 2.0, delimiters are case-insensitive by default. Formerly, they were always case-sensitive. To enforce the previous behavior, add an explicit considering case statement.

set AppleScript's text item delimiters to {", "}
{"bread", "milk", "butter", 10.45}  as string    -- "bread, milk, butter, 10.45"


The text item delimiters property can be used to extract individual names from a pathname. For example, the script
set AppleScript's text item delimiters to {":"}
get last text item of "Hard Disk:CD Contents:Release Notes"


set savedDelimiters to AppleScript's text item delimiters
try
    set AppleScript's text item delimiters to {"**"}
    --other script statements...
    --now reset the text item delimiters:
    set AppleScript's text item delimiters to savedDelimiters
on error m number n
# on error errMsg number errVal from objRef partial result {res list} to string
    if (n is equal to -128) then
        display dialog "cancelled"
    end if
    --also reset text item delimiters in case of an error:
    set AppleScript's text item delimiters to savedDelimiters
    --and resignal the error:
    error m number n
on error number -128
    display dialog "canceled"
end try

try
    repeat with i from 1 to "DEADBEEF"
    end repeat
or error from objRef to newClass
-- objRef is "DEADBEEF" ; newClass is "integer"
    log {objRef, newClass}
end try


The following script shows how to check for a version greater than or equal to version 1.9. The if statement is wrapped in a considering numeric strings statement so that an AppleScript version such as 1.10.6 compares as larger than, say, version 1.9.


considering numeric strings
    if version of AppleScript as string ≥ "1.9" then
        -- Perform operations that depend on version 1.9 or greater
    else
        -- Handle case where version is not high enough
    end if
end considering

tell application "Finder"
    version --result: "10.5.1"
    version of AppleScript --result: "2.0"
end tell


set myVariable to missing value
    -- perform operations that might change the value of myVariable
if myVariable is equal to missing value then
    -- the value of the variable never changed
else
    -- the value of the variable did change
end if


AppleScript defines the keyword me to refer to the current script and the keyword it to refer to the current target. (The current script is the one that is currently being executed; the current target is the object that is the current default target for commands.) It also defines my as a synonym for of me and its as a synonym for of it.
If a script hasn’t targeted anything, it and me refer to the same thing—the script—as shown in the following example:


-- At the top-level of the script:
me --result: «script» (the top-level script object)
it --result: «script» (same as it, since no target set yet)

A tell statement specifies a default target. In the following example, the default target is the Finder application:

-- Within a tell block:
tell application "Finder" -- sets target
    me --result: «script» (still the top-level script object)
    it --result: application "Finder" (target of the tell statement)
end tell

You can use the words of me or my to indicate that the target of a command is the current script and not the target of the tell statement. In the following example, the word my indicates that minimumValue() handler is defined by the script, not by Finder:

tell application "Finder"
    set fileCount to count files in front window
    set myCount to my minimumValue(fileCount, 100)
    --do something with up to the first 100 files...
end tell


You can also use of me or my to distinguish script properties from object properties. Suppose there is a TextEdit document open named “Simple.rtf”:

tell document 1 of application "TextEdit"
    name --result: "Simple.rtf" (implicitly uses target of tell)
    name of it --result: "Simple.rtf" (specifies target of tell)
    me --result: «script» (top-level script object, not target of tell)
end tell

tell application "Finder"
    version --result: "10.5.1" (Finder version is the default in tell block)
    its version --result: "10.5.1" (specifically asks for Finder version)
    version of me --result: "2.0" (AppleScript version)
    my version --result: "2.0" (AppleScript version)
    version of AppleScript --result: "2.0" (AppleScript version)
end tell



using terms from "Application"
end

using terms from application "Mail"
  on perform mail action with messages theMessages for rule theRule
    tell application "Mail"
        -- statements to process each message in theMessages
    end tell
  end perform mail action with messages
end using terms from



tell application "Microsoft Outlook"
    activate
    set thisMessage to selection
    set ptContent to plain text content of thisMessage
end tell



tell application "TextEdit"
    with timeout of 20 seconds
        close document 1 saving ask
    end timeout
end tell



