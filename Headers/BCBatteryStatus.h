//
//  BCBatteryStatus.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

@interface BCBatteryStatus : BCJSONModel <NSCopying>

@property (nonatomic, assign) NSInteger batteryStatusID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *displayName;

@end
