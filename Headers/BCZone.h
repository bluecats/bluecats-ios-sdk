//
//  BCZone.h
//  BCOtherCats
//
//  Created by Cody Singleton on 8/19/15.
//  Copyright (c) 2015 bluecats. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BCZoneScope) {
    BCZoneScopeSitewide,
    BCZoneScopeOneCategory,
    BCZoneScopeAcrossCategories
};

@class BCSite;

@interface BCZone : NSObject

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign) BCZoneScope zoneScope;
@property (nonatomic, assign) BOOL shouldPrefixLocationEventIdWithSiteName;
@property (nonatomic, copy) BCSite* site;

@end
