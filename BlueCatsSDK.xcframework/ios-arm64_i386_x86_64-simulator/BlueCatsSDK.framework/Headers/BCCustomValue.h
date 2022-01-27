//
//  BCCustomValue.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 9/19/14.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"

///The `BCCustomValue` class defines an object that represents a custom value.  Beacons, categories and sites can have custom values.
@interface BCCustomValue : BCJSONModel <NSCopying>

///@name Properties

///The resource ID.
@property (nonatomic, copy) NSString *customValueID;
///The key of the custom value.
@property (nonatomic, copy) NSString *key;
///The value of the custom value.
@property (nonatomic, copy) NSString *value;

@end

@protocol BCCustomValue
@end