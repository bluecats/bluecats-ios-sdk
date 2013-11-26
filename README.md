bluecats-ios-sdk
================

Request a BCAppToken from theteam@bluecats.com.

## Getting Started
 
We recommend installing BlueCats with CocoaPods. CocoaPods is an Objective-C library dependency manager. You can learn more about CocoaPods from [http://cocoapods.org](http://cocoapods.org/).

Add a BlueCatsSDK dependency to your Podfile in your Xcode project directory:

```ruby
platform :ios 7.0
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
    [BlueCatsSDK startPurringWithAppToken:@"YourBCAppToken"];
    [[BCMicroLocationManager sharedManager] startUpdatingMicroLocation]; 
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

    LBOnlyViewController *onlyViewController = [[LBOnlyViewController alloc] init];
    self.window.rootViewController = onlyViewController;
    [self.window makeKeyAndVisible];
    return YES;
}
```
If you don't like a shared micro-location manager, then init your very own BCMicroLocationManager. 

``` objective-c
- (BCMicroLocationManager *)microLocationManager
{
    if (!_microLocationManager) {
        _microLocationManager = [[BCMicroLocationManager alloc] init];
    }
    return _microLocationManager;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    self.microLocationManager.delegate = self;
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    _microLocationManager = nil;
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


### Implement BCMicroLocationManagerDelegate methods
``` objective-c
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didUpdateNearbySites:(NSArray *)sites
{
    [self refreshNearbySites];
}

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didEnterSite:(BCSite *)site
{
    [self determinedState:BCSiteStateInside forSite:site];
}

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didExitSite:(BCSite *)site
{
    [self determinedState:BCSiteStateOutside forSite:site];
}

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didDetermineState:(BCSiteState)state forSite:(BCSite *)site
{
    [self determinedState:state forSite:site];
}
```


### Get Categories and Beacons for Your Site by Proximity
``` objective-c
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didUpdateMicroLocations:(NSArray *)microLocations
{
    BCMicroLocation *microLocation = [microLocations lastObject];
    
    NSArray *categories = [microLocation categoriesForSite:self.site proximity:BCProximityNear];

    NSArray *beacons = [microLocation beaconsForSite:self.site proximity:BCProximityImmediate];
}
```

### Get Nearby Sites
``` objective-c
- (void)requestStateForNearbySites
{
    NSOrderedSet *nearbySites = self.microLocationManager.nearbySites;
    
    for (BCSite *site in nearbySites) {
        [self.microLocationManager requestStateForSite:site];
    }
}

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didDetermineState:(BCSiteState)state forSite:(BCSite *)site
{
    [self determinedState:state forSite:site];
}
```

### Schedule a Local Notification to Fire in a Site and categories
``` objective-c
- (IBAction)save:(id)sender
{
    [self.tableView endEditing:YES];
    
    BCLocalNotification* localNotification = [[BCLocalNotification alloc] init];
    localNotification.fireAfter = self.fireAfter;
    localNotification.alertBody = self.alertBody;
    localNotification.alertAction = self.alertAction;
    localNotification.fireInSite = self.site;
    localNotification.fireInCategories = self.fireInCategories;
    localNotification.fireInProximity = self.fireInProximity;
    
    [[BCLocalNotificationManager sharedManager] scheduleLocalNotification:localNotification];
    
    [self.delegate localNotificationViewControllerDelegate:self didSaveLocalNotification:localNotification];
}
```


 
### Monitor Sites and Range Beacons
``` objective-c
 
 self.microLocationManager startRangingBeaconsInSite:self.site];
 
 - (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didRangeBeacons:(NSArray *)beacons inSite:(BCSite *)site
{
    [self addAnnotationsForBeacons:beacons];
    
    [self updateAnnotationViewsWithBeacons:beacons];
}

 ```
