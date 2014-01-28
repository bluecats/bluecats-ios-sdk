BlueCats SDK for iOS7
================

Need some beacons? Request a starter pack from [www.bluecats.com](http://www.bluecats.com/starterpack). Will ship you 3 beacons in a neat box along with a code that will give you access to our platform.



## Getting Started
 
We recommend installing BlueCats with CocoaPods. CocoaPods is an Objective-C library dependency manager. You can learn more about CocoaPods from [http://cocoapods.org](http://cocoapods.org/).

Add a BlueCatsSDK dependency to your Podfile in your Xcode project directory:

```ruby
platform :ios, 7.0
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

## What the ...?

####BCSite

A BCSite object represents a group of beacons. A site is any place or building that has a physical address or coordinate. In some buildings such as malls there can be sites within a site. With our managment app you can control which apps access your sites and its beacons. Our BCSite gives context to Apple's CLBeaconRegion.    

####BCBeacon

A BCBeacon object represents a beacon device. Beacon devices are uniquely identified by their composite key (ProximityUUID:Major:Minor). Characterisitics such as beacon loudness and target speed can be changed to customize behaviours for your use case. In addition, you can use our management apps to assign categories such as text, hashtags, or urls to a beacon. The SDK eagerly syncs and caches beacons from nearby sites for your app. Our BCBeacon gives context to Apple's CLBeacon.  

####BCMicroLocation

A BCMicroLocation object represents the sites and beacons in proximity to the user. When your app needs some context it can query a micro-location for a sites beacons and categories by proximity. Its all the beacon goodness wrapped up into a tiny object. And integrating micro-locations with your app is simple. Either observe micro-location did update notification or become a delegate of our BCMicroLocationManager and implement the equivalent method.

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


### Get Some Context for Your Next App Action
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
