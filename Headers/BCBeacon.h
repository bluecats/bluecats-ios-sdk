//
//  BCBeacon.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

typedef enum {
	BCProximityUnknown = 0,
	BCProximityImmediate,
	BCProximityNear,
	BCProximityFar
} BCProximity;

typedef enum {
    BCBlueCatsAdDataTypeUnknown = 0,
    BCBlueCatsAdDataTypeSphynx1 = 1,
    BCBlueCatsAdDataTypeIBeacon2 = 2,
    BCBlueCatsAdDataTypeIBeacon3 = 3,
    BCBlueCatsAdDataTypeSecure1 = 4,
    BCBlueCatsAdDataTypeIBeacon4 = 5,
    BCBlueCatsAdDataTypeSecure2 = 6,
    BCBlueCatsAdDataTypeData1 = 7
} BCBlueCatsAdDataType;

typedef enum {
    BCVerificationStatusNotVerified = 0,
    BCVerificationStatusDetectedAttack,
    BCVerificationStatusVerifiedViaBlueCatsIBeaconAd,
    BCVerificationStatusVerifiedViaBueCatsSecureAd
} BCVerificationStatus;

typedef enum {
    BCSyncStatusNotSynced = 0,
    BCSyncStatusWillNotSync,
    BCSyncStatusSynced,
    BCSyncStatusRestored
} BCSyncStatus;

typedef enum {
    BCBlockDataEncodingNone = 0,
    BCBlockDataEncodingUTF8
} BCBlockDataEncoding;

typedef enum {
    BCBlockDataTypeCustom = 0,
    BCBlockDataTypeTempInCelcius
} BCBlockDataType;


@class BCBatteryStatus, BCBeaconLoudness, BCTargetSpeed, BCMapPoint, BCBeaconRegion, BCBeaconMode, BCBeaconVersion, BCBeaconVisit;

@interface BCBeacon : BCJSONModel <NSCopying>

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
@property (nonatomic, strong) NSArray *categories;
@property (nonatomic, strong) NSArray *customValues;

// CoreBluetooth properties
@property (nonatomic, copy) NSUUID *peripheralIdentifier;
@property (nonatomic, copy) NSDate *firstDiscoveredAt;
@property (nonatomic, copy) NSDate *lastDiscoveredAt;
@property (nonatomic, assign, readonly) BOOL discovered;

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

- (void)removeAllAdData;
- (void)removeAdDataForAdDataTypeKey:(NSString *)adDataTypeKey;
- (void)setAdData:(NSDictionary *)adData forAdDataTypeKey:(NSString *)adDataTypeKey;
- (NSDictionary *)adDataForAdDataTypeKey:(NSString *)adDataTypeKey;
- (id)objectFromBlueCatsAdDataForKey:(NSString *)key;

- (NSArray *)reassembledBlockDataWithDataType:(BCBlockDataType)dataType;
- (NSDictionary *)lastReassembledBlockDataWithDataType:(BCBlockDataType)dataType;

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

extern NSString * const BCFirmwareVersion002;
extern NSString * const BCFirmwareVersion010;
extern NSString * const BCFirmwareVersion011;
extern NSString * const BCFirmwareVersion020;
extern NSString * const BCFirmwareVersion030;
extern NSString * const BCFirmwareVersion031;

extern NSString * const BCAdDataTypeKey;

extern NSString * const BCAdDataTypeAppleIBeaconKey;
extern NSString * const BCAdDataTypeBlueCatsSphynxKey;
extern NSString * const BCAdDataTypeBlueCatsIBeaconKey;
extern NSString * const BCAdDataTypeBlueCatsSecureKey;
extern NSString * const BCAdDataTypeBlueCatsBlockDataKey;

extern NSString * const BCBlueCatsAdDataBeaconModeIDKey;
extern NSString * const BCBlueCatsAdDataVersionKey;
extern NSString * const BCBlueCatsAdDataTypeKey;
extern NSString * const BCBlueCatsAdDataProximityUUIDStringKey;
extern NSString * const BCBlueCatsAdDataBluetoothAddressStringKey;
extern NSString * const BCBlueCatsAdDataMajorKey;
extern NSString * const BCBlueCatsAdDataMinorKey;
extern NSString * const BCBlueCatsAdDataFirmwareVersionKey;
extern NSString * const BCBlueCatsAdDataModelNumberKey;
extern NSString * const BCBlueCatsAdDataBatteryLevelKey;
extern NSString * const BCBlueCatsAdDataTxPowerLevelKey;
extern NSString * const BCBlueCatsAdDataMeasuredPowerAt1MeterKey;
extern NSString * const BCBlueCatsAdDataBeaconLoudnessLevelKey;
extern NSString * const BCBlueCatsAdDataTargetSpeedInMillisecondsKey;
extern NSString * const BCBlueCatsAdDataSequenceNumberKey;

extern NSString * const BCBlueCatsBlockDataIdentifierKey;
extern NSString * const BCBlueCatsBlockDataTypeKey;
extern NSString * const BCBlueCatsBlockDataEncodingKey;
extern NSString * const BCBlueCatsBlockDataCountKey;
extern NSString * const BCBlueCatsBlockDataIndexKey;
extern NSString * const BCBlueCatsBlockDataLengthKey;
extern NSString * const BCBlueCatsBlockDataKey;
extern NSString * const BCBlueCatsIndexedBlockDataKey;

extern NSString * const BCAppleIBeaconAdDataProximityUUIDStringKey;
extern NSString * const BCAppleIBeaconAdDataMajorKey;
extern NSString * const BCAppleIBeaconAdDataMinorKey;
extern NSString * const BCAppleIBeaconAdDataMeasuredPowerAt1MeterKey;

