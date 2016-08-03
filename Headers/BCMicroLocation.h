//
//  BCMicroLocation.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 4/8/13.
//
//

#import "BCBeacon.h"

@class BCSite, BCMapPoint;

///The `BCMicroLocation` class defines an object that represents the micro-location of the device at a single point in time.
@interface BCMicroLocation : NSObject <NSCopying>

///@name Properties

///An array of BCSites within the micro-location.
@property (nonatomic, copy) NSArray *sites;
///A dictionary of beacons within
@property (nonatomic, copy) NSDictionary *beaconsForSiteID;
///The date of the micro-location.
@property (nonatomic, copy) NSDate *timestamp;

///@name Initialization

/**
 *  Initializes a BCMicroLocation object with the specified sites and beacons.
 *
 *  @param sites   Array of BCSites to include in the micro-location.
 *  @param beacons Array of BCBeacons to include in the micro-location.
 *
 *  @return Initializes and returns a newly created BCMicroLocation with the defined sites and beacons.
 */
- (id)initWithSites:(NSArray *)sites andBeacons:(NSArray *)beacons;

///@name Class Methods

/**
 *  Returns all of the beacons in the micro-location.
 *
 *  @return An array of BCBeacons.
 */
- (NSArray *)beacons;
/**
 *  Returns an array of beacons in the specified BCProximity.
 *
 *  @param proximity The BCProximity in which to filter by.
 *
 *  @return An array of BCBeacons within the proximity.
 */
- (NSArray *)sitesWithBeaconsInProximity:(BCProximity)proximity;
/**
 *  Returns an array of sites that have categories in the specified BCProximity.
 *
 *  @param proximity The BCProximity in which to filter by.
 *
 *  @return An array of BCSites within the proximity.
 */
- (NSArray *)sitesWithCategoriesInProximity:(BCProximity)proximity;
/**
 *  Returns an array of beacons in the specified site and proximity.
 *
 *  @param site      The BCSite for which to filter by.
 *  @param proximity The BCProximity for which to filter by.
 *
 *  @return An array of BCBeacons within the site and proximity.
 */
- (NSArray *)beaconsForSite:(BCSite *)site
                  proximity:(BCProximity)proximity;
/**
 *  Returns an array of beacons in the specified site and proximity.
 *
 *  @param siteID    The BCSite for which to filter by.
 *  @param proximity The BCProximity for which to filter by.
 *
 *  @return An array of BCBeacons within the site and proximity.
 */
- (NSArray *)beaconsForSiteID:(NSString *)siteID
                  proximity:(BCProximity)proximity;
/**
 *  Returns an array of beacons in the specified proximity.
 *
 *  @param proximity The BCSite for which to filter by.
 *
 *  @return An array of BCBeacons within the proximity.
 */
- (NSArray *)beaconsInProximity:(BCProximity)proximity;
/**
 *  Returns an array of categories in the specified site and proximity.
 *
 *  @param site      The BCSite for which to filter by.
 *  @param proximity The BCProximity for which to filter by.
 *
 *  @return An array of BCCategories within the site and proximity.
 */
- (NSArray *)categoriesForSite:(BCSite *)site
                     proximity:(BCProximity)proximity;
/**
 *  Returns an array of categories in the specified site and proximity.
 *
 *  @param siteID    The BCSite for which to filter by.
 *  @param proximity The BCProximity for which to filter by.
 *
 *  @return An array of BCCategories within the site and proximity.
 */
- (NSArray *)categoriesForSiteID:(NSString *)siteID
                     proximity:(BCProximity)proximity;

///@name Getting Map Points by Site
/**
 *  Returns the map point for the specified site if present.
 *
 *  @param site A BCSite.
 *
 *  @return A BCMapPoint for the specified site.
 */
- (BCMapPoint *)mapPointForSite:(BCSite *)site;
/**
 *  Returns the map point for the specified site.
 *
 *  @param siteID A BCSite ID.
 *
 *  @return A BCMapPoint for the specified site.
 */
- (BCMapPoint *)mapPointForSiteID:(NSString *)siteID;

///@name Getting Categories
///Returns all categories in the micro-location.
- (NSArray *)allCategories;

@end
