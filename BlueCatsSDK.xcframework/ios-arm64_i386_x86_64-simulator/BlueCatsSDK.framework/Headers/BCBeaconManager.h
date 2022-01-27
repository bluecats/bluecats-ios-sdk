//
//  BCBeaconManager.h
//  BlueCatsSDK
//
//  Created by Zach Prager on 10/15/15.
//  Copyright © 2015 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BCDefinitions.h"

@class BCSite, BCCategory, BCBeacon, BCBeaconRegion, BCMeasurement;
@protocol BCBeaconManagerDelegate;

@interface BCBeaconManager : NSObject

@property (nonatomic, weak) id<BCBeaconManagerDelegate> delegate;

- (instancetype)initWithDelegate:(id)delegate queue:(dispatch_queue_t)queue;

- (void)startMonitoringBeaconRegion:(BCBeaconRegion *)beaconRegion;
- (void)stopMonitoringBeaconRegion:(BCBeaconRegion *)beaconRegion;
- (NSArray <BCBeaconRegion *> *)monitoredBeaconRegions;

- (void)requestStateForSite:(BCSite *)site;
- (void)requestStateForBeacon:(BCBeacon *)beacon;

@end

@protocol BCBeaconManagerDelegate <NSObject>

@optional

- (void)beaconManager:(BCBeaconManager *)beaconManager didEnterSite:(BCSite *)site;
- (void)beaconManager:(BCBeaconManager *)beaconManager didExitSite:(BCSite *)site;
- (void)beaconManager:(BCBeaconManager *)beaconManager didDetermineState:(BCSiteState)state forSite:(BCSite *)site;

- (void)beaconManager:(BCBeaconManager *)beaconManager didRangeBlueCatsBeacons:(NSArray<BCBeacon *> *)blueCatsBeacons;

- (void)beaconManager:(BCBeaconManager *)monitor didRangeNewbornBeacons:(NSArray<BCBeacon *> *)newbornBeacons;
- (void)beaconManager:(BCBeaconManager *)monitor didRangeIBeacons:(NSArray<BCBeacon *> *)iBeacons;
- (void)beaconManager:(BCBeaconManager *)monitor didRangeEddystoneBeacons:(NSArray<BCBeacon *> *)eddystoneBeacons;
- (void)beaconManager:(BCBeaconManager *)monitor didRangeBeacons:(NSArray <BCBeacon *> *)beacons;
- (void)beaconManager:(BCBeaconManager *)monitor didRangeIdentifierBeacons:(NSArray <BCBeacon *> *)identifierBeacons;
- (void)beaconManager:(BCBeaconManager *)monitor didRangeMeasurementBeacons:(NSArray <BCBeacon *> *)beacons;

- (void)beaconManager:(BCBeaconManager *)monitor didEnterBeacons:(NSArray <BCBeacon *> *)beacons;
- (void)beaconManager:(BCBeaconManager *)monitor didExitBeacons:(NSArray <BCBeacon *> *)beacons;
- (void)beaconManager:(BCBeaconManager *)beaconManager didDetermineState:(BCBeaconState)state forBeacon:(BCBeacon *)beacon;

- (void)beaconManager:(BCBeaconManager *)monitor didDiscoverEddystoneURL:(NSURL *)eddystoneURL;

- (void)beaconManager:(BCBeaconManager *)beaconManager didDiscoverMeasurements:(NSArray<BCMeasurement *> *)measurements forBeacon:(BCBeacon *)beacon;

@end
