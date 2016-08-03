//
//  BCLasso.h
//  BlueCatsSDK
//
//  Created by Zach Prager on 7/31/15.
//  Copyright (c) 2015 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCBeacon;

///The `BCLasso` class defines an object that represents a lasso device.
@interface BCLasso : NSObject

///@name Lasso Properties

///The beacon embedded in the lasso device.
@property (nonatomic, readonly) BCBeacon *beacon;
///The status of the devices redemption with the lasso.
@property (nonatomic, readonly) double redemptionRadius;

///@name Initialization
/**
 *  Creates a BCDevice from the provided BCBeacon.
 *
 *  @param beacon The beacon object.
 *
 *  @return Retuns the instance type of the created `BCDevice` object.
 */
- (instancetype) initWithBeacon:(BCBeacon *)beacon;

@end
