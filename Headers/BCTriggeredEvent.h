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

///These constants indicate the state of a `BCTrigger` object.
typedef enum {
    ///The trigger is still valid, but has not been fired.
    BCTriggerStateIncomplete = 0,
    ///The trigger has fired.
    BCTriggerStateTriggered,
    ///The trigger has expired and can no longer fire.
    BCTriggerStateExpired
} BCTriggerState;

///The `BCTriggeredEvent` class defines an object that represents a triggered event.
@interface BCTriggeredEvent : NSObject<NSCopying>

///@name Event Filter Properties
///The event details `BCEvent`.
@property (nonatomic, copy) BCEvent *event;
///The filtered `BCMicroLocation` that satisfied the `BCTrigger`.
@property (nonatomic, copy) BCMicroLocation *filteredMicroLocation;
///The current trigger state.  See BCTriggerState.
@property (nonatomic, assign) BCTriggerState triggerState;
///The amount of times the trigger has fired.
@property (nonatomic, assign) NSInteger triggeredCount;
///The first date that the trigger was fired.
@property (nonatomic, copy) NSDate *firstTriggeredAt;
///The most recent date the trigger was fired.
@property (nonatomic, copy) NSDate *lastTriggeredAt;

@end
