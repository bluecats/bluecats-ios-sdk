//
//  BCBeacon.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
#import "BCDefinitions.h"
#import "BCMeasurement.h"

@class BCMapPoint, BCBatteryStatus, BCEddystone, BCSite, BCBeaconLoudness, BCBeaconMode, BCTargetSpeed, BCBeaconRegion;

@protocol BCBeaconDelegate;

///The `BCBeacon` class defines an object that represents a beacon.
@interface BCBeacon : BCJSONModel <NSCopying>

///@name Beacon Properties

///The object id.
@property (nonatomic, copy) NSString *beaconID;
///The serial number of the beacon.  This is the preferred unique beacon identifier.
@property (nonatomic, copy) NSString *serialNumber;
///The model number of the beacon.  I.e. BC303-A -> AA, BC202-A -> USB.
@property (nonatomic, copy) NSString *modelNumber;
///The name of the beacon.  This can be used to organize your beacons by color or room for example.
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSDate *lastRangedAt;
@property (nonatomic, copy) NSString *wireframeURLString;
///@name iBeacon Properties


// Identity properties
@property (nonatomic, copy) NSString *bluetoothAddress;

///The Proximity UUID of the beacon.
@property (nonatomic, copy) NSString *proximityUUIDString;
///The major value of the beacon.
@property (nonatomic, copy) NSNumber *major;
///The minor value of the beacon.
@property (nonatomic, copy) NSNumber *minor;

///@name Eddystone Properties

///The Eddystone properties of the beacon such as namespace and URL.
@property (nonatomic, copy) BCEddystone *eddystone;
//@property (nonatomic, copy) NSNumber *uptime;

///@name Proximity Properties
@property (nonatomic, assign) double accuracy;
///The received signal strength indication of the beacon. Reasonable values range from -40 dBm at the highest to -110 dBm at the lowest.
@property (nonatomic, copy) NSNumber *rssi;
///The BCProximity value of the beacon.
@property (nonatomic, assign) BCProximity proximity;

///@name Versioned properties

///The advertising mode of the beacon, such as iBeacon or BlueCats Secure
@property (nonatomic, copy) BCBeaconMode *beaconMode;
///The beacon loundess / range
@property (nonatomic, copy) BCBeaconLoudness *beaconLoudness;
///The beacon advertisment frequency
@property (nonatomic, copy) BCTargetSpeed *targetSpeed;
///Version number for the current settings
@property (nonatomic, copy) NSNumber *version;
///Version number for settings not yet applied to the beacon. Will be nil if the settings are up to date.
@property (nonatomic, copy) NSNumber *pendingVersion;

///@name Firmware properties

///The current firmware version of the beacon
@property (nonatomic, copy) NSString *firmwareVersion;
@property (nonatomic, copy) NSString *firmwareUID;

///@name Context Properties

///An array of BCCategories that have been applied to the beacon.
@property (nonatomic, copy) NSArray *categories;
///A dictionary containing the beacon's custom values.
@property (nonatomic, copy, readonly) NSDictionary *customValueForKey;
///The beacon's map point if placed on a map.
@property (nonatomic, copy) BCMapPoint *mapPoint;

///@name Beacon Health Properties

///The battery status of the beacon.  Alive: 100% - 25%, Warning: 25% - 10%, Critical: <10%.
@property (nonatomic, copy) BCBatteryStatus *batteryStatus;
///The last known battery level of the beacon.
@property (nonatomic, copy) NSNumber *lastKnownBatteryLevel;

///@name Organizational Properties

///The ID of the team the beacon is within.
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, copy) BCSite *site;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *siteName;

///@name Raw Beacon Data
@property (nonatomic, copy) NSData *rawMeasurementData;

//
- (BOOL)isNewborn;
- (BOOL)isIBeacon;
- (BOOL)isEddystone;
- (BOOL)isBlueCat;
- (BOOL)isSecure;
- (BOOL)hasIdentifierData;

- (BOOL)hasDiscoveredEddystoneUIDFrame;
- (BOOL)hasDiscoveredEddystoneURLFrame;
- (BOOL)hasDiscoveredEddystoneTelemetryFrame;

- (NSString *)identifierDataString;
- (NSString *)localName;
- (NSString *)cacheIdentifier;

- (void)sendDataRequest:(NSData *)requestData
       toBeaconEndpoint:(BCBeaconEndpoint)endpoint
                success:(void (^)(NSData *responseData))success
                 status:(void (^)(NSString *status))status
                failure:(void (^)(NSError *error))failure;

- (void)sendDataRequests:(NSArray *)requestDataArray
        toBeaconEndpoint:(BCBeaconEndpoint)endpoint
                 success:(void (^)(NSArray *responseDataArray))success
                  status:(void (^)(NSString *status))status
                 failure:(void (^)(NSError *error))failure;

- (void)sendOpcode:(BCBeaconOpcode)opcode
           success:(void (^)(void))success
           failure:(void (^)(NSError *error))failure;

- (void)sendOpcode:(BCBeaconOpcode)opcode
          withData:(NSData *)data
           success:(void (^)(void))success
           failure:(void (^)(NSError *error))failure;

- (void)transportDataRequest:(NSData *)requestData
            toBeaconEndpoint:(BCBeaconEndpoint)endpoint
                     success:(void (^)(NSData *responseData))success
                      status:(void (^)(NSString *status))status
                     failure:(void (^)(NSError *error))failure;

- (void)updateSettingsOffPlatformWithSettings:(NSDictionary *)settingsForKey
                                      success:(void (^)(void))success
                                       status:(void (^)(NSString *))status
                                      failure:(void (^)(NSError *error))failure;

- (NSArray<BCMeasurement *> *) measurementsOfType:(BCMeasurementType)type;
- (NSArray<NSNumber *> *) availableMeasurementTypes;

@end

