//
//  BCMap.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/8/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

@class BCResource;

///The `BCMap` class defines a object that represents a map or floor plan. BlueCats maps reside underneath sites in the hierarchy and can be used to organize beacons according to their relative location in a space or one anther.
@interface BCMap : BCJSONModel<NSCopying>

///@name Properties

///The resource ID.
@property (nonatomic, copy) NSString *mapID;
///The map name.
@property (nonatomic, copy) NSString *name;
///The ID of the site.
@property (nonatomic, copy) NSString *siteID;
///The BCResource of the map. BCResource is used to store additional data.
@property (nonatomic, strong) BCResource *mapResource;
///The number of map points on the map. This resembles the number of beacons placed on the map.
@property (nonatomic, assign) NSInteger mapPointCount;
///The size of the map in the x plane.
@property (nonatomic, copy) NSNumber *scaleX;
///The size of the map in the y plane.
@property (nonatomic, copy) NSNumber *scaleY;
///The absolute X coordinate of the top left corner of the map.
@property (nonatomic, copy) NSNumber *scaleMarkerAx;
///The absolute Y coordinate of the top left corner of the map.
@property (nonatomic, copy) NSNumber *scaleMarkerAy;
///The absolute X coordinate of the right of the map.
@property (nonatomic, copy) NSNumber *scaleMarkerBx;
///The absolute Y coordinate of the bottom of the map.
@property (nonatomic, copy) NSNumber *scaleMarkerBy;

@end
