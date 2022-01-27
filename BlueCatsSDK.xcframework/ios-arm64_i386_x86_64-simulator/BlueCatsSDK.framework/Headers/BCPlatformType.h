//
//  BCPlatformType.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/2/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
#import <Foundation/Foundation.h>

@interface BCPlatformType : BCJSONModel

@property (nonatomic, assign) NSInteger platformTypeID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *displayName;

@end


extern NSInteger const BCPlatformTypeIDIOS;
extern NSInteger const BCPlatformTypeIDAndroid;