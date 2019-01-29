//
//  BCBeaconVisit.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
#import "BCBeacon.h"

@class CLLocation, BCManagedBeaconVisit;

///The `BCBeaconVisit` class defines an object that represents a device's visit to a single beacon.
@interface BCBeaconVisit : BCJSONModel <NSCopying>

///@name Beacon Visit Properties

///The beacon visit id.
@property (nonatomic, copy) NSString *beaconVisitID;
///Device SDK version.
@property (nonatomic, copy) NSString *SDKVersion;
///Beacon firmware version.
@property (nonatomic, copy) NSString *firmwareUID;
///Proximity UUID of the Beacon.
@property (nonatomic, copy) NSString *proximityUUIDString;
///Bluetooth address of the beacon.  This is a spoofed value and changes
@property (nonatomic, copy) NSString *bluetoothAddress;
///Beacon major value.
@property (nonatomic, copy) NSNumber *major;
///Beacon minor value.
@property (nonatomic, copy) NSNumber *minor;
///Beacon version number.
@property (nonatomic, copy) NSNumber *version;
///Beacon serial number.
@property (nonatomic, copy) NSString *serialNumber;
///The site identifier the beacon is within.
@property (nonatomic, copy) NSString *siteID;
///The device UUID when it visited the beacon.
@property (nonatomic, copy) NSString *deviceUUID;
///The session UUID.
@property (nonatomic, copy) NSString *sessionUUID;
///The date the visit began.
@property (nonatomic, copy) NSDate *beganAt;
///The RSSI when the visit began.
@property (nonatomic, copy) NSNumber *rssiWhenVisitBegan;
///The date the visit ended.
@property (nonatomic, copy) NSDate *endedAt;
///The RSSI when the visit ended.
@property (nonatomic, copy) NSNumber *rssiWhenVisitEnded;
///The battery level of the beacon.
@property (nonatomic, copy) NSNumber *batteryLevel;
///The latitude when the visit ended.
@property (nonatomic, copy) NSNumber *latitude;
///The longitude when the visit ended.
@property (nonatomic, copy) NSNumber *longitude;
///The time (date) the device was closest to the beacon.
@property (nonatomic, copy) NSDate *deviceWasClosestAt;
///Accuracy (distance) when the device was closest to the beacon.
@property (nonatomic, copy) NSNumber *cDist;
///The RSSI when the device was closest to the beacon.
@property (nonatomic, copy) NSNumber *rssiWhenDeviceWasClosest;
///The date when the device entered its closest proximity to the beacon.
@property (nonatomic, copy) NSDate *enteredCProxAt;
///The RSSI when the device entered its closes proximity to the beacon.
@property (nonatomic, copy) NSNumber *rssiWhenCProxEntered;
///The date when the device exited its closest proximity to the beacon.
@property (nonatomic, copy) NSDate *exitedCProxAt;
///The RSSI when the device exited its closest proximity to the beacon.
@property (nonatomic, copy) NSNumber *rssiWhenCProxExited;
///The closest proximity the of the device to the beacon.
@property (nonatomic, assign) BCProximity cProx;
///The ID of the closest proximity of the device to the beacon.
@property (nonatomic, copy) NSNumber *cProxID;
/////The last verification status ID of the beacon during the visit.
//@property (nonatomic, copy) NSNumber *verificationStatusID;
///The date the beacon was last ranged.
@property (nonatomic, copy) NSDate *lastRangedAt;
///The date a visit to beacon was last posted.
@property (nonatomic, copy) NSDate *lastPostedAt;
///A bool value indicating if the visit began in the background. `YES` if the visit began in the background. `NO` if the visit began in the foreground.
@property (nonatomic, assign) BOOL beganInBackground;
///A bool value indicating if the visit ended in the background. `YES` if the visit ended in the background. `NO` if the visit ended in the foreground.
@property (nonatomic, assign) BOOL endedInBackground;
///The mode of the beacon.
@property (nonatomic, assign) NSInteger beaconModeID;
///A `BOOL` value indicating if the device is currently visiting the beacon. `YES` if the device is currently visiting the beacon. `NO` if the device is not currently visiting the beacon.
@property (nonatomic, assign, getter=isCurrentlyVisiting) BOOL currentlyVisiting;

///@name Initialization
/**
 *  Initializes a BCBeaconVisit with the provided BCManagedBeaconVisit.
 *
 *  @param managedBeaconVisit A BCManagedBeaconVisit object.
 *
 *  @return Returns the object ID.
 */
- (id)initWithManagedBeaconVisit:(BCManagedBeaconVisit *)managedBeaconVisit;

///@name Setting the Location
/**
 *  Sets the latitude and longitude for the visit from a CLLocation object.
 *
 *  @param location CLLocation location object.
 */
- (void)setLocation:(CLLocation *)location;

///@name Getting Visits
/**
 *  Issues an asynchronous request to get the visits to the beacon matching the predicate and sort descriptors with success and failure blocks.
 *
 *  @param predicate Predicate condition(s).
 *  @param sortDesc  Sort description.
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure   The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
+ (void)storedVisitsWithPredicate:(NSPredicate *)predicate
                  sortDescriptors:(NSArray *)sortDesc
                          success:(void (^)(NSArray *visits))success
                          failure:(void (^)(NSError *error))failure;

///@name Getting Visit Count
/**
 *  Issues an asynchronous request to get the number visits to the beacon matching the predicate with success and failure blocks.
 *
 *  @param predicate Predicate condition(s).
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure   The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
+ (void)numberOfVisitsWithPredicate:(NSPredicate *)predicate
                            success:(void (^)(NSUInteger visitCount))success
                            failure:(void (^)(NSError *error))failure;

@end
