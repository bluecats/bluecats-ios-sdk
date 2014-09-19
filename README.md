BlueCats SDK for iOS
================

#### The BlueCats' iOS SDK has been developed for quick deployment so you can begin receiving accurate and real time proximity verification with the least amount of development!

Need some beacons? Request a StarterPack from [www.bluecats.com](http://www.bluecats.com/starterpack) or email our [sales team](mailto:sales@bluecats.com).

We've recently added a [wiki](https://github.com/bluecats/bluecats-ios-sdk/wiki) with information regarding [initializing](https://github.com/bluecats/bluecats-ios-sdk/wiki/Start-Purring) the SDK and other details.

## Installation
 
We recommend installing BlueCats with CocoaPods. CocoaPods is an Objective-C library dependency manager. You can learn more about CocoaPods from [http://cocoapods.org](http://cocoapods.org/).

Add a BlueCatsSDK dependency to your Podfile in your Xcode project directory:

```ruby
platform :ios, 8.0
pod 'BlueCatsSDK', :git => 'https://github.com/bluecats/bluecats-ios-sdk.git'
```

Now you can install the BlueCatsSDK dependency in your project:

```
$ pod install
```
If you need to update the installed BlueCatsSDK dependency in your project:

```
$ pod update
```

## Requirements

iOS 7.0 and up

## New in this Version 

### Info.plist

iOS8 now requires a description for the reason for accessing the user's location information.  Please see [NSLocationAlwaysUsageDescription](https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW18) and  [NSLocationWhenInUseUsageDescription](https://developer.apple.com/library/ios/documentation/General/Reference/InfoPlistKeyReference/Articles/CocoaKeys.html#//apple_ref/doc/uid/TP40009251-SW26).

### New Option

BCOptionUseLocalStorage: Enables ranging of previously cached beacons from database when network is not available.
