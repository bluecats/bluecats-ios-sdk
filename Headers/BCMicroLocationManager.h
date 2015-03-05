//
//  BCMicroLocationManager.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 4/8/13.
//
//

#import <CoreLocation/CoreLocation.h>
#import "BCSite.h"

@protocol BCMicroLocationManagerDelegate;

@class BCMicroLocation;

@interface BCMicroLocationManager : NSObject

@property (nonatomic, assign) NSObject<BCMicroLocationManagerDelegate> *delegate;

@property (readonly, nonatomic) NSOrderedSet *nearbySites;
@property (nonatomic, assign) double distanceFilter;

@property (readonly, nonatomic) NSSet *monitoredSites;
@property (readonly, nonatomic) NSSet *rangedSites;

@property (nonatomic, assign) BOOL updateMicroLocationOnlyOnProximityChanges;

@property (nonatomic, copy, readonly) BCMicroLocation *microLocation;

- (void)startUpdatingMicroLocation;
- (void)stopUpdatingMicroLocation;


- (void)startMonitoringSite:(BCSite *)site;
- (void)stopMonitoringSite:(BCSite *)site;
- (void)requestStateForSite:(BCSite *)site;
- (void)stopMonitoringAllSites;
- (BOOL)isMonitoringSite:(BCSite *)site;

- (void)startRangingBeaconsInSite:(BCSite *)site;
- (void)stopRangingBeaconsInSite:(BCSite *)site;


// Class methods
+ (BOOL)locationServicesEnabled;
+ (CLAuthorizationStatus)authorizationStatus;
+ (BOOL)isAuthorized;
+ (BOOL)isSiteMonitoringAvailable;
+ (BOOL)isBeaconRangingAvailable;
+ (BOOL)isMicroLocationUpdatingAvailable;

+ (BCMicroLocationManager *)sharedManager;
+ (void)setSharedManager:(BCMicroLocationManager *)sharedManager;

@end


@protocol BCMicroLocationManagerDelegate <NSObject>

@optional

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
            didFailWithError:(NSError *)error;


- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
        didUpdateNearbySites:(NSArray *)sites;



- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
   didStartMonitoringForSite:(BCSite *)site;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
    monitoringDidFailForSite:(BCSite *)site
                   withError:(NSError *)error;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
           didDetermineState:(BCSiteState)state
                     forSite:(BCSite *)site;



- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
                didEnterSite:(BCSite *)site;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
                 didExitSite:(BCSite *)site;



- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
rangingBeaconsDidFailForSite:(BCSite *)site
                   withError:(NSError *)error;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
             didRangeBeacons:(NSArray *)beacons
                      inSite:(BCSite *)site;



- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
     didUpdateMicroLocations:(NSArray *)microLocations;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager didUpdateMicroLocationServicesAvailibility:(BOOL)available;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager didBeginVisitForBeaconsWithSerialNumbers:(NSArray *)serialNumbers;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager didEndVisitForBeaconsWithSerialNumbers:(NSArray *)serialNumbers;

@end

extern NSString * const BCMicroLocationManagerDidEnterSite;
extern NSString * const BCMicroLocationManagerDidExitSite;
extern NSString * const BCMicroLocationManagerDidUpdateNearbySites;
extern NSString * const BCMicroLocationManagerDidUpdateMicroLocationServicesAvailibility;

extern NSString * const BCMicroLocationManagerNotificationSiteItem;
extern NSString * const BCMicroLocationManagerNotificationNewLocationItem;
