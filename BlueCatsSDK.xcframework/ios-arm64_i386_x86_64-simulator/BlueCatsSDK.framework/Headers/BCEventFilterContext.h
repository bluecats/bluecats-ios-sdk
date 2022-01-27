//
//  BCEventFilterContext.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 4/07/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCEvent.h"
#import "BCTriggeredEvent.h"

///The `BCEventFilterContext` class defines an object that represents the context to apply to triggered event.
@interface BCEventFilterContext : NSObject

///@name Properties

///An array of beacons to filter.
@property (nonatomic, copy) NSArray* beaconsToFilter;
///The respective `BCEvent`.
@property (nonatomic, copy) BCEvent* event;
///The `BCTriggerState` of the `BCEvent`.
@property (nonatomic, assign) BCTriggerState triggerState;
///The number of times the event has been triggered.
@property (nonatomic, assign) NSInteger triggeredCount;
///The first date the event triggered.
@property (nonatomic, copy) NSDate *firstTriggeredAt;
///The last date the event triggered.
@property (nonatomic, copy) NSDate *lastTriggeredAt;
///A list of sites and their respective IDs that the event filter applies.
@property (nonatomic, copy) NSDictionary* siteForSiteID;

@end
