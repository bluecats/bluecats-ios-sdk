//
//  BCCustomValue.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 9/19/14.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"

@interface BCCustomValue : BCJSONModel <NSCopying>

@property (nonatomic, copy) NSString *customValueID;
@property (nonatomic, copy) NSString *key;
@property (nonatomic, copy) NSString *value;

@end


@protocol BCCustomValue
@end