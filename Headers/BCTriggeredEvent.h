//
//  BCTriggeredEvent.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 1/07/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCEvent.h"
#import "BCTrigger.h"
#import "BCMicroLocation.h"

typedef enum {
    BCTriggerStateIncomplete = 0,
    BCTriggerStateTriggered,
    BCTriggerStateExpired
} BCTriggerState;

@interface BCTriggeredEvent : NSObject<NSCopying>

@property (nonatomic, copy) BCEvent *event;
@property (nonatomic, copy) BCMicroLocation *filteredMicroLocation;
@property (nonatomic, assign) BCTriggerState triggerState;
@property (nonatomic, assign) NSInteger triggeredCount;
@property (nonatomic, copy) NSDate *firstTriggeredAt;
@property (nonatomic, copy) NSDate *lastTriggeredAt;

@end
