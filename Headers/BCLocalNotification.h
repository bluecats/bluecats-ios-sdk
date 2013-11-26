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

@interface BCLocalNotification : NSObject

@property (nonatomic, copy) BCSite *fireInSite;
@property (nonatomic, copy) NSArray *fireInCategories;
@property (nonatomic, assign) BCProximity fireInProximity;
@property (nonatomic, copy) NSDate *fireAfter;
@property (nonatomic, copy) NSTimeZone *timeZone;
@property (nonatomic, copy) NSString *alertBody;
@property (nonatomic, copy) NSString *alertAction;
@property (nonatomic, copy) NSString *alertLaunchImage;
@property (nonatomic, copy) NSString *soundName;
@property(nonatomic,copy) NSDictionary *userInfo;

@end
