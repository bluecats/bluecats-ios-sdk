//
//  BCMap.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/8/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

@interface BCMap : NSObject

@property (nonatomic, copy) NSString *mapID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, copy) NSString *mapImageURL;
@property (nonatomic, copy) NSDate *modifiedAt;
@property (nonatomic, assign) NSInteger mapPointCount;

@end
