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

@interface BCEventFilterContext : NSObject

@property (nonatomic, copy) NSArray* beaconsToFilter;
@property (nonatomic, copy) BCEvent* event;
@property (nonatomic, assign) BCTriggerState triggerState;
@property (nonatomic, assign) NSInteger triggeredCount;
@property (nonatomic, copy) NSDate *firstTriggeredAt;
@property (nonatomic, copy) NSDate *lastTriggeredAt;
@property (nonatomic, copy) NSDictionary* siteForSiteID;

@end
