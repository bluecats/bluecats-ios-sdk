//
//  BCBeaconLoudness.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

@interface BCBeaconLoudness : BCJSONModel <NSCopying>

@property (nonatomic, assign) NSInteger beaconLoudnessID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *displayName;
@property (nonatomic, assign) NSInteger level;
@property (nonatomic, assign) NSInteger measuredPowerAt1Meter;
@property (nonatomic, assign) NSInteger tiMeasuredPowerAt1Meter;

@end
