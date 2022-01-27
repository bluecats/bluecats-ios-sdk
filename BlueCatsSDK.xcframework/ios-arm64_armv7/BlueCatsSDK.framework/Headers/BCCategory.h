//
//  BCCategory.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
#import "BCDefinitions.h"

///The `BCCategory` class defines an object that represents a tag that can be used to group beacons within a site under a common heading.  Categories can carry custom values, define zones, and trigger events.
@interface BCCategory : BCJSONModel <NSCopying>

///@name General Properties

///The resource ID.
@property (nonatomic, copy) NSString *categoryID;
///The category name.
@property (nonatomic, copy) NSString *name;
///The `BCCategoryType`.
@property (nonatomic, assign) BCCategoryType categoryType;

///@name Context Properties

///The dictionary containing the beacon's custom values.
@property (nonatomic, copy, readonly) NSDictionary *customValueForKey;

///@name Organizational properties

///The team that the category is within.
@property (nonatomic, copy) NSString *teamID;

@end
