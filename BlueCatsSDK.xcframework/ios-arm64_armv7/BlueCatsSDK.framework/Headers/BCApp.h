//
//  BCApp.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/2/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
@class BCPlatformType;

///The `BCApp` class defines an object that represents a mobile application.
@interface BCApp : BCJSONModel

///@name App Properties

///The resource ID.
@property (nonatomic, copy) NSString *appID;
///The team ID of the team containing the app.
@property (nonatomic, copy) NSString *teamID;
///The name of the app.
@property (nonatomic, copy) NSString *name;
///The iTunes URL of the app if provided.
@property (nonatomic, copy) NSString *iTunesURL;
///
@property (nonatomic, copy) NSString *packageName;
///The app platform type.
@property (nonatomic, strong) BCPlatformType *platformType;
///The app icon URL.
@property (nonatomic, copy) NSString *appIconURL;

@end
