//
//  BCRegionVisit.h
//  BlueCatsSDK
//
//  Created by Zach Prager on 10/17/14.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"
#import <Foundation/Foundation.h>

@class BCManagedBeaconRegionVisit;

@interface BCBeaconRegionVisit : BCJSONModel <NSCopying>

@property (nonatomic, copy) NSString *beaconRegionIdentifier;
@property (nonatomic, copy) NSDate *beganAt;
@property (nonatomic, copy) NSDate *endedAt;
@property (nonatomic, copy) NSString *beaconRegionVisitID;
@property (nonatomic, assign) BOOL appInForeground;
@property (nonatomic, strong) BCManagedBeaconRegionVisit *managedRegionVisit;

+ (NSArray *)storedVisitsWithPredicate:(NSPredicate *)predicate andSortDescriptors:(NSArray *)sortDesc;
+ (NSUInteger)numberOfVisitsWithPredicate:(NSPredicate *)predicate;

@end
