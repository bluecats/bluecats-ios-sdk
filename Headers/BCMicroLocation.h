//
//  BCMicroLocation.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 4/8/13.
//
//

#import "BCBeacon.h"

@class BCSite, BCMapPoint;

@interface BCMicroLocation : NSObject <NSCopying>

@property (nonatomic, copy) NSArray *sites;
@property (nonatomic, copy) NSDictionary *beaconsForSiteID;
@property (nonatomic, copy) NSDate *timestamp;

- (NSArray *)sitesWithBeaconsInProximity:(BCProximity)proximity;

- (NSArray *)sitesWithCategoriesInProximity:(BCProximity)proximity;

- (NSArray *)beaconsForSite:(BCSite *)site
                  proximity:(BCProximity)proximity;

- (NSArray *)categoriesForSite:(BCSite *)site
                     proximity:(BCProximity)proximity;

- (BCMapPoint *)mapPointForSite:(BCSite *)site;

@end
