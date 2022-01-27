//
//  BCSite.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/30/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
#import "BCDefinitions.h"

@class CLLocation, BCAddress, BCSiteAccessType;

///The `BCSite` class defines an object representing a BlueCats site.
@interface BCSite : BCJSONModel <NSCopying>

///@name Site Properties

///The resource ID.
@property (nonatomic, copy) NSString *siteID;
///The site name.
@property (nonatomic, copy) NSString *name;
///The site access type.
@property (nonatomic, strong) BCSiteAccessType *siteAccessType;

///@name Location Properties

///The site address.
@property (nonatomic, strong) BCAddress *address;
/**
 *  Returns a `CLLocation` object from the site information.
 *
 *  @return A `CLLocation` object.
 */
- (CLLocation *)location;

///@name Map Properties

///The array of `BCMaps` assigned to the site.
@property (nonatomic, copy) NSArray *maps;
///The dictionary containing the site's custom values.
@property (nonatomic, copy, readonly) NSDictionary *customValueForKey;

///@name Organizational Properties
///The resource ID of the team the site is within.
@property (nonatomic, copy) NSString *teamID;

@end
