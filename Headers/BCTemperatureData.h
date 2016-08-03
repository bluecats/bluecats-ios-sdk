//
// Created by Jacky on 23/03/2016.
// Copyright (c) 2016 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCJSONModel.h"


@interface BCTemperatureData : NSObject

@property(nonatomic, copy, readonly) NSDate *timestamp;
@property(nonatomic, readonly) float  tempInCelcius;

- (instancetype)initWithBlockDataInfo:(NSDictionary *)blockDataInfo;
- (void)updateWithBlockDataInfo:(NSDictionary *)blockDataInfo;
+ (instancetype)temperatureDataWithBlockDataInfo:(NSDictionary *)blockDataInfo;

@end