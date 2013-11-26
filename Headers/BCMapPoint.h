//
//  BCMapPoint.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/8/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

@class BCPoint;

@interface BCMapPoint : NSObject <NSCopying>

@property (nonatomic, copy) NSString *mapPointID;
@property (nonatomic, copy) NSString *mapID;
@property (nonatomic, copy) BCPoint *point;
@property (nonatomic, copy) NSDate *modifiedAt;

@end
