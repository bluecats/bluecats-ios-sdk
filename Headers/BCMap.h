//
//  BCMap.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/8/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

@class BCResource;

@interface BCMap : BCJSONModel<NSCopying>

@property (nonatomic, copy) NSString *mapID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *siteID;
@property (nonatomic, strong) BCResource *mapResource;
@property (nonatomic, assign) NSInteger mapPointCount;
@property (nonatomic, copy) NSNumber *scaleX;
@property (nonatomic, copy) NSNumber *scaleY;
@property (nonatomic, copy) NSNumber *scaleMarkerAx;
@property (nonatomic, copy) NSNumber *scaleMarkerAy;
@property (nonatomic, copy) NSNumber *scaleMarkerBx;
@property (nonatomic, copy) NSNumber *scaleMarkerBy;

@end
