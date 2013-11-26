//
//  BlueCats.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

@interface BlueCatsSDK : NSObject

+ (void)setOptions:(NSDictionary*)options;

+ (void)setAppToken:(NSString *)appToken;

+ (void)startPurring;

+ (void)startPurringWithAppToken:(NSString *)appToken;

+ (void)stopPurring;

+ (void)makeYourMarkWithKey:(NSString *)key value:(NSString *)value;

@end

extern NSString* const BCOptionUseStageApi;
extern NSString* const BCOptionBeaconVisitTrackingEnabled;

