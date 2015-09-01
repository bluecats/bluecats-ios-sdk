//
//  BCLasso.h
//  BlueCatsSDK
//
//  Created by Zach Prager on 7/31/15.
//  Copyright (c) 2015 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCBeacon;

@interface BCLasso : NSObject

@property (nonatomic, readonly) BCBeacon *beacon;
@property (nonatomic, readonly) double redemptionRadius;

- (instancetype) initWithBeacon:(BCBeacon *)beacon;

@end
