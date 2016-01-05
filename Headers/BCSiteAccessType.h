//
//  BCSiteAccessType.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"

@interface BCSiteAccessType : BCJSONModel<NSCopying>

@property (nonatomic, assign) NSInteger siteAccessTypeID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *displayName;

+ (BCSiteAccessType *)siteAccessTypeWithPublic:(BOOL)isPublic;

@end
