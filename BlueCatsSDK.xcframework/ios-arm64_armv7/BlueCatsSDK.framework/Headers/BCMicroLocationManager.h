//
//  BCMicroLocationManager.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 4/8/13.
//
//

#import <CoreLocation/CoreLocation.h>
#import "BCSite.h"

@protocol BCMicroLocationManagerDelegate;

@class BCMicroLocation;

/**
 *  The BCMicroLocationManager is the central point for receiving information about the device's current micro-location.
 *
 *  The BCMicroLocationManager includes a delegate and notifications to trigger reactions to micro-location events.
 */
@interface BCMicroLocationManager : NSObject

///@name Accessing the Delegate

///The delegate object to receive update events.
@property (nonatomic, weak) NSObject<BCMicroLocationManagerDelegate> *delegate;

///@name Property Protocols

///Collection of sites within the distance filter.
@property (readonly, nonatomic) NSOrderedSet *nearbySites;
///Distance of sites included in the collection of nearby sites.
@property (nonatomic, assign) double distanceFilter;
///The collection of currently monitored Sites (all sites that the current app has access to).
@property (readonly, nonatomic) NSSet *monitoredSites;
///The collection of ranged Sites.
@property (readonly, nonatomic) NSSet *rangedSites;
///Set to `YES` if you only wish to be notified only when the device changes proximity to a beacon.  Defaults to `NO`.
@property (nonatomic, assign) BOOL updateMicroLocationOnlyOnProximityChanges;
///The most current BCMicroLocation Object.
@property (nonatomic, copy, readonly) BCMicroLocation *microLocation;

#pragma mark  - BCMicroLocationManager interface

///@name Initiating Micro-Location Updates

///Starts the generation of updates that reports the device's micro-location.
- (void)startUpdatingMicroLocation;

///Stops the generation of updates that reports the device's micro-location.
- (void)stopUpdatingMicroLocation;

///@name Initiating Site Based Micro-Location Updates

/**
 *  Start monitoring for beacons in a specified site.
 *
 *  @param site The site of the beacons you wish to monitor.
 */
- (void)startMonitoringSite:(BCSite *)site;
/**
 *  Stop monitoring for beacons in a specified site.
 *
 *  @param site The site of the beacons you do not want to monitor.
 */
- (void)stopMonitoringSite:(BCSite *)site;
/**
 *  Request a state for a specified site.
 *
 *  @param site The site whose state you want to know.
 */
- (void)requestStateForSite:(BCSite *)site;
/**
 *  Start monitoring all sites available to the app or authenticated user.
 */
- (void)stopMonitoringAllSites;
/**
 *  Returns a Boolean indicating whether the device is monitoring the specified site.
 *
 *  @param site The BCSite to check for monitoring.
 *
 *  @return `YES` if the device is monitoring the specified site; `NO` if it is not.
 */
- (BOOL)isMonitoringSite:(BCSite *)site;
/**
 *  Starts the delivery of notifications for beacons in the specified Site.
 *
 *  @param site The Site object that defines the identifying information for the targeted beacons.
 */
- (void)startRangingBeaconsInSite:(BCSite *)site;
/**
 *  Stops the delivery of notifications for beacons in the specified Site.
 *
 *  @param site The Site object that defines the identifying information for the targeted beacons.
 */
- (void)stopRangingBeaconsInSite:(BCSite *)site;

- (instancetype)initWithDelegateQueue:(dispatch_queue_t)queue;

///@name Determining the Availability of Services

/**
 *  Returns a Boolean value indicating whether location services are enabled on the device.
 *
 *  @return `YES` if location services are enabled; `NO` if they are not.
 */
+ (BOOL)locationServicesEnabled;
/**
 *  Returns the app’s authorization status for using location services.
 *
 *  @return A value indicating whether the app is authorized to use location services.
 */
+ (CLAuthorizationStatus)authorizationStatus;
/**
 *  Returns a Boolean Value indicating whether the app is authorized to use location services.
 *
 *  @return `YES` if the app is authorized for Always or WhenInUse; `NO` if it is not authorized to use location services.
 */
+ (BOOL)isAuthorized;
/**
 *  Returns a Boolean value if site monitoring is available.
 *
 *  @return `YES` if site monitoring is available; `NO` if it is not.
 */
+ (BOOL)isSiteMonitoringAvailable;
/**
 *  Returns a Boolean value indicating
 *
 *  @return `YES` if beacon ranging is available; `NO` if it is not.
 */
+ (BOOL)isBeaconRangingAvailable;
/**
 *  Returns a Boolean value
 *
 *  @return `YES` if micro-location updating is available; `NO` if it is not.
 */
+ (BOOL)isMicroLocationUpdatingAvailable;

///@name Accessing and Setting the Shared Manager

/**
 *  Returns the shared micro-location manager.
 *
 *  @return A shared `BCMicroLocationManager`.
 */
+ (BCMicroLocationManager *)sharedManager;
/**
 *  Use this method if you would like to set your own shared manager.
 *
 *  @param sharedManager A shared BCMicroLocationManager instance.
 */
+ (void)setSharedManager:(BCMicroLocationManager *)sharedManager;

@end

