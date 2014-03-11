//
//  BlueCats.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

@interface BlueCatsSDK : NSObject

+ (void)setOptions:(NSDictionary*)options;

+ (void)startPurring;
+ (void)startPurringWithAppToken:(NSString *)appToken;

+ (void)stopPurring;

+ (void)setAppToken:(NSString *)appToken;
+ (void)setCredentialsWithUserName:(NSString *)userName password:(NSString *)password;

@end

extern NSString* const BCOptionUseStageApi;
extern NSString* const BCOptionBeaconVisitTrackingEnabled;
extern NSString* const BCOptionMonitorBlueCatsRegionOnStartup;
extern NSString* const BCOptionMonitorAllAvailableRegionsOnStartup;

