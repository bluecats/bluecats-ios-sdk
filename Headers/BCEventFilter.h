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

- (NSString *) filterIdentifier;

@optional

- (NSDictionary *) params;

@end

@protocol BCEventFilterResolver <NSObject>

- (id<BCEventFilter>) resolveFilterFromDefinition:(id<BCEventFilterDefinition>)filterDefinition;

@end

@interface BCEventFilter : NSObject <BCEventFilter>

@property (copy) NSArray* (^FilterBeaconsForEventBlock)(BCEventFilterContext*, NSMutableDictionary*);
@property (copy) BOOL (^ShouldApplyFilterWhenNoBeaconsRemainingBlock)(void);

/*!
 * @discussion Factory to create a filter to restrict ranged beacons using a predicate. 
    Beacons matching the predicate are passed to subsequent filters.
 * @param predicate The predicate used to filter each ranged beacon.
 * @return filter
 */
+(id<BCEventFilter>)filterByPredicate:(NSPredicate*)predicate;

/*!
 * @discussion Factory to create a filter to restrict ranged beacons by an array of beaconIDs. 
    Only beacons with IDs in this list are passed to subsequent filters.
 * @param beaconIDs array of beaconIDs used to restrict matching beacons
 * @return filter
 */
+(id<BCEventFilter>)filterByIDs:(NSArray *)beaconIDs;

/*!
 * @discussion Factory to create a filter to restrict ranged beacons by a single proximity
    BCProximityImmediate, BCProximityNear or BCProximityFar. Only beacons in this proximity 
    are passed to subsequent filters.
 * @param proximity BCProximity enum value to match
 * @return filter
 */
+(id<BCEventFilter>)filterByProximity:(BCProximity)proximity;


/*!
 * @discussion Factory to create a filter to restrict ranged beacons that have a custom value matching a
    specific key and value.
 * @param custom value key to match
 * @param array of values of possible matches
 * @return filter
 */
+ (id <BCEventFilter>)filterBeaconsWithCustomValuesWithKey:(NSString *)key
                                                 andValues:(NSArray *)values;

/*!
 * @discussion Factory to create a filter to restrict ranged beacons that have a category with 
 a custom value matching a specific key and value.
 * @param custom value key to match
 * @param array of values of possible matches
 * @return filter
 */
+ (id <BCEventFilter>)filterByCategorieswithCustomValuesWithKey:(NSString *)key
                                                      andValues:(NSArray *)values;

/*!
 * @discussion Factory to create a filter to restrict ranged beacons by multiple proximities
    BCProximityImmediate, BCProximityNear or BCProximityFar. Only beacons any of these proximities
    are passed to subsequent filters.
 * @param proximities array of BCProximity enum values to match
 * @return filter
 */
+(id<BCEventFilter>)filterByProximities:(NSArray*)proximities;
+(id<BCEventFilter>)filterByAccuracyRangeFrom:(double)fromAccuracy to:(double)toAccuracy;
+(id<BCEventFilter>)filterByCategoriesNamed:(NSArray *)categoryNames;
+(id<BCEventFilter>)filterByCategoriesWithIDs:(NSArray *)categoryIDs;
+(id<BCEventFilter>)filterByCustomValuesWithKeys:(NSArray *)customValueKeys;
+(id<BCEventFilter>)filterByCategoriesWithCustomValueKeys:(NSArray *)keys;
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

+(id<BCEventFilter>)filterByReassembledBlockDataWithDataType:(BCBlockDataType)dataType;
+(id<BCEventFilter>)filterByNeverEnteredBeacon;
@end


