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

- (void) monitorEventWithTrigger:(BCTrigger*)trigger;
- (void) removeMonitoredEvent:(NSString*)eventIdentifier;
- (void) removeAllMonitoredEvents;

- (void) logEvent:(BCEvent*)event withPriority:(BCEventPriority)priority;

+ (BCEventManager *)sharedManager;

@end

extern NSString * const BCEventManagerTriggeredEvent;
extern NSString * const BCEventManagerTriggeredEventItem;

@protocol BCEventManagerDelegate <NSObject>

@optional

- (void)eventManager:(BCEventManager*)eventManager
      triggeredEvent:(BCTriggeredEvent*)triggeredEvent;

@end

