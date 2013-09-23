//
//  BCSite.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/30/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

@class CLLocation;

@class  BCAddress;

@interface BCSite : NSObject <NSCopying>

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

@end
