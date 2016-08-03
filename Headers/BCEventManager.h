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

///These constants indicate the priority level of the event. The priority level of the event relates to how quickly the event is posted to the BC API.  See the `logEvent:withPriority:` method.
typedef enum {
    ///An event of normal priority. Posted to the BC API during the next posting event (a high priority event occurs or the app state changes.)
    BCEventPriorityNormal = 0,
    ///A event of high priority. Posted quickly to the BC API.
    BCEventPriorityHigh = 1
} BCEventPriority;
 
///The `BCEventManager` is the central point for managing triggers and events. The `BCEventManager` can also be used to log events to the BlueCats API.
@interface BCEventManager : NSObject

///@name Accessing the Delegate

///The delegate object to receive update events.
@property (nonatomic, weak) NSObject<BCEventManagerDelegate> *delegate;

- (instancetype)initWithDelegate:(id)delegate queue:(dispatch_queue_t)queue;

///@name Custom Device Identification

///The default custom device identifier.
@property (nonatomic, strong) NSString *defaultCustomDeviceIdentifier;

///@name Getting Monitored Events
/**
 *  Returns an NSArray of all monitored event identifiers.
 *
 *  @return An array of strings containing the identifiers of monitored events.
 */
- (NSArray *)allMonitoredEventIdentifiers;

///@name Adding an Events to the Monitor
/**
 *  Adds a BCTrigger to the event manager. This method will reset the trigger count to 0 by default.
 *
 *  @param trigger The BCTrigger object you wish to add to the event manager.
 */
- (void)monitorEventWithTrigger:(BCTrigger*)trigger;
/**
 *  Adds a BCTrigger to the event manager with a block object to be executed when the trigger is fired. This method will reset the trigger count to 0 by default.
 *
 *  @param trigger      The BCTrigger object you wish to add to the event manager.
 *  @param eventHandler The block object to be executed when the trigger is fired.
 *
 *  The block has no return value and takes one argument:
 *
 *  `triggered event` | The triggered event.
 */
- (void)monitorEventWithTrigger:(BCTrigger*)trigger eventHandler:(void (^)(BCTriggeredEvent*))eventHandler;
/**
 *  Adds a BCTrigger to the BCEventManager with the option to restore the triggered count.
 *
 *  @param trigger               The BCTrigger object you wish to add to the event manager.
 *  @param restoreTriggeredCount YES: restore the trigger count from cache.  NO: reset the trigger count to 0.
 */
- (void)monitorEventWithTrigger:(BCTrigger*)trigger restoreTriggeredCount:(BOOL)restoreTriggeredCount;
/**
 *  Adds a BCTrigger to the BCEventManager with a block object to be executed when the trigger is fired and the option to restore the triggered count.
 *
 *  @param trigger               The BCTrigger object you wish to add to the event manager.
 *  @param restoreTriggeredCount YES: restore the trigger count from cache.  NO: reset the trigger count to 0.
 *  @param eventHandler          The block object to be executed when the trigger is fired.
 *
 *  The block has no return value and takes one argument:
 *
 *  `triggered event` | The triggered event.
 */
- (void)monitorEventWithTrigger:(BCTrigger*)trigger restoreTriggeredCount:(BOOL)restoreTriggeredCount eventHandler:(void (^)(BCTriggeredEvent*))eventHandler;

///@name Removing Events
/**
 *  Removes the specified monitored event from the BCEventManager.
 *
 *  @param eventIdentifier The event identifier for the monitored event you wish to remove from the event manager.
 */
- (void)removeMonitoredEvent:(NSString*)eventIdentifier;
///Removes all monitored events from the BCEventManager.
- (void)removeAllMonitoredEvents;

///@name Logging Events
/**
 *  Adds an BCEvents to a log.
 *
 *  This method can be used to send a BCEvent log to the BlueCats API.  Events with high priority are added to the begging of the log array and events with normal priority are added to the array in the order they are received.
 *
 *  Logs are posted under the following conditions:
 *  1. The first time this is called the event will be posted immediately.  
 *  2. If the event is of high priority and an event hasn't been posted in the last ten seconds the log is posted.
 *  3. If an event is of normal priority and the log hasn't been posted in the last sixty seconds the log is posted.
 *
 *  Additionally, logs are posted under the following conditions:
 *
 *  -when the class is deallocated
 *  -on `applicationDidBecomeActive`
 *  -when the application launches with un-posted events present in local store
 *
 *  @param event    The event object.
 *  @param priority The priority of the event.
 */
- (void)logEvent:(BCEvent*)event withPriority:(BCEventPriority)priority;

///@name Getting the Shared Manager
/**
 *  Returns a shared `BCEventManager`.
 *
 *  Use this method to return the shared manager for a subsequent call.
 *
 *  @return The shared event manager.
 */
+ (BCEventManager *)sharedManager;

@end

extern NSString * const BCEventManagerTriggeredEvent;
extern NSString * const BCEventManagerTriggeredEventItem;

///The `BCEventManagerDelegate` protocol defines the methods used to receive location updates from a event manager object.
@protocol BCEventManagerDelegate <NSObject>

@optional

///@name Optional Delegate Methods
/**
 *  Tells the delegate that an event has fired.
 *
 *  @param eventManager   The event manager
 *  @param triggeredEvent The triggered event.
 */
- (void)eventManager:(BCEventManager*)eventManager
      triggeredEvent:(BCTriggeredEvent*)triggeredEvent;

@end

