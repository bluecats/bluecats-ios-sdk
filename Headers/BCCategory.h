//
//  BCCategory.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
#import "BCCategoryDataSource.h"

typedef enum BCCategoryType {
    BCCategoryTypeUnknown = 0,
    BCCategoryTypeBlueCats = 1,
    BCCategoryTypeTeam = 2
} BCCategoryType;

@interface BCCategory : BCJSONModel <NSCopying, BCCustomValueDataSource>

@property (nonatomic, copy) NSString *categoryID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSNumber *categoryTypeID;
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, assign) BCCategoryType categoryType;
@property (nonatomic, copy) NSArray *customValues;

- (void)numberOfVisitsTodayWithSuccess:(void (^)(NSUInteger visitCount))success
                               failure:(void (^)(NSError *error))failure;

- (void)numberOfVisitsYesterdayWithSuccess:(void (^)(NSUInteger visitCount))success
                                   failure:(void (^)(NSError *error))failure;

- (void)numberOfVisitsThisWeekWithSuccess:(void (^)(NSUInteger visitCount))success
                                  failure:(void (^)(NSError *error))failure;

- (void)numberOfVisitsLastWeekWithSuccess:(void (^)(NSUInteger visitCount))success
                                  failure:(void (^)(NSError *error))failure;

- (void)numberOfVisitsThisMonthWithSuccess:(void (^)(NSUInteger visitCount))success
                                   failure:(void (^)(NSError *error))failure;

- (void)numberOfVisitsLastMonthWithSuccess:(void (^)(NSUInteger visitCount))success
                                   failure:(void (^)(NSError *error))failure;

- (void)numberOfVisitsSinceDate:(NSDate *)date
                        success:(void (^)(NSUInteger visitCount))success
                        failure:(void (^)(NSError *error))failure;

- (void)numberOfVisitsUntilDate:(NSDate *)date
                        success:(void (^)(NSUInteger visitCount))success
                        failure:(void (^)(NSError *error))failure;

- (void)numberOfVisitsFromDate:(NSDate *)startDate untilDate:(NSDate *)endDate
                       success:(void (^)(NSUInteger visitCount))success
                       failure:(void (^)(NSError *error))failure;

@end

