//
//  BCBeacon.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreLocation/CoreLocation.h>

typedef enum {
	BCProximityUnknown,
	BCProximityImmediate,
	BCProximityNear,
	BCProximityFar
} BCProximity;

@class BCBatteryStatus, BCBeaconLoudness, BCTargetSpeed, BCBeaconRSSILog, BCMapPoint;

@protocol BCBeaconDelegate;

@interface BCBeacon : NSObject


// BlueCats Api properties
@property (nonatomic, copy) NSString *beaconID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *siteName;
@property (nonatomic, strong) NSDate *createdAt;
@property (nonatomic, strong) BCBatteryStatus *batteryStatus;
@property (nonatomic, strong) BCBeaconLoudness *beaconLoudness;
@property (nonatomic, strong) BCTargetSpeed *targetSpeed;
@property (nonatomic, copy) NSArray *categories;
@property (nonatomic, strong) BCMapPoint *mapPoint;

// Core bluetooth properties
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, copy) NSNumber *smoothedRSSI;
@property (nonatomic, copy) NSNumber *batteryLevel;
@property (nonatomic, copy) NSNumber *txPowerLevel;
@property (nonatomic, copy) NSDate *firstDiscoveredAt;
@property (nonatomic, copy) NSDate *lastDiscoveredAt;
@property (nonatomic, copy) NSMutableArray *beaconRSSILogs;

// iBeacon properties
@property (nonatomic, copy) NSString *proximityUUIDString;
@property (nonatomic, copy) NSNumber *major;
@property (nonatomic, copy) NSNumber *minor;
@property (nonatomic, assign) double accuracy;
@property (nonatomic, copy) NSNumber *rssi;
@property (nonatomic, assign) BCProximity proximity;

// BCBeaconManager properties
@property (nonatomic, copy) NSDate *cachedAt;
@property (nonatomic, copy, readonly) NSDate *syncedAt;
@property (nonatomic, copy, readonly) NSString *compositeKey;

- (void)copyApiPropertiesFromBeacon:(BCBeacon *)beacon;

- (BOOL)needsBeaconLoudnessUpdated;
- (NSData *)beaconLoudnessLevelData;

- (BOOL)discovered;
- (BOOL)synced;

- (void)addDelegate:(NSObject<BCBeaconDelegate> *)delegate;
- (void)removeDelegate:(NSObject<BCBeaconDelegate> *)delegate;

// Class methods
+ (NSString *)compositeKeyForProximityUUIDString:(NSString *)proximityUUIDString major:(NSNumber *)major minor:(NSNumber *)minor;

@end


@protocol BCBeaconDelegate <NSObject>

@optional
- (void)beaconDidUpdateRSSI:(BCBeacon*)beacon;
- (void)beaconDidUpdateApiAttributes:(BCBeacon*)beacon;
- (void)beacon:(BCBeacon*)beacon didLogRSSI:(BCBeaconRSSILog *)rssiLog;

@end
