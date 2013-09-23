bluecats-ios-sdk
================

Request a BCAppToken from theteam@bluecats.com.

## Getting Started
 
We recommend installing BlueCats with CocoaPods. CocoaPods is an Objective-C library dependency manager. You can learn more about CocoaPods from [http://cocoapods.org](http://cocoapods.org/).

Add a BlueCatsSDK dependency to your Podfile in your Xcode project directory:

```ruby
platform :ios 6.0
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

## Examples

### Start Purring
``` objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [BlueCatsSDK setOptions:@{BCOptionUseStageApi: @"YES"}];
    [BlueCatsSDK startPurringWithAppToken:@"YourBCAppToken"];
    [[BCMicroLocationManager sharedManager] startUpdatingMicroLocation];
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

    LBOnlyViewController *onlyViewController = [[LBOnlyViewController alloc] init];
    self.window.rootViewController = onlyViewController;
    [self.window makeKeyAndVisible];
    return YES;
}
```

### Observe BCMicroLocationManager Notifications
``` objective-c
#import "BCMicroLocationManager.h"

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(microLocationManagerDidEnterSiteNotification:)
                                                 name:BCMicroLocationManagerDidEnterSite
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(microLocationManagerDidExitSiteNotification:)
                                                 name:BCMicroLocationManagerDidExitSite
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(microLocationManagerDidUpdateMicroLocationNotification:)
                                                 name:BCMicroLocationManagerDidUpdateMicroLocation
                                               object:nil];
}
```

### Implement BCMicroLocationManager Notifications 
``` objective-c
- (void)microLocationManagerDidEnterSiteNotification:(NSNotification *)notification
{
    BCSite *site = [notification.userInfo objectForKey:BCMicroLocationManagerNotificationSiteItem];
}

- (void)microLocationManagerDidExitSiteNotification:(NSNotification *)notification
{
    BCSite *site = [notification.userInfo objectForKey:BCMicroLocationManagerNotificationSiteItem];
}

- (void)microLocationManagerDidUpdateMicroLocationNotification:(NSNotification *)notification
{
    BCMicroLocation *microLocation = [notification.userInfo objectForKey:BCMicroLocationManagerNotificationNewLocationItem];
}
```
