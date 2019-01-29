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

- (id)initWithManagedBeaconRegionVisit:(BCManagedBeaconRegionVisit *)managedBeaconRegionVisit;

+ (void)storedVisitsWithPredicate:(NSPredicate *)predicate
                  sortDescriptors:(NSArray *)sortDesc
                          success:(void (^)(NSArray *visits))success
                          failure:(void (^)(NSError *error))failure;

+ (void)numberOfVisitsWithPredicate:(NSPredicate *)predicate
                            success:(void (^)(NSUInteger visitCount))success
                            failure:(void (^)(NSError *error))failure;

@end
