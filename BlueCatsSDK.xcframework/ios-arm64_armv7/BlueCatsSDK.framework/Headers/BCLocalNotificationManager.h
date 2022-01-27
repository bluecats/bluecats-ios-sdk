//
//  BCLocalNotificationManager.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/21/13.
//  Copyright (c) 2013 BlueCats. All rights reserved.
//

@class BCLocalNotification;

NS_CLASS_AVAILABLE(NA, 7_0)

///The `BCLocalNotificationManager` class defines the central object that manages `BCLocalNotifications`.
@interface BCLocalNotificationManager : NSObject

///@name Getting the Shared Manager
/**
 *  Returns the the shared local notification manager.
 *
 *  @return The shared `BCLocalNotificationManager`.
 */
+ (BCLocalNotificationManager *)sharedManager;

///@name Getting Scheduled Local Notifications
/**
 *  Returns the array of scheduled local notifications.
 *
 *  @return The array of scheduled `BCLocalNotifications`.
 */
- (NSArray *)scheduledLocalNotifications;

///@name Scheduling Notifications
/**
 *  Adds the specified notification to the manager.
 *
 *  @param localNotification The `BCLocalNotification` to add to the manager.
 */
- (void)scheduleLocalNotification:(BCLocalNotification *)localNotification;

///@name Canceling Notifications
/**
 *  Removes the specified local notification from the manager.
 *
 *  @param localNotification The `BCLocalNotification` to cancel.
 */
- (void)cancelLocalNotification:(BCLocalNotification *)localNotification;
///Cancels all local the manager's local notifications.
- (void)cancelAllLocalNotifications;

@end

extern NSString * const BCLocalNotificationManagerDidChangeLocalNotifications;
extern NSString * const BCLocalNotificationManagerDidPresentLocalNotification;

extern NSString * const BCLocalNotificationManagerLocalNotificationItem;