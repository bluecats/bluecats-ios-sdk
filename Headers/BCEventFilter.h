//
//  BCEventFilter.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 1/07/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCBeacon.h"

@class BCEvent,BCEventFilterContext;

@protocol BCEventFilter <NSObject>

- (NSArray *) filterBeaconsForEvent:(BCEventFilterContext *)eventContext;

@optional

- (BOOL) shouldApplyFilterWhenNoBeaconsRemaining;

@end

@protocol BCEventFilterDefinition <NSObject>

- (NSString *) filterKey;

@optional

- (NSDictionary *) params;

@end

@protocol BCEventFilterResolver <NSObject>

- (id<BCEventFilter>) resolveFilterFromDefinition:(id<BCEventFilterDefinition>)filterDefinition;

@end

@interface BCEventFilter : NSObject <BCEventFilter>

@property (copy) NSArray* (^FilterBeaconsForEventBlock)(BCEventFilterContext*, NSMutableDictionary*);
@property (copy) BOOL (^ShouldApplyFilterWhenNoBeaconsRemainingBlock)(void);

+(id<BCEventFilter>)filterByPredicate:(NSPredicate*)predicate;
+(id<BCEventFilter>)filterByIDs:(NSArray *)beaconIDs;
+(id<BCEventFilter>)filterByProximity:(BCProximity)proximity;
+(id<BCEventFilter>)filterByProximities:(NSArray*)proximities;
+(id<BCEventFilter>)filterByAccuracyRangeFrom:(double)fromAccuracy to:(double)toAccuracy;
+(id<BCEventFilter>)filterByCategoriesNamed:(NSArray *)categoryNames;
+(id<BCEventFilter>)filterByCategoriesWithIDs:(NSArray *)categoryIDs;
+(id<BCEventFilter>)filterBySitesNamed:(NSArray *)siteNames;
+(id<BCEventFilter>)filterBySitesWithIDs:(NSArray *)siteIDs;
+(id<BCEventFilter>)filterBySitesWithPredicate:(NSPredicate*)sitePredicate;
+(id<BCEventFilter>)filterByMinTimeIntervalBeaconMatched:(NSTimeInterval)minTimeIntervalMatched allowingMaxTimeIntervalNotMatched:(NSTimeInterval)maxTimeIntervalNotMatched;
+(id<BCEventFilter>)filterByMinTimeIntervalBetweenBeaconMatches:(NSTimeInterval)minTimeIntervalBetweenMatches;
+(id<BCEventFilter>)filterByMinTimeIntervalBetweenTriggers:(NSTimeInterval)minTimeIntervalBetweenTriggers;
+(id<BCEventFilter>)filterByClosestBeacon;
+(id<BCEventFilter>)filterByClosestBeaconChanged;
+(id<BCEventFilter>)filterApplySmoothedAccuracyOverTimeInterval:(NSTimeInterval)timeInterval;
+(id<BCEventFilter>)filterApplySmoothedRSSIOverTimeInterval:(NSTimeInterval)timeInterval;
+(id<BCEventFilter>)filterByEnteredBeaconResetAfterTimeIntervalUnmatched:(NSTimeInterval)minTimeUnmatchedBeforeReset;
+(id<BCEventFilter>)filterByEnteredAnyBeaconResetAfterTimeIntervalAllUnmatched:(NSTimeInterval)minTimeUnmatchedBeforeReset;
+(id<BCEventFilter>)filterByExitedBeaconAfterTimeIntervalUnmatched:(NSTimeInterval)minTimeIntervalUnmatched;
+(id<BCEventFilter>)filterByExitedAllBeaconsAfterTimeInterval:(NSTimeInterval)minTimeIntervalUnmatched;

@end


