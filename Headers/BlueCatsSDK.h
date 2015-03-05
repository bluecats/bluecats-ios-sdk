//
//  BlueCats.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCApp.h"

typedef NS_ENUM(int, BCStatus) {
    kBCStatusNeverPurred = 0,
    kBCStatusPurring,
    kBCStatusPurringWithErrors
};

typedef NS_ENUM(int, BCAppTokenVerificationStatus) {
    kBCAppTokenVerificationStatusNotProvided = 0,
    kBCAppTokenVerificationStatusNotVerified,
    kBCAppTokenVerificationStatusVerified,
    kBCAppTokenVerificationStatusInvalid
};

@interface BlueCatsSDK : NSObject

+ (void)setOptions:(NSDictionary*)options;

+ (void)startPurring:(void (^)(BCStatus status))completion;
+ (void)startPurringWithAppToken:(NSString *)appToken completion:(void (^)(BCStatus status))completion;

+ (void)stopPurring;

+ (void)setAppToken:(NSString *)appToken;
+ (void)setCredentialsWithUserName:(NSString *)userName password:(NSString *)password;

+ (BCStatus)status;
+ (BCAppTokenVerificationStatus)appTokenVerificationStatus;
+ (BOOL)isNetworkReachable;
+ (BOOL)isLocationAuthorized;
+ (BOOL)isBluetoothEnabled;

#if defined(__IPHONE_OS_VERSION_MIN_REQUIRED)
+ (void)requestAlwaysLocationAuthorization;
+ (void)requestWhenInUseLocationAuthorization;
#else
+ (void)requestLocationAuthorization;
#endif


+(BCApp*) currentApp;

@end

extern NSString * const BCOptionUseStageApi;
extern NSString * const BCOptionTrackBeaconVisits;
extern NSString * const BCOptionMonitorBlueCatsRegionOnStartup;
extern NSString * const BCOptionMonitorAllAvailableRegionsOnStartup;
extern NSString * const BCOptionUseEnergySaverScanStrategy;
extern NSString * const BCOptionScanInBackground;
extern NSString * const BCOptionCrowdSourceBeaconUpdates;
extern NSString * const BCOptionUseLocalStorage;
extern NSString * const BCOptionCacheAllBeaconsForApp;
extern NSString * const BCOptionDiscoverBeaconsNearby;
extern NSString * const BCOptionCacheRefreshTimeIntervalInSeconds;
extern NSString * const BCOptionShowBluetoothPowerWarningMessage;


