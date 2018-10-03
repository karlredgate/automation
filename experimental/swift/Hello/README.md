
```
/usr/libexec/PlistBuddy 
$ /usr/libexec/PlistBuddy -c "Print CFBundleIdentifier:" /Library/Developer/Toolchains/swift-4.0-RELEASE.xctoolchain/Info.plist
/usr/libexec/PlistBuddy -c "Print CFBundleIdentifier:" /Library/Developer/Toolchains/swift-4.0-RELEASE.xctoolchain/Info.plist
ls /Library/Developer/
find /Library/Developer/CommandLineTools/ | grep -i swift
find /Library/Developer/CommandLineTools/ | grep -i swift | less
man swift
swift -v
mkdir Hello
cd Hello/
swift package init --type executable
swift run Hello
vi Sources/main.swift 
swift run
swift run Hello
swift --help
swift run
swift run Hello
swift run .
swift run Package.swift 
swift run Sources/main.swift 
swift build
ls .build/debug/Hello
file .build/debug/Hello
swift run Hello
./.build/debug/Hello
vi Sources/Greeter.swift
vi Sources/main.swift 
swift build
swift run Hello
./.build/debug/Hello
./.build/debug/Hello foo
vi factorial.swift
swiftc -g factorial.swift 
./factorial
git add factorial.swift 
```

```
$ swiftc -g cocoa.swift
<unknown>:0: error: cannot load underlying module for 'CoreGraphics'
<unknown>:0: note: did you forget to set an SDK using -sdk or SDKROOT?
<unknown>:0: note: use "xcrun swiftc" to select the default macOS SDK installed with Xcode
$
```

```
$ xcodebuild -sdk -version
SDKROOT=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk swiftc -g cocoa.swift
```

<!-- vim: set autoindent expandtab sw=4 syntax=markdown: -->
