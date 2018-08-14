 2524  2018-08-14-14:49:34 /usr/libexec/PlistBuddy 
 2525  2018-08-14-14:49:55 $ /usr/libexec/PlistBuddy -c "Print CFBundleIdentifier:" /Library/Developer/Toolchains/swift-4.0-RELEASE.xctoolchain/Info.plist
 2526  2018-08-14-14:50:00 /usr/libexec/PlistBuddy -c "Print CFBundleIdentifier:" /Library/Developer/Toolchains/swift-4.0-RELEASE.xctoolchain/Info.plist
 2527  2018-08-14-14:50:25 ls /Library/Developer/
 2528  2018-08-14-14:50:39 find /Library/Developer/CommandLineTools/ | grep -i swift
 2529  2018-08-14-14:51:14 find /Library/Developer/CommandLineTools/ | grep -i swift | less
 2530  2018-08-14-14:51:50 man swift
 2532  2018-08-14-14:52:01 swift -v
 2533  2018-08-14-14:53:16 mkdir Hello
 2534  2018-08-14-14:53:18 cd Hello/
 2535  2018-08-14-14:53:28 swift package init --type executable
 2537  2018-08-14-14:53:36 swift run Hello
 2545  2018-08-14-14:54:17 vi Sources/main.swift 
 2546  2018-08-14-14:54:24 swift run
 2547  2018-08-14-14:54:36 swift run Hello
 2549  2018-08-14-14:54:52 swift --help
 2550  2018-08-14-14:55:07 swift run
 2551  2018-08-14-14:55:14 swift run Hello
 2552  2018-08-14-14:55:17 swift run .
 2553  2018-08-14-14:55:22 swift run Package.swift 
 2554  2018-08-14-14:55:27 swift run Sources/main.swift 
 2557  2018-08-14-14:55:52 swift build
 2560  2018-08-14-14:56:17 ls .build/debug/Hello
 2561  2018-08-14-14:56:18 file .build/debug/Hello
 2562  2018-08-14-14:56:23 swift run Hello
 2563  2018-08-14-14:56:33 ./.build/debug/Hello
 2568  2018-08-14-14:57:29 vi Sources/Greeter.swift
 2569  2018-08-14-14:58:04 vi Sources/main.swift 
 2570  2018-08-14-14:59:21 swift build
 2571  2018-08-14-14:59:27 swift run Hello
 2572  2018-08-14-14:59:33 ./.build/debug/Hello
 2573  2018-08-14-14:59:37 ./.build/debug/Hello foo
 2580  2018-08-14-15:01:23 vi factorial.swift
 2581  2018-08-14-15:01:34 swiftc -g factorial.swift 
 2584  2018-08-14-15:01:45 ./factorial
 2585  2018-08-14-15:01:52 git add factorial.swift 
