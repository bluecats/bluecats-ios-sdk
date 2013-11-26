//
//  BCSite.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/30/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCBeaconDataSource.h"

typedef enum {
    BCSiteStateUnknown = 0,
    BCSiteStateInside,
    BCSiteStateOutside,
} BCSiteState;

@class CLLocation, BCAddress, BCSiteAccessType, BCSiteType;

@protocol BCSiteDelegate;

@interface BCSite : NSObject <NSCopying, BCBeaconDataSource>

@property (nonatomic, assign) NSObject<BCSiteDelegate> *delegate;
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, assign) NSInteger beaconCount;
@property (nonatomic, strong) BCSiteAccessType *siteAccessType;
@property (nonatomic, strong) BCSiteType *siteType;
@property (nonatomic, copy) NSDate *createdAt;

@property (nonatomic, copy) NSDate *syncedAt;
@property (nonatomic, copy) NSDate *cachedAt;

- (void)copyApiPropertiesFromSite:(BCSite *)site;

@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *greeting;
@property (nonatomic, strong) BCAddress *address;
@property (nonatomic, copy) NSArray *maps;

@property (nonatomic, copy) NSDate *cachedCategoriesAt;
@property (nonatomic, copy) NSArray *cachedCategories;

- (BOOL)hasCategoriesCacheExpired;

- (void)loadCategoriesWithSuccess:(void (^)(BCSite *, NSArray *))success
                          failure:(void (^)(BCSite *, NSError *))failure
                     preferCached:(BOOL)preferCached;

- (CLLocation *)location;

@property (nonatomic, copy) NSDate *cachedBeaconsAt;

- (NSArray *)cachedBeacons;
- (BOOL)hasBeaconsCacheExpired;
- (void)loadBeaconsWithSuccess:(void (^)(NSArray *))success failure:(void (^)(NSError *))failure preferCached:(BOOL)preferCached;

- (BOOL)synced;

@end


@protocol BCSiteDelegate <NSObject>

@optional
- (void)siteDidUpdateApiProperties:(BCSite*)site;

@end