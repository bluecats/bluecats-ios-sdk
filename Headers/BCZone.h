//
//  BCZone.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 8/19/15.
//  Copyright (c) 2015 bluecats. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BCZoneScope) {
    BCZoneScopeAllBeaconsInSite,
    BCZoneScopeAllBeaconsInCategory,
    BCZoneScopeAllBeaconsWithZoneIdentifierCustomValue
};

typedef NS_ENUM(NSInteger, BCZoneState) {
    BCZoneStateUnknown,
    BCZoneStateInside,
    BCZoneStateOutside
};

@class BCSite;

@interface BCZone : NSObject

@property (nonatomic, copy) NSString *identifier;
@property (nonatomic, assign) BCZoneState zoneState;
@property (nonatomic, assign) BCZoneScope zoneScope;
@property (nonatomic, copy) BCSite* site;
@property (nonatomic, strong) NSDate* enteredZoneAt;
@property (nonatomic, strong) NSDate* reenteredZoneAt;
@property (nonatomic, strong) NSDate* exitedZoneAt;
@property (nonatomic, strong) NSDate* lastRangedBeaconsInZoneAt;
@property (nonatomic, assign) NSInteger entryCount;

- (NSDate *) lastEntered;

@end
