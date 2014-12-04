//
//  BCMapPoint.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/8/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

@class BCPoint;

@interface BCMapPoint : BCJSONModel<NSCopying>

@property (nonatomic, copy) NSString *mapPointID;
@property (nonatomic, copy) NSString *mapID;
@property (nonatomic, copy) NSString *mapName;
@property (nonatomic, copy) BCPoint *point;
@property (nonatomic, copy) NSDate *modifiedAt;

@end
