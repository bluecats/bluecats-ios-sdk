//
//  BCCategory.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

typedef enum BCCategoryType {
    BCCategoryTypeUnknown = 0,
    BCCategoryTypeBlueCats = 1,
    BCCategoryTypeTeam = 2
} BCCategoryType;

@interface BCCategory : BCJSONModel <NSCopying>

@property (nonatomic, copy) NSString *categoryID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSNumber *categoryTypeID;
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, assign) BCCategoryType categoryType;
@property (nonatomic, copy) NSArray *customValues;

- (NSUInteger)numberOfVisitsToday;
- (NSUInteger)numberOfVisitsYesterday;
- (NSUInteger)numberOfVisitsThisWeek;
- (NSUInteger)numberOfVisitsLastWeek;
- (NSUInteger)numberOfVisitsThisMonth;
- (NSUInteger)numberOfVisitsLastMonth;
- (NSUInteger)numberOfVisitsSinceDate:(NSDate *)date;
- (NSUInteger)numberOfVisitsUntilDate:(NSDate *)date;
- (NSUInteger)numberOfVisitsFromDate:(NSDate *)startDate untilDate:(NSDate *)endDate;

@end