/**The `BCMicroLocationManagerDelegate` protocol defines the methods used to receive location updates from a `BCMicroLocationManager`.
 *
 *  The use of site specific updates requires having called startMonitoringSite for the specified site.
 *
 */
@protocol BCMicroLocationManagerDelegate <NSObject>

@optional

///@name Responding to Micro-Location Events

/**
 *  Tells the delegate that the micro-location manager was unable to retrieve a micro-location.
 *
 *  @param microLocationManager The location manager object that was unable to retrieve the micro-location.
 *  @param error                The error object containing the reason the micro-location could not be retrieved.
 */ 
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
            didFailWithError:(NSError *)error;

///@name Responding to Site Micro-Location Events

/**
 *  Tells the delegate that new nearby site data is available.
 *
 *  @param microLocationManager The micro-location manager object that generated the update event.
 *  @param sites                An array of BCSites.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
        didUpdateNearbySites:(NSArray *)sites;
/**
 *  Tells the delegate that the micro-location manager did start monitoring a specified site passed into `startRangingBeaconsInSite:`.
 *
 *  @param microLocationManager The micro-location manager object that generated the update event.
 *  @param site                 The site for which monitoring did start successfully.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
   didStartMonitoringForSite:(BCSite *)site;
/**
 *  Tells the delegate that the micro-location manager was unable to monitor a specified site passed into `startRangingBeaconsInSite:`.
 *
 *  @param microLocationManager The micro-location manager reporting the event.
 *  @param site                 The BCSite that the micro-location manager was unable to monitor.
 *  @param error                The error object containing the reason why monitoring failed for the specified site.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
    monitoringDidFailForSite:(BCSite *)site
                   withError:(NSError *)error;
/**
 *  Tells the delegate that a state was determined for the specified site passed into `startRangingBeaconsInSite:`.
 *
 *  @param microLocationManager The micro-location manager object that generated the update event.
 *  @param state                The BCSite state for the specified site.
 *  @param site                 The BCSite passed into `startRangingBeaconsInSite:`.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
           didDetermineState:(BCSiteState)state
                     forSite:(BCSite *)site;
/**
 *  Tells the delegate that a site was entered.
 *
 *  @param microLocationManager The micro-location manager object that generated the update event.
 *  @param site                 The BCSite that was entered by the device.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
                didEnterSite:(BCSite *)site;
/**
 *  Tells the delegate that a site was exited.
 *
 *  @param microLocationManager The micro-location manager object that generated the update event.
 *  @param site                 The BCSite that was exited by the device.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
                 didExitSite:(BCSite *)site;
/**
 *  Tells the delegate that the micro-location manager was unable to range beacons for the specified site.
 *
 *  @param microLocationManager The micro-location manager reporting the event.
 *  @param site                 The BCSite
 *  @param error                The error object containing the reason beacon could not be ranged.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
rangingBeaconsDidFailForSite:(BCSite *)site
                   withError:(NSError *)error;
/**
 *  Tells the delegate that the micro-location manager did range beacons for the specified site.
 *
 *  @param microLocationManager The micro-location manager object that generated the update event.
 *  @param beacons              An array of BCBeacons.
 *  @param site                 A BCSite.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
             didRangeBeacons:(NSArray *)beacons
                      inSite:(BCSite *)site;
/**
 *  Tells the delegate that the micro-location manager did update its micro-location array.
 *
 *  @param microLocationManager The micro-location manager object that generate the update event.
 *  @param microLocations       An array of BCMicroLocations with the most recent at the end.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager
     didUpdateMicroLocations:(NSArray *)microLocations;

///@name Responding to Authorization Changes

/**
 *  Tells the delegate that the micro-location manager did update micro-location services ability.
 *
 *  @param microLocationManager The micro-location manager object that generate the update event.
 *  @param available            `YES` if micro-location services are now available or `NO` if they are no longer available.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager didUpdateMicroLocationServicesAvailibility:(BOOL)available;

///@name Responding by Serial Number

/*
 These need to send something other than serial numbers because we might begin
 visit before delegate gets call about ranging beacons.
 */
/**
 *  Tells the delegate that the micro-location manager did begin visits for beacons with the specified serial numbers.
 *
 *  @param microLocationManager The micro-location manager object that generate the update event.
 *  @param serialNumbers        An array of BCBeacon serial numbers.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager didBeginVisitForBeaconsWithSerialNumbers:(NSArray *)serialNumbers;
/**
 *  Tells the delegate that the micro-location manager did end visits for beacons with the specified serial numbers.
 *
 *  @param microLocationManager The micro-location manager object that generate the update event.
 *  @param serialNumbers        An array of BCBeacon serial numbers.
 */
- (void)microLocationManager:(BCMicroLocationManager *)microLocationManager didEndVisitForBeaconsWithSerialNumbers:(NSArray *)serialNumbers;

@end

extern NSString * const BCMicroLocationManagerDidEnterSite;
extern NSString * const BCMicroLocationManagerDidExitSite;
extern NSString * const BCMicroLocationManagerDidUpdateNearbySites;
extern NSString * const BCMicroLocationManagerDidUpdateMicroLocationServicesAvailibility;

extern NSString * const BCMicroLocationManagerNotificationSiteItem;
extern NSString * const BCMicroLocationManagerNotificationNewLocationItem;
