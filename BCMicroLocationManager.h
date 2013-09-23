//
//  BCMicroLocationManager.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 4/8/13.
//
//

@protocol BCMicroLocationManagerDelegate;

@class BCMicroLocation, BCSite;

@interface BCMicroLocationManager : NSObject

@property (nonatomic, assign) NSObject<BCMicroLocationManagerDelegate> *delegate;
@property (nonatomic, assign) double nearbySitesDistanceFilter;
@property (nonatomic, assign, readonly, getter = isUpdatingMicroLocationEnabled) BOOL updatingMicroLocationEnabled;

+ (BCMicroLocationManager *)sharedManager;

+ (void)setSharedManager:(BCMicroLocationManager *)sharedManager;

- (void)startUpdatingMicroLocation;

- (void)stopUpdatingMicroLocation;

- (BCMicroLocation *)microLocation;

- (NSArray *)nearbySites;

- (BOOL)microLocationServicesAvailable;

@end


@protocol BCMicroLocationManagerDelegate <NSObject>

@optional

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didFailWithError:(NSError *)error;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didUpdateToMicroLocation:(BCMicroLocation *)newMicroLocation fromMicroLocation:(BCMicroLocation *)oldMicroLocation;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didEnterSite:(BCSite *)site;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didExitSite:(BCSite *)site;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didUpdateNearbySites:(NSArray *)sites;

- (void)microLocationManager:(BCMicroLocationManager *)microLocationManger didUpdateMicroLocationServicesAvailibility:(BOOL)available;

@end

extern NSString * const BCMicroLocationManagerDidEnterSite;
extern NSString * const BCMicroLocationManagerDidExitSite;
extern NSString * const BCMicroLocationManagerDidUpdateMicroLocation;
extern NSString * const BCMicroLocationManagerDidUpdateNearbySites;
extern NSString * const BCMicroLocationManagerDidUpdateMicroLocationServicesAvailibility;

extern NSString * const BCMicroLocationManagerNotificationSiteItem;
extern NSString * const BCMicroLocationManagerNotificationNewLocationItem;
