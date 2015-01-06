//
//  BCLocalNotificationManager.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/21/13.
//  Copyright (c) 2013 BlueCats. All rights reserved.
//

@class BCLocalNotification;

NS_CLASS_AVAILABLE(NA, 7_0)
@interface BCLocalNotificationManager : NSObject

+ (BCLocalNotificationManager *)sharedManager;

- (NSArray *)scheduledLocalNotifications;

- (void)scheduleLocalNotification:(BCLocalNotification *)localNotification;

- (void)cancelLocalNotification:(BCLocalNotification *)localNotification;

- (void)cancelAllLocalNotifications;

@end

extern NSString * const BCLocalNotificationManagerDidChangeLocalNotifications;
extern NSString * const BCLocalNotificationManagerDidPresentLocalNotification;

extern NSString * const BCLocalNotificationManagerLocalNotificationItem;