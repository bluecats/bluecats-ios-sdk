//
//  BCZone.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/19/15.
//  Copyright (c) 2015 bluecats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCDefinitions.h"

@class BCSite;

///The `BCZone` class defines an object that represents a grouped micro-location.  A `BCZone` can be composed of all beacons in a site, a category, multiple categories and beacons containing a zone identifier custom value.
@interface BCZone : NSObject

///@name Zone Properties

///The zone identifier. This must be unique.
@property (nonatomic, copy) NSString *identifier;
///The `BCZoneState`.
@property (nonatomic, assign) BCZoneState zoneState;
///The site the zone is within.
@property (nonatomic, copy) BCSite* site;
///The date the zone was entered.
@property (nonatomic, strong) NSDate* enteredZoneAt;
///The date the zone was re-entered.
@property (nonatomic, strong) NSDate* reenteredZoneAt;
///The date the zone was exited.
@property (nonatomic, strong) NSDate* exitedZoneAt;
///The last date a beacon from the zone was ranged.
@property (nonatomic, strong) NSDate* lastRangedBeaconsInZoneAt;
///The number of times the device entered the zone.
@property (nonatomic, assign) NSInteger entryCount;

///@name Getting Last Entered Date
/**
 *  Returns the last date the zone was entered.
 *
 *  @return Date when the zone was last entered.
 */
- (NSDate *) lastEntered;

@end
