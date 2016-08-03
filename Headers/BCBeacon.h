//
//  BCBeacon.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
#import "BCDefinitions.h"

@class BCMapPoint, BCBatteryStatus, BCEddystone, BCSite, BCTemperatureData, BCBeaconLoudness, BCBeaconMode, BCTargetSpeed, BCBeaconRegion;

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

///The Proximity UUID of the beacon.
@property (nonatomic, copy) NSString *proximityUUIDString;
///The major value of the beacon.
@property (nonatomic, copy) NSNumber *major;
///The minor value of the beacon.
@property (nonatomic, copy) NSNumber *minor;

///@name Eddystone Properties

///The Eddystone properties of the beacon such as namespace and URL.
@property (nonatomic, copy) BCEddystone *eddystone;
@property (nonatomic, copy) NSNumber *uptime;

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

@property(nonatomic, copy) BCTemperatureData * temperatureData;

- (BOOL)isNewborn;
- (BOOL)isIBeacon;
- (BOOL)isEddystone;
- (BOOL)isBlueCat;
- (BOOL)isSecure;

- (BOOL)hasDiscoveredEddystoneUIDFrame;
- (BOOL)hasDiscoveredEddystoneURLFrame;
- (BOOL)hasDiscoveredEddystoneTelemetryFrame;

- (NSString *)localName;
- (NSString *)cacheIdentifier;



///@name Requesting Data from a Beacon Endpoint
/**
 *  Issues an asynchronous request for data from a beacon endpoint with the specified response data array and success, status and failure blocks.
 *
 *  @param endpoint         Type of beacon endpoint.
 *  @param requestDataArray Request parameters.
 *  @param success          The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `responseDataArray` | The response data array.
 *
 *  @param status           The block object to be executed while the operation is completing.
 *
 *  The block has no return value and takes one argument:
 *
 *  `status` | The operation status.
 *
 *  @param failure          The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */

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

- (void)transportDataRequest:(NSData *)requestData
            toBeaconEndpoint:(BCBeaconEndpoint)endpoint
                     success:(void (^)(NSData *responseData))success
                      status:(void (^)(NSString *status))status
                     failure:(void (^)(NSError *error))failure;

@end

