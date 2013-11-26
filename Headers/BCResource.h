//
//  BCResource.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 11/22/13.
//  Copyright (c) 2013 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BCResource : NSObject

@property (nonatomic, copy) NSString *resourceID;
@property (nonatomic, copy) NSString *URL;
@property (nonatomic, copy) NSString *secureURL;
@property (nonatomic, copy) NSString *publicID;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *format;
@property (nonatomic, copy) NSString *resourceType;
@property (nonatomic, copy) NSDate *createdAt;
@property (nonatomic, copy) NSString *createdBy;

@end
