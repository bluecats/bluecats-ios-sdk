//
//  BCLocalNotificationManager.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/21/13.
//  Copyright (c) 2013 BlueCats. All rights reserved.
//

@class BCLocalNotification;

@interface BCLocalNotificationManager : NSObject

+ (BCLocalNotificationManager *)sharedManager;

- (NSArray *)scheduledLocalNotifications;

- (void)scheduleLocalNotification:(BCLocalNotification *)localNotification;

- (void)cancelLocalNotification:(BCLocalNotification *)localNotification;

- (void)cancelAllLocalNotifications;

@end

extern NSString * const BCLocalNotificationManagerDidChangeLocalNotifications;