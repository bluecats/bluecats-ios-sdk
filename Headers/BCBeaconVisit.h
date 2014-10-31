//
//  BCBeaconVisit.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCBeacon.h"

@class CLLocation, BCManagedBeaconVisit;

@interface BCBeaconVisit : NSObject <NSCopying>

@property (nonatomic, copy) NSString *beaconVisitID;
@property (nonatomic, copy) NSString *SDKVersion;
@property (nonatomic, copy) NSString *firmwareVersion;
@property (nonatomic, copy) NSString *proximityUUIDString;
@property (nonatomic, copy) NSString *bluetoothAddress;
@property (nonatomic, copy) NSNumber *major;
@property (nonatomic, copy) NSNumber *minor;
@property (nonatomic, copy) NSString *serialNumber;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *deviceUUID;
@property (nonatomic, copy) NSString *sessionUUID;
@property (nonatomic, copy) NSDate *beganAt;
@property (nonatomic, copy) NSNumber *rssiWhenVisitBegan;
@property (nonatomic, copy) NSDate *endedAt;
@property (nonatomic, copy) NSNumber *rssiWhenVisitEnded;
@property (nonatomic, copy) NSNumber *batteryLevel;
@property (nonatomic, copy) NSNumber *latitude;
@property (nonatomic, copy) NSNumber *longitude;
@property (nonatomic, copy) NSDate *deviceWasClosestAt;
@property (nonatomic, copy) NSNumber *cDist;
@property (nonatomic, copy) NSNumber *rssiWhenDeviceWasClosest;
@property (nonatomic, copy) NSDate *enteredCProxAt;
@property (nonatomic, copy) NSNumber *rssiWhenCProxEntered;
@property (nonatomic, copy) NSDate *exitedCProxAt;
@property (nonatomic, copy) NSNumber *rssiWhenCProxExited;
@property (nonatomic, assign) BCProximity cProx;
@property (nonatomic, copy) NSNumber *cProxID;
@property (nonatomic, copy) NSNumber *verificationStatusID;
@property (nonatomic, copy) NSDate *lastRangedAt;
@property (nonatomic, copy) NSDate *lastPostedAt;
@property (nonatomic, assign) BOOL beganInBackground;
@property (nonatomic, assign) BOOL endedInBackground;
@property (nonatomic, strong) BCManagedBeaconVisit *managedBeaconVisit;

- (void)setLocation:(CLLocation *)location;

+ (BCBeaconVisit *)beaconVisitWithManagedBeaconVisit:(BCManagedBeaconVisit *)managedbeaconVisit;

+ (NSArray *)storedVisitsWithPredicate:(NSPredicate *)predicate andSortDescriptors:(NSArray *)sortDesc;

+ (NSUInteger)numberOfVisitsWithPredicate:(NSPredicate *)predicate;

@end