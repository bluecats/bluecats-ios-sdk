//
//  BCTrigger.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 1/07/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCEventFilter.h"

#pragma mark - BCTrigger interface

///The `BCTrigger` class defines an object representing an actionable trigger based on `BCEventFilters`.
@interface BCTrigger : NSObject<NSCopying>

///@name Properties

///The string name distinguishing the event.
@property (nonatomic, copy) NSString *eventIdentifier;
///The name of the event.
@property (nonatomic, copy) NSString *eventName;
///The amount of times the event will repeat.  The default value is 0 (will only fire once).
@property (nonatomic, assign) NSInteger repeatCount;
///The first date that the trigger is valid.
@property (nonatomic, copy) NSDate *validFrom;
///The date the trigger is no longer expired.
@property (nonatomic, copy) NSDate *expiresAt;
///The list of filters applied to the trigger.
@property (nonatomic, copy) NSDictionary *filterDescriptors;

///@name Initialization
/**
 *  Initialize a trigger with identifier and filters
 *
 *  @param identifier The string identifier of the Trigger
 *  @param filters    An array of filters applying to the trigger.
 *
 *  @return returns the Triggers ID if successful.
 */
- (id)initWithIdentifier:(NSString*) identifier andFilters:(NSArray*)filters;

///@name Adding a Filter
/**
 *  Adds a filter to a BCTrigger.
 *
 *  @param filter The `id` of the BCEventFilter to be added to the trigger.
 */
- (void)addFilter:(id<BCEventFilter>) filter;

///@name Clearing All Filters
///Clear the current filters on the trigger.
- (void)clearFilters;

///@name Getting All Filters
/**
 *  List all the filters on this trigger.
 *
 *  @return An array of all the filters on the BCTrigger object.
 */
- (NSArray *) allFilters;

@end
