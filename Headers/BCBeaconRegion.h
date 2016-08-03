//
//  BCBeaconRegion.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 28/02/14.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"

@class BCBeaconMode;

///The `BCBeaconRegion` class defines an object that represents a beacon region. Beacon regions are used in iOS to define separate or sub groupings of beacons. Multiple regions can be used to trigger separate wakeup events when entering new areas in iBeacon networks. Please see `CLBeaconRegion` for more information on native iOS regions.
@interface BCBeaconRegion : BCJSONModel <NSCopying>

///@name Region Properties

///The resource ID.
@property (nonatomic, copy) NSString *beaconRegionID;
///The string name of the region.
@property (nonatomic, copy) NSString *name;
///The identifier for the region. E.g. com.bluecats.beaconRegion1
@property (nonatomic, copy) NSString *identifier;

///The Proximity UUID of the region.
@property (nonatomic, copy) NSString *proximityUUIDString;
///If defined, the major value used to identify the region.
@property (nonatomic, copy) NSNumber *major;
///If defined, the minor value used to identify the region.
@property (nonatomic, copy) NSNumber *minor;
///The team ID of the team that the region belongs to.
@property (nonatomic, copy) NSString *teamID;
///The last date that the beacon region was cached.
@property (nonatomic, copy) NSDate *cachedAt;
@property (nonatomic, assign, getter=isAppManaged) BOOL appManaged;

@property (nonatomic, copy) NSString *keepAliveProximityUUIDString;
@property (nonatomic, copy) NSNumber *keepAliveMajor;
@property (nonatomic, copy) NSNumber *keepAliveMinor;
@property (nonatomic, copy) NSString *namespaceID;

-(BOOL)supportsBeaconMode:(BCBeaconMode *)beaconMode;

@end
