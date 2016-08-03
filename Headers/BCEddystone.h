//
//  BCEddystone.h
//  BlueCatsSDK
//
//  Created by Zach Prager on 9/2/15.
//  Copyright (c) 2015 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"

///The `BCEddystone` class defines an object that represents an Eddystone beacon.
@interface BCEddystone : BCJSONModel <NSCopying>

///@name General Properties

///The beacon's namespace ID.
@property (nonatomic, copy) NSString *namespaceID;
///The beacon's instance ID.
@property (nonatomic, copy) NSString *instanceID;
///The beacon's UID.
@property (nonatomic, copy) NSString *UIDString;

@property (nonatomic, copy) NSString *URLString;

@property (nonatomic, readonly, copy) NSURL *URL;

@end