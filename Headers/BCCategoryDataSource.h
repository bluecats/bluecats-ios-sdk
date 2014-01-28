//
//  BCCategoryDataSource.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 1/15/14.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCCategory;

@protocol BCCategoryDataSource <NSObject>

@required

- (NSDate *)cachedCategoriesAt;
- (NSArray *)cachedCategories;
- (BOOL)hasCategoriesCacheExpired;

- (void)getCategoriesWithSuccess:(void (^)(NSArray *))success
                         failure:(void (^)(NSError *))failure
                    preferCached:(BOOL)preferCached;

@optional

- (void)createCategory:(BCCategory *)category
               success:(void (^)(BCCategory *))success
               failure:(void (^)(NSError *))failure;

- (void)deleteCategory:(BCCategory *)category
               success:(void (^)(void))success
               failure:(void (^)(NSError *))failure;

@end
