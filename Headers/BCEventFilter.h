//
//  BCEventFilter.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 1/07/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCDefinitions.h"

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

///The `BCEventFilter` class defines an object that represents a macro-location filter. `BCEventFilters` can be combined to trigger actions in micro-locations and/or particular conditions are met.
@interface BCEventFilter : NSObject <BCEventFilter>

///@name Block Properties

///A block property that takes a event filter context and `NSMutableDictionary` to define a context for the `BCEventFilter`.
@property (copy) NSArray* (^FilterBeaconsForEventBlock)(BCEventFilterContext*, NSMutableDictionary*);
///A block property with no parameters defining whether a filter should apply when no beacons are remaining. `YES` if the filter should apply when no beacons are remaining; `NO` if the filter should not apply. Defaults to `NO`.
@property (copy) BOOL (^ShouldApplyFilterWhenNoBeaconsRemainingBlock)(void);

///@name Creating a Filter
/**
 *  Returns a `BCEventFilter` that is restricted by the specified predicate.
 *
 *  @param predicate The predicate condition to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByPredicate:(NSPredicate*)predicate;
/**
 *  Returns a `BCEventFilter` that is satisfied by any of the specified beacon IDs.
 *
 *  @param beaconIDs The array of beacon IDs to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByIDs:(NSArray *)beaconIDs;
/**
 *  Returns a `BCEventFilter` object is satisfied by a single proximity.
 *
 *  @param proximity The BCProximity that the beacons must be within.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByProximity:(BCProximity)proximity;
/**
 *  Returns a `BCEventFilter` object that is satisfied by a range of proximities.
 *
 *  @param proximities The array of proximities to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByProximities:(NSArray*)proximities;
/**
 *  Returns a `BCEventFilter` object that is satisfied by beacons with the specified key and values.
 *
 *  @param key    The custom value key to filter by.
 *  @param values The array of values to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterBeaconsWithCustomValuesWithKey:(NSString *)key
                                                 andValues:(NSArray *)values;
/**
 *  Returns a `BCEventFilter` object that is satisfied by categories with the specified key and values.
 *
 *  @param key    The custom value key filter by.
 *  @param values The array of values to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByCategorieswithCustomValuesWithKey:(NSString *)key
                                                      andValues:(NSArray *)values;
/**
 *  Returns a `BCEventFilter` object that is satisfied by the specified accuracy range.
 *
 *  @param fromAccuracy The first limit.
 *  @param toAccuracy   The second limit.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByAccuracyRangeFrom:(double)fromAccuracy to:(double)toAccuracy;
/**
 *  Returns a `BCEventFilter` object that is satisfied when any of the specified categories are ranged.
 *
 *  @param categoryNames The array of category names to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByCategoriesNamed:(NSArray *)categoryNames;
/**
 *  Returns a `BCEventFilter` object that is satisfied by the specified category IDs.
 *
 *  @param categoryIDs The array of category IDs to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByCategoriesWithIDs:(NSArray *)categoryIDs;
/**
 *  Returns a `BCEventFilter` object that is satisfied by any of the specified custom value keys.
 *
 *  @param customValueKeys The array of custom value keys to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByCustomValuesWithKeys:(NSArray *)customValueKeys;
/**
 *  Returns a `BCEventFilter` object that is satisfied by categories with any of the specified custom value keys.
 *
 *  @param keys The array of custom value keys to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByCategoriesWithCustomValueKeys:(NSArray *)keys;
/**
 *  Returns a `BCEventFilter` object that is satisfied by any of the specified site names.
 *
 *  @param siteNames The array of site names to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterBySitesNamed:(NSArray *)siteNames;
/**
 *  Returns a `BCEventFilter` object that is satisfied when the current site is within a list of sites.
 *
 *  @param siteIDs The array of site IDs to filter by.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterBySitesWithIDs:(NSArray *)siteIDs;
/**
 *  Returns a `BCEventFilter` object that is satisfied by the specified predicate.
 *
 *  @param sitePredicate The predicate condition.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterBySitesWithPredicate:(NSPredicate*)sitePredicate;
/**
 *  Returns a `BCEventFilter` object that is satisfied when beacons have been ranged for a minimum amount of time, but not more than the maximum amount of time.
 *
 *  @param minTimeIntervalMatched    The minimum time interval.
 *  @param maxTimeIntervalNotMatched The maximum time interval.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByMinTimeIntervalBeaconMatched:(NSTimeInterval)minTimeIntervalMatched allowingMaxTimeIntervalNotMatched:(NSTimeInterval)maxTimeIntervalNotMatched;
/**
 *  Returns a `BCEventFilter` object that can be used to set the minimum time interval between beacon matches.
 *
 *  @param minTimeIntervalBetweenMatches The minimum time interval.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByMinTimeIntervalBetweenBeaconMatches:(NSTimeInterval)minTimeIntervalBetweenMatches;
/**
 *  Returns a `BCEventFilter` object that is satisfied if the amount of time between the current time the last triggered event is greater than the specified minimum delay interval.
 *
 *  @param minTimeIntervalBetweenTriggers The minimum time interval since the last event.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByMinTimeIntervalBetweenTriggers:(NSTimeInterval)minTimeIntervalBetweenTriggers;
/**
 *  Returns a `BCEventFilter` object that will only return the closest beacon when the filter is satisfied.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByClosestBeacon;
/**
 *  Returns a `BCEventFilter` object that is satisfied whenever the closest beacon changes.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByClosestBeaconChanged;
/**
 *  Returns a `BCEventFilter` object that smooths the accuracy value used in filters over the specified time interval.
 *
 *  @param timeInterval The time interval in seconds.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterApplySmoothedAccuracyOverTimeInterval:(NSTimeInterval)timeInterval;
/**
 *  Returns a `BCEventFilter` object that smooths the RSSI value used in filters over the specified time interval.
 *
 *  @param timeInterval The time interval.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterApplySmoothedRSSIOverTimeInterval:(NSTimeInterval)timeInterval;
/**
 *  Returns a `BCEventFilter` object that is satisfied when the device enters a beacon that has not been ranged since the specified time interval.
 *
 *  @param minTimeUnmatchedBeforeReset The minimum time interval between matchings.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByEnteredBeaconResetAfterTimeIntervalUnmatched:(NSTimeInterval)minTimeUnmatchedBeforeReset;
/**
 *  Returns a `BCEventFilter` object that is satisfied when the device enters any in the filter context since the specified amount of time has passed since ranging any beacon in the filter context.
 *
 *  @param minTimeUnmatchedBeforeReset The minimum amount of time between filter resets.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByEnteredAnyBeaconResetAfterTimeIntervalAllUnmatched:(NSTimeInterval)minTimeUnmatchedBeforeReset;
/**
 *  Returns a `BCEventFilter` object that is satisfied when the device exits the range of beacon after it has not been ranged for the specified amount of time.
 *
 *  @param minTimeIntervalUnmatched The minimum amount of time since the beacon was last ranged.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByExitedBeaconAfterTimeIntervalUnmatched:(NSTimeInterval)minTimeIntervalUnmatched;
/**
 *  Returns a `BCEventFilter` object that is satisfied when the device has exited the range of all beacons in the filter context for the specified minimum time interval.
 *
 *  @param minTimeIntervalUnmatched The minimum time interval for which a beacon has not been discovered.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByExitedAllBeaconsAfterTimeInterval:(NSTimeInterval)minTimeIntervalUnmatched;
/**
 *  Returns a `BCEventFilter` object that is satisfied whenever data is reassembled with the specified data type.
 *
 *  @param dataType The BCBlockDataType
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByReassembledBlockDataWithDataType:(BCBlockDataType)dataType;
/**
 *  Returns a `BCEventFilter` object that is satisfied when no beacons were ranged.
 *
 *  @return A `BCEventFilter` object initialized with the specified parameter.
 */
+(id<BCEventFilter>)filterByNeverEnteredBeacon;
@end


