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
+ (BOOL)isSiteMonitoringAvailable;
+ (BOOL)isBeaconRangingAvailable;
+ (BOOL)isMicroLocationUpdatingAvailable;
+ (NSString *)stringForSiteState:(BCSiteState)state;

+ (BCMicroLocationManager *)sharedManager;
+ (void)setSharedManager:(BCMicroLocationManager *)sharedManager;

@end


@protocol BCMicroLocationManagerDelegate <NSObject>

@optional

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
            didFailWithError:(NSError *)error;


- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
        didUpdateNearbySites:(NSArray *)sites;



- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
   didStartMonitoringForSite:(BCSite *)site;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
    monitoringDidFailForSite:(BCSite *)site
                   withError:(NSError *)error;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
           didDetermineState:(BCSiteState)state
                     forSite:(BCSite *)site;



- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
                didEnterSite:(BCSite *)site;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
                 didExitSite:(BCSite *)site;



- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
rangingBeaconsDidFailForSite:(BCSite *)site
                   withError:(NSError *)error;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
             didRangeBeacons:(NSArray *)beacons
                      inSite:(BCSite *)site;



- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger
     didUpdateMicroLocations:(NSArray *)microLocations;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didUpdateMicroLocationServicesAvailibility:(BOOL)available;

@end

extern NSString * const BCMicroLocationManagerDidEnterSite;
extern NSString * const BCMicroLocationManagerDidExitSite;
extern NSString * const BCMicroLocationManagerDidUpdateMicroLocation;
extern NSString * const BCMicroLocationManagerDidUpdateNearbySites;
extern NSString * const BCMicroLocationManagerDidUpdateMicroLocationServicesAvailibility;

extern NSString * const BCMicroLocationManagerNotificationSiteItem;
extern NSString * const BCMicroLocationManagerNotificationNewLocationItem;
