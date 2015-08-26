//
//  BCJSONModel+BCCustomValueDataSource.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/24/15.
//  Copyright (c) 2015 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"

@protocol BCCustomValueDataSource <NSObject>

@required
- (NSArray *)customValues;

@end

@interface BCJSONModel (BCCustomValueDataSource)

- (BOOL)hasCustomValueMatchingPredicate:(NSPredicate*)predicate;

- (BOOL)hasCustomValueWithKey:(NSString *)key andValueIn:(NSArray *)values;

- (NSString *)stringValueForCustomValueKey:(NSString *)key ignoreCase:(BOOL)ignoreCase;

@end
