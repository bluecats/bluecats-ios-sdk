//
//  BCBeaconDataSource.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 11/5/13.
//  Copyright (c) 2013 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCAddress;

@protocol BCBeaconDataSource <NSObject>

@optional

- (BCAddress *)address;

@required

- (NSDate *)cachedBeaconsAt;
- (NSArray *)cachedBeacons;
- (BOOL)hasBeaconsCacheExpired;

- (void)getBeaconsWithSuccess:(void (^)(NSArray *))success
                      failure:(void (^)(NSError *))failure
                 preferCached:(BOOL)preferCached;

@end
