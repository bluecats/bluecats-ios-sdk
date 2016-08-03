//
//  BCMapPoint.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/8/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

@class BCPoint;

///The BCMapPoint class defines an object that represents a single location on a BCMap.
@interface BCMapPoint : BCJSONModel<NSCopying>

///@name Properties

///The map point resource ID.
@property (nonatomic, copy) NSString *mapPointID;
///The map resource ID.
@property (nonatomic, copy) NSString *mapID;
///The name of the map the map point is on.
@property (nonatomic, copy) NSString *mapName;
///The BCPoint (x,y-coordinates) of the map point object.
@property (nonatomic, copy) BCPoint *point;
///The last date the map point was modified.
@property (nonatomic, copy) NSDate *modifiedAt;

@end
