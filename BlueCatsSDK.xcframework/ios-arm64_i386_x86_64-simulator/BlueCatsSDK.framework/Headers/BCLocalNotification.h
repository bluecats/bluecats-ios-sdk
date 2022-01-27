//
//  BCLocalNotification.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/21/13.
//  Copyright (c) 2013 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCBeacon.h"

@class BCSite;

///The BCLocalNotification class defines a object that represents a beacon based local notification. It helps triggering beacon based local notifications easy. For more information, see the documentation for [`UILocalNotification`](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/) for further reference.
@interface BCLocalNotification : NSObject

///@name Beacon Properties

///The specified site in which to fire the local notification. This is optional.
@property (nonatomic, copy) BCSite *fireInSite;
///The array of specified categories in which to fire the local notification. At least one category is required to trigger the notification.
@property (nonatomic, copy) NSArray *fireInCategories;
///The specified BCProximity in which to fire the local notification. See BCProximity.
@property (nonatomic, assign) BCProximity fireInProximity;

///@name Notification Properties

///The date and time after when the notification becomes active. The notification still won't be displayed until a matching beacon is detected. This is optional and will be set to the current date and time if left `nil`. For more information see [UILocalNotification fireDate](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/#//apple_ref/occ/instp/UILocalNotification/fireDate).
@property (nonatomic, copy) NSDate *fireAfter;
///The time zone of the notification's fire date. For more information see [UILocalNotification timeZone](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/#//apple_ref/occ/instp/UILocalNotification/timeZone).
@property (nonatomic, copy) NSTimeZone *timeZone;
///The message displayed in the notification alert. For more information see [UILocalNotification alertBody](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/#//apple_ref/occ/instp/UILocalNotification/alertBody).
@property (nonatomic, copy) NSString *alertBody;
///The title of the action button or slider. For more information see [UILocalNotification alertAction](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/#//apple_ref/occ/instp/UILocalNotification/alertAction).
@property (nonatomic, copy) NSString *alertAction;
///Identifies the image used as the launch image when the user taps (or slides) the action button (or slider). For more information see [UILocalNotification alertLaunchImage](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/#//apple_ref/occ/instp/UILocalNotification/alertLaunchImage).
@property (nonatomic, copy) NSString *alertLaunchImage;
///The name of the file containing the sound to pay when an alert is displayed. For more information see [UILocalNotification soundName](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/#//apple_ref/occ/instp/UILocalNotification/soundName).
@property (nonatomic, copy) NSString *soundName;
///A dictionary for passing custom information to the notified app. For more information see [UILocalNotification userInfo](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/#//apple_ref/occ/instp/UILocalNotification/userInfo).
@property (nonatomic, copy) NSDictionary *userInfo;
/// `BOOL` value indicating if the badge number should increment with the notification. `YES` if the badge number should increment; `NO` if the badge number should not increment.
@property (nonatomic, assign) BOOL incrementBadgeNumber;
///The name of a group of actions to display in the alert. For more information see [UILocalNotification category](https://developer.apple.com/library/ios/documentation/iPhone/Reference/UILocalNotification_Class/#//apple_ref/occ/instp/UILocalNotification/category).
@property (nonatomic, copy) NSString *category;

@end
