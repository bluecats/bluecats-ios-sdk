//
//  BCEventManager.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 1/07/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCEvent.h"
#import "BCEventFilter.h"
#import "BCTrigger.h"
#import "BCTriggeredEvent.h"

@protocol BCEventManagerDelegate, BCEventFilter, BCEventFilterResolver;
@class BCTrigger, BCTriggeredEvent;

typedef enum {
    BCEventPriorityNormal = 0,
    BCEventPriorityHigh = 1
} BCEventPriority;

@interface BCEventManager : NSObject

@property (nonatomic, assign) NSObject<BCEventManagerDelegate> *delegate;
@property (nonatomic, strong) NSString* defaultCustomDeviceIdentifier;

- (NSArray *) allMonitoredEventIdentifiers;

/**
 *  these two methods reset the trigger count to 0 by default
 *
 *  @param trigger event trigger
 */
- (void) monitorEventWithTrigger:(BCTrigger*)trigger;
- (void) monitorEventWithTrigger:(BCTrigger*)trigger eventHandler:(void (^)(BCTriggeredEvent*))eventHandler;

/**
 *  monitor event with trigger with restore option
 *
 *  @param trigger event trigger
 *  @param restoreTriggeredCount   YES: restore the trigger count from cache    NO: reset the trigger count to 0
 */
- (void) monitorEventWithTrigger:(BCTrigger*)trigger restoreTriggeredCount:(BOOL)restoreTriggeredCount;
- (void) monitorEventWithTrigger:(BCTrigger*)trigger restoreTriggeredCount:(BOOL)restoreTriggeredCount eventHandler:(void (^)(BCTriggeredEvent*))eventHandler;

- (void) removeMonitoredEvent:(NSString*)eventIdentifier;
- (void) removeAllMonitoredEvents;

- (void) logEvent:(BCEvent*)event withPriority:(BCEventPriority)priority;
- (void) loadEventFiltersFromDictionary:(NSDictionary *)dictionary;

+ (BCEventManager *)sharedManager;

@end

extern NSString * const BCEventManagerTriggeredEvent;
extern NSString * const BCEventManagerTriggeredEventItem;

@protocol BCEventManagerDelegate <NSObject>

@optional

- (void)eventManager:(BCEventManager*)eventManager
      triggeredEvent:(BCTriggeredEvent*)triggeredEvent;

@end

