//
//  BCApp.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/2/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
#import "BCBeaconDataSource.h"

@class BCPlatformType;

@interface BCApp : BCJSONModel<BCBeaconDataSource>

@property (nonatomic, copy) NSString *appID;
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *iTunesURL;
@property (nonatomic, copy) NSString *packageName;
@property (nonatomic, strong) BCPlatformType *platformType;
@property (nonatomic, copy) NSString *appIconURL;

- (void)copyApiPropertiesFromApp:(BCApp *)app;

#pragma mark - BCBeaconDataSource

- (NSDate *)cachedBeaconsAt;
- (NSArray *)cachedBeacons;
- (BOOL)hasBeaconsCacheExpired;

- (NSDate *)cachedSitesAt;
- (NSArray *)cachedSites;
- (BOOL)hasSitesCacheExpired;

- (void)getBeaconsWithSuccess:(void (^)(NSArray *))success
                      failure:(void (^)(NSError *))failure
                 preferCached:(BOOL)preferCached;

- (void)getSitesWithSuccess:(void (^)(NSArray *))success
                      failure:(void (^)(NSError *))failure
                 preferCached:(BOOL)preferCached;

@end
