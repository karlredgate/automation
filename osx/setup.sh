#!/bin/bash
#
# Settings for OSX to fix broken behavior :-)
#

# Turn off spotlight - you don't use it anyway.
launchctl unload -w /System/Library/LaunchDaemons/com.apple.metadata.mds.plist
