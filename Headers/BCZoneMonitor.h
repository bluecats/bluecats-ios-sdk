//
//  BCZoneMonitor.h
//  BCOtherCats
//
//  Created by Cody Singleton on 8/18/15.
//  Copyright (c) 2015 bluecats. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCZone;

@protocol BCZoneMonitorDelegate;

@interface BCZoneMonitor : NSObject

@property (nonatomic, assign, readonly, getter=isZoneMonitoringEnabled) BOOL zoneMonitoringEnabled;

- (instancetype)initWithDelegate:(id)delegate queue:(dispatch_queue_t)queue;
- (instancetype)initWithDelegate:(id)delegate queue:(dispatch_queue_t)queue zoneIdentifierKeys:(NSArray *)keys;

- (NSArray *)zoneIdentifierKeys;

- (void)startMonitoringZones;
- (void)stopMonitoringZones;

@end


@protocol BCZoneMonitorDelegate <NSObject>

@optional
- (void)zoneMonitor:(BCZoneMonitor *)monitor didEnterZone:(BCZone *)zone;
- (void)zoneMonitor:(BCZoneMonitor *)monitor didReEnterZone:(BCZone *)zone;
- (void)zoneMonitor:(BCZoneMonitor *)monitor didRangeBeacons:(NSArray *)beacons inZone:(BCZone *)zone;
- (void)zoneMonitor:(BCZoneMonitor *)monitor didDwellInZone:(BCZone *)zone forTimeInterval:(NSTimeInterval)dwellTimeInterval;
- (void)zoneMonitor:(BCZoneMonitor *)monitor didExitZone:(BCZone *)zone;

@end