//
//  NSPredicate+BCBeaconFilter.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 12/14/15.
//  Copyright © 2015 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCBeacon.h"
#import "BCDefinitions.h"

@interface NSPredicate (BCBeaconFilter)

+ (NSPredicate *)predicateForProximity:(BCProximity)proximity;

+ (NSPredicate *)predicateForAccuracyRangeFrom:(double)fromAccuracy to:(double)toAccuracy;

+ (NSPredicate *)predicateForCategoryNamed:(NSString *)categoryName;

+ (NSPredicate *)predicateForCustomValueKey:(NSString *)key;
+ (NSPredicate *)predicateForCustomValueKey:(NSString *)key andValue:(NSString *)value;

+ (NSPredicate *)predicateForCategoryWithCustomValueKey:(NSString *)key;
+ (NSPredicate *)predicateForCategoryWithCustomValueKey:(NSString *)key andValue:(NSString *)value;

+ (NSPredicate *)predicateForIsEddystone;
+ (NSPredicate *)predicateForHasDiscoveredEddystoneUIDFrame;
+ (NSPredicate *)predicateForHasDiscoveredEddystoneURLFrame;

+ (NSPredicate *)predicateForEddystoneWithNamespaceID:(NSString *)namespaceID;
+ (NSPredicate *)predicateForEddystoneWithURLDomain:(NSString *)eddystoneURLDomain;

+ (NSPredicate *)predicateForIsIBeacon;

+ (NSPredicate *)predicateForIsBlueCat;

@end
