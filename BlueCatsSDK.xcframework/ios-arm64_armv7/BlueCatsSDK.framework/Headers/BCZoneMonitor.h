//
//  BCZoneMonitor.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/18/15.
//  Copyright (c) 2015 bluecats. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCZone, BCSite;

@protocol BCZoneMonitorDelegate;

///The `BCZoneMonitor` class defines an object that is central manager for `BCZone` obects.  Set zone identifier keys and observe `BCZoneMonitorDelegate` notifications from this class.
@interface BCZoneMonitor : NSObject

///@name Properties

///Returns a `BOOL` value indicating if zone monitoring is enabled. `YES` if zone monitoring is enabled; `NO` if it is not enabled.
@property (nonatomic, assign, readonly, getter=isZoneMonitoringEnabled) BOOL zoneMonitoringEnabled;

///@name Initializing the Zone Monitor
/**
 *  Initializes the zone monitor with a specified delegate and dispatch queue.
 *
 *  @param delegate The delegate to receive  zone events.
 *  @param queue    The dispatch queue to use to dispatch the zone events.  If the value is nil, the zone monitor dispatches zone events using the main queue.
 *
 *  @return Returns a newly initialized zone monitor.
 */
- (instancetype)initWithDelegate:(id<BCZoneMonitorDelegate>)delegate queue:(dispatch_queue_t)queue;
/**
 *  Initializes the zone monitor with specified delegate, dispatch queue, and zone identifier keys.
 *
 *  @param delegate The delegate to receive zone events.
 *  @param queue    The dispatch queue to use to dispatch the zone events.  If the value is nil, the zone monitor dispatches zone events using the main queue.
 *  @param keys     An optional array of zone identifier keys.
 *
 *  @return The newly initialized zone monitor.
 */
- (instancetype)initWithDelegate:(id<BCZoneMonitorDelegate>)delegate queue:(dispatch_queue_t)queue zoneIdentifierKeys:(NSArray *)keys;

///@name Getting Zone Identifier Keys

///Zone identifier keys used to define the zone.
- (NSArray *)zoneIdentifierKeys;

///@name Starting and Stopping Zone Monitoring

///Asks the zone monitor to start zone monitoring.
- (void)startMonitoringZones;
///Asks the zone monitor to stop zone monitoring.
- (void)stopMonitoringZones;

///@name Resuming and Suspending Zone Monitoring

///Asks the zone monitor to resume suspended zone monitoring in all sites.
- (void)resumeMonitoringZonesInAllSites;
///Asks the zone monitor to suspend zone monitoring in all sites.
- (void)suspendMonitoringZonesInAllSites;

@end

///The `BCZoneMonitorDelegate` protocol defines the methods used to receive location updates from a `BCZoneMonitor` object.
@protocol BCZoneMonitorDelegate <NSObject>

@optional

///@name Site Entry and Exit
/**
 *  Tells the delegate that the device did enter the specified site.
 *
 *  @param monitor The zone monitor object that generated the update event.
 *  @param site    The site object of the event.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor didEnterSite:(BCSite *)site;
/**
 *  Tells the delegate that the device did exit the specified site.
 *
 *  @param monitor The zone monitor object that generated the update event.
 *  @param site    The site object of the event.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor didExitSite:(BCSite *)site;

///@name Zone Entry, Exit and Ranging
/**
 *  Tells the delegate that the device did enter the specified zone.
 *
 *  @param monitor The zone monitor object that generated the update event.
 *  @param zone    The zone object of the event.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor didEnterZone:(BCZone *)zone;
/**
 *  Tells the delegate that the devices did re-enter the specified zone.
 *
 *  @param monitor The zone monitor object that generated the update event.
 *  @param zone    The zone object of the event.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor didReEnterZone:(BCZone *)zone;
/**
 *  Tells the delegate that the device did range the returned beacons in the specified zone.
 *
 *  @param monitor The zone monitor object that generated the update event.
 *  @param beacons An array of beacons that were ranged.
 *  @param zone    The BCZone obect of the event.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor didRangeBeacons:(NSArray *)beacons inZone:(BCZone *)zone;
/**
 *  Tells the delegate that the device did dwell in a BCZone
 *
 *  @param monitor           The zone monitor object that generated the update event.
 *  @param zone              The zone object of the event.
 *  @param dwellTimeInterval The dwell time interval satisfied by the event.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor didDwellInZone:(BCZone *)zone forTimeInterval:(NSTimeInterval)dwellTimeInterval;
/**
 *  Tells the delegate that the device did exit the specified zone.
 *
 *  @param monitor The zone monitor object that generated the update event.
 *  @param zone    The zone object of the event.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor didExitZone:(BCZone *)zone;
- (void)zoneMonitor:(BCZoneMonitor *)monitor inZone:(BCZone *)zone afterTime:(NSTimeInterval)timeInterval forRange:(NSRange)timeRange;

///@name Zone Suspension and Resumption
/**
 *  Tells the delegate that zone monitoring for the specified site will suspend until the specified date.
 *
 *  @param monitor The zone monitor object that generated the update event.
 *  @param site    The site object where zone monitoring will suspend.
 *  @param date    The NSDate when zone monitoring for the specified site will resume.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor willSuspendMonitoringInSite:(BCSite *)site untilDate:(NSDate *)date;
/**
 *  Tells the delegate that zone monitoring for the specified site will resume.
 *
 *  @param monitor The zone monitor object that generated the update event.
 *  @param site    The site object where zone monitoring will resume.
 */
- (void)zoneMonitor:(BCZoneMonitor *)monitor willResumeMonitoringInSite:(BCSite *)site;

@end