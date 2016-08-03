//
//  BCBeacon+Analytics.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 11/15/15.
//  Copyright © 2015 BlueCats. All rights reserved.
//

#import "BCBeacon.h"

@interface BCBeacon (Analytics)

//@name Analytics Methods
/**
 *  Issues an asynchronous request to get the number of visits to the beacon for the current day with success and failure blocks.
 *
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
- (void)numberOfVisitsTodayWithSuccess:(void (^)(NSUInteger visitCount))success
                               failure:(void (^)(NSError *error))failure;
/**
 *  Issues an asynchronous request to get the number of visits to the beacon for the previous day with success and failure blocks.
 *
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
- (void)numberOfVisitsYesterdayWithSuccess:(void (^)(NSUInteger visitCount))success
                                   failure:(void (^)(NSError *error))failure;
/**
 *  Issues an asynchronous request to get the number of visits to the beacon for the current week with success and failure blocks.
 *
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
- (void)numberOfVisitsThisWeekWithSuccess:(void (^)(NSUInteger visitCount))success
                                  failure:(void (^)(NSError *error))failure;
/**
 *  Issues an asynchronous request to get the number of visits to the beacon for the previous week with success and failure blocks.
 *
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */- (void)numberOfVisitsLastWeekWithSuccess:(void (^)(NSUInteger visitCount))success
                                  failure:(void (^)(NSError *error))failure;
/**
 *  Issues an asynchronous request to get the number of visits to the beacon for the current month with success and failure blocks.
 *
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
- (void)numberOfVisitsThisMonthWithSuccess:(void (^)(NSUInteger visitCount))success
                                   failure:(void (^)(NSError *error))failure;
/**
 *  Issues an asynchronous request to get the number of visits to the beacon for the previous month with success and failure blocks.
 *
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
- (void)numberOfVisitsLastMonthWithSuccess:(void (^)(NSUInteger visitCount))success
                                   failure:(void (^)(NSError *error))failure;
/**
 *  Issues an asynchronous request to get the number of visits to the beacon since the specified date with success and failure blocks.
 *
 *  @param date    The date from which to determine the number of beacon visits.
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
- (void)numberOfVisitsSinceDate:(NSDate *)date
                        success:(void (^)(NSUInteger visitCount))success
                        failure:(void (^)(NSError *error))failure;
/**
 *  Issues an asynchronous request to get the number of visits to the beacon until the specified date with success and failure blocks.
 *
 *  @param date    The date up until which to determine the number of beacon visits.
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
- (void)numberOfVisitsUntilDate:(NSDate *)date
                        success:(void (^)(NSUInteger visitCount))success
                        failure:(void (^)(NSError *error))failure;
/**
 *  Issues an asynchronous request to get the number of visits to the beacon between the specified dates with success and failure blocks.
 *
 *  @param startDate The initial date from which to determine the number of beacon visits.
 *  @param endDate   The final date from which to determine the number of beacon visits.
 *  @param success The block object to be executed when the request operation finishes successfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `visitCount` | The number of visits.
 *
 *  @param failure The block object to be executed when the task finishes unsuccessfully.
 *
 *  The block has no return value and takes one argument:
 *
 *  `error` | The error.
 */
- (void)numberOfVisitsFromDate:(NSDate *)startDate untilDate:(NSDate *)endDate
                       success:(void (^)(NSUInteger visitCount))success
                       failure:(void (^)(NSError *error))failure;

@end
