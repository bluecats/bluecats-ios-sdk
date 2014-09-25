//
//  BCEvent.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 30/06/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BCEvent : NSObject<NSCopying>

@property (nonatomic, copy) NSString *eventID;
@property (nonatomic, copy) NSString *eventIdentifier;
@property (nonatomic, copy) NSString *deviceUUID;
@property (nonatomic, copy) NSString *sessionUUID;
@property (nonatomic, copy) NSString *customDeviceIdentifier;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *beaconID;
@property (nonatomic, copy) NSString *categoryID;
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

@end
