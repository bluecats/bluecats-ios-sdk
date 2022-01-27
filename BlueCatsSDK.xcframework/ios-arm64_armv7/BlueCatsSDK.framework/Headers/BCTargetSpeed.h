//
//  BCTargetSpeed.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

@interface BCTargetSpeed : BCJSONModel<NSCopying>

@property (nonatomic, assign) NSInteger targetSpeedID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *displayName;
@property (nonatomic, assign) NSInteger milliseconds;

@end
