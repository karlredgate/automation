
tell application "System Events"
    activate
    set choice to choose from list {"a","b","c"} with title "My Choice" with multiple selections allowed
end
