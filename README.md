BlueCats SDK for iOS
================

The BlueCats' SDKs have been developed for easy integration and to offer flexiblity across different use cases.  Please let us know if you have any questions at developers@bluecats.com.

**See the [BlueCats Developer Portal](https://developer.bluecats.com) for SDK documentaiton and getting started guides.**

Need some beacons?  Check out the [store](http://store.bluecats.com/collections/featured-products/products/bluecats-starterpack-with-usb) for a StarterPack or email our [sales team](mailto:sales@bluecats.com).


## Installation - Swift Package Manager

Swift Package Manager is a new dependency manager recommended by Apple. Adding swift packages to your app is easy and straighforward, checkout [this artical](https://developer.apple.com/documentation/swift_packages/adding_package_dependencies_to_your_app)

Adding BlueCatsSDK in your Swift project is just a few steps:
* Open your app project with XCode (ver > 13)
* Click 'File->Add Packages' to open the package manager dialog, paste 'https://github.com/bluecats/bluecats-ios-sdk' in the search box at the top-right corner, pick the latest SDK version (>=2.2.0) or the latest commit on master branch, click 'Add'
* SPM will download the BlueCatsSDK for you
* Add 'import BlueCatsSDK' in any swift files where the SDK is invoked.


## Installation - Cocoapods
 
CocoaPods is an Objective-C library dependency manager. You can learn more about CocoaPods from [http://cocoapods.org](http://cocoapods.org/).

Add a BlueCatsSDK dependency to your Podfile in your Xcode project directory:

```ruby
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


## Have a Question?
* If you've found a bug, [open an issue](https://github.com/bluecats/bluecats-ios-sdk/issues).
* If you have a general question, please see our [developer portal](https://developer.bluecats.com) and [support center](support.bluecats.com) for articles on our platform and beacons.
* If you want a particular feature, [open an issue](https://github.com/bluecats/bluecats-ios-sdk/issues).
* If taking a look at our SDK for the first time, please see our [iOS SDK documentation](https://developer.bluecats.com).
