//
//  BCEvent.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 30/06/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"
#import <Foundation/Foundation.h>

@interface BCEvent : BCJSONModel<NSCopying>

@property (nonatomic, copy) NSString *eventID;
@property (nonatomic, copy) NSString *eventIdentifier;
@property (nonatomic, copy) NSString *eventName;
@property (nonatomic, copy) NSString *deviceUUID;
@property (nonatomic, copy) NSString *sessionUUID;
@property (nonatomic, copy) NSString *customDeviceIdentifier;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *siteName;
@property (nonatomic, copy) NSString *beaconID;
@property (nonatomic, copy) NSString *beaconName;
@property (nonatomic, copy) NSString *categoryID;
@property (nonatomic, copy) NSString *categoryName;
@property (nonatomic, copy) NSDate *beganAt;
@property (nonatomic, copy) NSDate *endedAt;
@property (nonatomic, copy) NSNumber *rssi;
@property (nonatomic, copy) NSNumber *accuracy;
@property (nonatomic, copy) NSString *mapID;
@property (nonatomic, copy) NSNumber *mapX;
@property (nonatomic, copy) NSNumber *mapY;
@property (nonatomic, copy) NSString *value1;
@property (nonatomic, copy) NSString *value2;
@property (nonatomic, copy) NSString *value3;
@property (nonatomic, assign) NSNumber* beganInBackground;
@property (nonatomic, assign) NSNumber* endedInBackground;
@property (nonatomic, copy) NSDate* lastPostedAt;

+ (void)storedEventsWithPredicate:(NSPredicate *)predicate
                  sortDescriptors:(NSArray *)sortDesc
                          success:(void (^)(NSArray *visits))success
                          failure:(void (^)(NSError *error))failure;

+ (void)numberOfEventsWithPredicate:(NSPredicate *)predicate
                            success:(void (^)(NSUInteger visitCount))success
                            failure:(void (^)(NSError *error))failure;

@end
