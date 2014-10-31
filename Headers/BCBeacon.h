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
    BCBeaconAdTypeUnknown = 0,
    BCBeaconAdTypeSphynx1 = 1,
    BCBeaconAdTypeIBeacon2 = 2,
    BCBeaconAdTypeIBeacon3 = 3,
    BCBeaconAdTypeSecure1 = 4
} BCBeaconAdType;

typedef enum {
    BCVerificationStatusNotVerified = 0,
    BCVerificationStatusDetectedAttack,
    BCVerificationStatusVerifiedViaIBeaconAd,
    BCVerificationStatusVerifiedViaSecureAd
} BCVerificationStatus;

typedef enum {
    BCSyncStatusNotSynced = 0,
    BCSyncStatusWillNotSync,
    BCSyncStatusSynced,
    BCSyncStatusRestored
} BCSyncStatus;

@class BCBatteryStatus, BCBeaconLoudness, BCTargetSpeed, BCMapPoint, BCBeaconRegion, BCBeaconMode, BCBeaconVersion, BCBeaconVisit;

@interface BCBeacon : NSObject <NSCopying>

// BlueCats Api properties
@property (nonatomic, copy) NSString *beaconID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *siteName;
@property (nonatomic, copy) NSString *bluetoothAddress;
@property (nonatomic, copy) NSNumber *measuredPowerAt1Meter;
@property (nonatomic, copy) NSString *firmwareVersion;
@property (nonatomic, copy) NSString *latestFirmwareVersion;
@property (nonatomic, copy) NSString *modelNumber;
@property (nonatomic, copy) NSString *serialNumber;
@property (nonatomic, assign) BOOL upgradableOTA;
@property (nonatomic, copy) NSNumber *version;
@property (nonatomic, copy) NSNumber *pendingVersion;
@property (nonatomic, copy) NSDate *createdAt;
@property (nonatomic, copy) NSDate *modifiedAt;
@property (nonatomic, copy) BCBeaconRegion *beaconRegion;
@property (nonatomic, copy) BCBeaconMode *beaconMode;
@property (nonatomic, copy) BCBatteryStatus *batteryStatus;
@property (nonatomic, copy) BCBeaconLoudness *beaconLoudness;
@property (nonatomic, copy) BCTargetSpeed *targetSpeed;
@property (nonatomic, copy) BCMapPoint *mapPoint;
@property (nonatomic, copy) NSArray *categories;
@property (nonatomic, copy) NSArray *customValues;

// CoreBluetooth properties
@property (nonatomic, copy) NSUUID *peripheralIdentifier;
@property (nonatomic, copy) NSDate *firstDiscoveredAt;
@property (nonatomic, copy) NSDate *lastDiscoveredAt;
@property (nonatomic, assign, readonly) BOOL discovered;
@property (nonatomic, copy) NSDictionary *blueCatsAdData;

// iBeacon properties
@property (nonatomic, copy) NSString *proximityUUIDString;
@property (nonatomic, copy) NSNumber *major;
@property (nonatomic, copy) NSNumber *minor;
@property (nonatomic, copy) NSDate *lastRangedAt;
@property (nonatomic, copy) NSDate *firstRangedAt;

// BeaconManager properties
@property (nonatomic, copy) NSDate *cachedAt;
@property (nonatomic, copy) NSDate *syncedAt;
@property (nonatomic, assign) BCSyncStatus syncStatus;
@property (nonatomic, assign, readonly) BOOL synced;
@property (nonatomic, copy, readonly) NSString *iBeaconKey;

// Proximity Properties
@property (nonatomic, assign) double accuracy;
@property (nonatomic, copy) NSNumber *rssi;
@property (nonatomic, assign) BCProximity proximity;

@property (nonatomic, copy) NSDate *verifiedAt;
@property (nonatomic, assign) BCVerificationStatus verificationStatus;

- (NSUInteger)numberOfVisitsToday;
- (NSUInteger)numberOfVisitsYesterday;
- (NSUInteger)numberOfVisitsThisWeek;
- (NSUInteger)numberOfVisitsLastWeek;
- (NSUInteger)numberOfVisitsThisMonth;
- (NSUInteger)numberOfVisitsLastMonth;
- (NSUInteger)numberOfVisitsSinceDate:(NSDate *)date;
- (NSUInteger)numberOfVisitsUntilDate:(NSDate *)date;
- (NSUInteger)numberOfVisitsFromDate:(NSDate *)startDate untilDate:(NSDate *)endDate;

+ (NSUInteger)numberOfBeaconsWithPredicate:(NSPredicate *)predicate;
+ (NSArray *)storedBeaconsWithPredicate:(NSPredicate *)predicate andSortDescriptors:(NSArray *)sortDesc;

@end

extern NSString * const BCAdvertisementDataBeaconModeIDKey;
extern NSString * const BCAdvertisementDataVersionKey;
extern NSString * const BCAdvertisementDataAdTypeKey;
extern NSString * const BCAdvertisementDataProximityUUIDStringKey;
extern NSString * const BCAdvertisementDataBluetoothAddressStringKey;
extern NSString * const BCAdvertisementDataMajorKey;
extern NSString * const BCAdvertisementDataMinorKey;
extern NSString * const BCAdvertisementDataFirmwareVersionKey;
extern NSString * const BCAdvertisementDataModelNumberKey;
extern NSString * const BCAdvertisementDataBatteryLevelKey;
extern NSString * const BCAdvertisementDataTxPowerLevelKey;
extern NSString * const BCAdvertisementDataMeasuredPowerAt1MeterKey;
extern NSString * const BCAdvertisementDataBeaconLoudnessLevelKey;
extern NSString * const BCAdvertisementDataTargetSpeedInMillisecondsKey;
extern NSString * const BCAdvertisementDataSequenceNumberKey;

extern NSString * const BCFirmwareVersion002;
extern NSString * const BCFirmwareVersion010;
extern NSString * const BCFirmwareVersion011;
extern NSString * const BCFirmwareVersion020;
extern NSString * const BCFirmwareVersion030;
extern NSString * const BCFirmwareVersion031;

