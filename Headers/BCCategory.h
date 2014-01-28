//
//  BCCategory.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

typedef enum BCCategoryType {
    BCCategoryTypeUnknown = 0,
    BCCategoryTypeBlueCats = 1,
    BCCategoryTypeTeam = 2
} BCCategoryType;

@interface BCCategory : NSObject <NSCopying>

@property (nonatomic, copy) NSString *categoryID;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSNumber *categoryTypeID;
@property (nonatomic, copy) NSString *teamID;
@property (nonatomic, assign) BCCategoryType categoryType;

@end
