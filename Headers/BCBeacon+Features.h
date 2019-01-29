//
//  BCBeacon+Features.m
//  BlueCatsSDK
//
//  Created by Cody Singleton on 4/13/15.
//  Copyright (c) 2015 BlueCats. All rights reserved.
//

#import "BCBeacon.h"

@interface BCBeacon (Features)

- (BOOL)supportsTargetSpeedChange;
- (BOOL)supportsTemperatureData;
- (BOOL)supportsTwoWayDataTransfer;
- (BOOL)supportsLegacyBLEFirmwareUpdate;
- (BOOL)supportsUnencryptedBLEFirmwareUpdate;
- (BOOL)supportsAES128CMACBLEFirmwareUpdate;
- (BOOL)supportsLegacyBLESettingsUpdate;
- (BOOL)supportsUnencryptedBLESettingsUpdate;
- (BOOL)supportsAES128CMACBLESettingsUpdate;

@end
