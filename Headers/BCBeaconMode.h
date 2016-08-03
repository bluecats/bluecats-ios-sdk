//
//  BCBeaconMode.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 5/2/14.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"
#import <Foundation/Foundation.h>

@interface BCBeaconMode : BCJSONModel

@property (nonatomic, assign) NSInteger beaconModeID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *displayName;

+ (BOOL)isValidBeaconModeID:(NSInteger)beaconModeID;

@end

extern NSInteger const BCBeaconModeIDSecure;
extern NSInteger const BCBeaconModeIDIBeacon;
extern NSInteger const BCBeaconModeIDIBeaconPlusSecure;
extern NSInteger const BCBeaconModeIDUID;
extern NSInteger const BCBeaconModeIDURL;
extern NSInteger const BCBeaconModeIDNewborn;
extern NSInteger const BCBeaconModeIDIBeaconPlusUID;

