//
//  BCBeacon.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

typedef enum {
	BCProximityUnknown = 0,
	BCProximityImmediate,
	BCProximityNear,
	BCProximityFar
} BCProximity;

typedef enum {
    BCBeaconModeUnknown = 0,
    BCBeaconModeSpecialNeeds = 1,
    BCBeaconModeSphynx = 2,
    BCBeaconModeBengal = 3
} BCBeaconMode;

typedef enum {
    BCAvailabilityStatusNotDetermined = 0,
    BCAvailabilityStatusNotAvailable,
    BCAvailabilityStatusAvailable
} BCAvailabilityStatus;

typedef enum {
    BCSyncStatusNotSynced = 0,
    BCSyncStatusWillNotSync,
    BCSyncStatusSynced
} BCSyncStatus;

@class BCBatteryStatus, BCBeaconLoudness, BCTargetSpeed, BCMapPoint, CBPeripheral;

@interface BCBeacon : NSObject <NSCopying>

// BlueCats Api properties
@property (nonatomic, copy) NSString *beaconID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *siteName;
@property (nonatomic, copy) NSString *bluetoothAddress;
@property (nonatomic, copy) NSDate *createdAt;

@property (nonatomic, copy) BCBatteryStatus *batteryStatus;
@property (nonatomic, copy) BCBeaconLoudness *beaconLoudness;
@property (nonatomic, copy) BCTargetSpeed *targetSpeed;
@property (nonatomic, copy) BCMapPoint *mapPoint;

@property (nonatomic, copy) NSArray *categories;

// CoreBluetooth properties
@property (nonatomic, strong) CBPeripheral *peripheral;
@property (nonatomic, copy) NSDate *firstDiscoveredAt;
@property (nonatomic, copy) NSDate *lastDiscoveredAt;
@property (nonatomic, assign, readonly) BOOL discovered;
@property (nonatomic, copy) NSDictionary *advertisementData;

// iBeacon properties
@property (nonatomic, copy) NSString *proximityUUIDString;
@property (nonatomic, copy) NSNumber *major;
@property (nonatomic, copy) NSNumber *minor;
@property (nonatomic, assign) double accuracy;
@property (nonatomic, copy) NSNumber *rssi;
@property (nonatomic, assign) BCProximity proximity;

// BeaconManager properties
@property (nonatomic, copy) NSDate *cachedAt;
@property (nonatomic, copy) NSDate *syncedAt;
@property (nonatomic, assign) BCSyncStatus syncStatus;
@property (nonatomic, assign, readonly) BOOL synced;
@property (nonatomic, copy, readonly) NSString *compositeKey;

- (BOOL)needsBehaviourUpdate;
@property (nonatomic, assign, readonly) BCAvailabilityStatus behaviourUpdatingAvailabilityStatus;
@property (nonatomic, assign, readonly) BCAvailabilityStatus modeSwitchingAvailabilityStatus;
@property (nonatomic, assign, readonly) BCAvailabilityStatus opcodeControllingAvailabilityStatus;

- (void)copyApiPropertiesFromBeacon:(BCBeacon *)beacon;

// Class methods
+ (NSString *)compositeKeyForProximityUUIDString:(NSString *)proximityUUIDString
                                           major:(NSNumber *)major
                                           minor:(NSNumber *)minor;

@end

extern NSString * const BCAdvertisementDataModeKey;
extern NSString * const BCAdvertisementDataProximityUUIDStringKey;
extern NSString * const BCAdvertisementDataBluetoothAddressStringKey;
extern NSString * const BCAdvertisementDataMajorKey;
extern NSString * const BCAdvertisementDataMinorKey;
extern NSString * const BCAdvertisementDataFirmwareVersionKey;
extern NSString * const BCAdvertisementDataModelNumberKey;
extern NSString * const BCAdvertisementDataBatteryLevelKey;
extern NSString * const BCAdvertisementDataTxPowerLevelKey;
extern NSString * const BCAdvertisementDataMeasuredPowerAtOneMeterKey;
extern NSString * const BCAdvertisementDataBeaconLoudnessLevelKey;
extern NSString * const BCAdvertisementDataTargetSpeedInMillisecondsKey;

extern NSString * const BCFirmwareVersion002;
extern NSString * const BCFirmwareVersion010;
extern NSString * const BCFirmwareVersion011;

