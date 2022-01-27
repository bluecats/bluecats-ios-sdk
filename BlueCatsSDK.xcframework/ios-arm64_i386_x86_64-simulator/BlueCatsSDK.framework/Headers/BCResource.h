//
//  BCResource.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 11/22/13.
//  Copyright (c) 2013 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"
#import <Foundation/Foundation.h>

///The `BCResource` class defines an object representing an resource used by the BlueCats SDK.
@interface BCResource : BCJSONModel<NSCopying>

///@name Properties

///The resource ID.
@property (nonatomic, copy) NSString *resourceID;
///The resource URL.
@property (nonatomic, copy) NSString *URL;
///The secure URL.
@property (nonatomic, copy) NSString *secureURL;
///The public ID.
@property (nonatomic, copy) NSString *publicID;
///The resource version.
@property (nonatomic, copy) NSString *version;
///The resource format.
@property (nonatomic, copy) NSString *format;
///The type of the resource.
@property (nonatomic, copy) NSString *resourceType;
///The date the resource was created.
@property (nonatomic, copy) NSDate *createdAt;
///The object that created the resource.
@property (nonatomic, copy) NSString *createdBy;

@end
