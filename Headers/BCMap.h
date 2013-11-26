//
//  BCMap.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/8/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

@class BCResource;

@interface BCMap : NSObject

@property (nonatomic, copy) NSString *mapID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, strong) BCResource *mapResource;
@property (nonatomic, copy) NSDate *createdAt;
@property (nonatomic, copy) NSString *createdBy;
@property (nonatomic, assign) NSInteger mapPointCount;

@end
