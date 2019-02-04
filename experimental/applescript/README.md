
Through some searching, trial, and error I found that the & operator with join multiple outputs with a comma and space ,:

osascript -e "output volume of (get volume settings) & output muted of (get volume settings)"
19, false


osascript -e "set volume with output muted"
This whole without instead of unmute seems a little odd though:

osascript -e "set volume without output muted"

And if you want to check the status of whether the audio is muted or not, you can get that too:

osascript -e "output muted of (get volume settings)"

You might know the trick about using the ⇧ + ⌥ + Volume Down keyboard shortcut to set the volume by quarter bars, but you can also use AppleScript to set it to 100ths.

osascript -e "set volume output volume 51 --100%"

So here's the deal, normally when you set the volume to 0 the speakers are automatically muted. On the keyboard you can hit the mute button while the volume is at 0 and it will unmute to the secret lowest volume setting.

Likewise, you can instruct AppleScript to not automatically mute the volume:

osascript -e "set volume without output muted output volume 1 --100%"

Sometimes you want the volume to stay muted, but to come on at a particular level when you unmute.

This is how you prevent the audio from unmuting when you adjust the volume level:

osascript -e "set volume with output muted output volume 42 --100%"

You can even get the current value and add to it all in one go.

osascript -e "set volume output volume (output volume of (get volume settings) + 1) --100%"

Now let's say you want to slowly fade out the volume over a second (or however long).

You can create a .applescript file that looks something like this, with a fractional delay, except a heck of a lot longer:

set volume without output muted output volume 18 --100%
delay 0.033
set volume without output muted output volume 17 --100%
delay 0.033
set volume without output muted output volume 16 --100%

