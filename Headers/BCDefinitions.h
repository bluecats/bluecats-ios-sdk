//
//  BCDefinitions.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 10/14/15.
//  Copyright © 2015 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

///This enum indicates the relationship of the device to the beacon region.
typedef enum {
    /**
     *  The state of the beacon region is unknown.
     */
            BCBeaconRegionStateUnknown = 0,
    /**
     *  The device is inside of the beacon region.
     */
            BCBeaconRegionStateInside,
    /**
     *  The device is outside of the beacon region.
     */
            BCBeaconRegionStateOutside,
} BCBeaconRegionState;

#pragma mark - BCSite

/**
 *  These constants indicate the known state of the site.
 */
typedef NS_ENUM(NSUInteger, BCSiteState) {
    /**
     *  The state of the site is unknown. The device has not ranged a beacon from the site.
     */
            BCSiteStateUnknown = 0,
    /**
     *  The device is currently ranging beacon(s) from the site.
     */
            BCSiteStateInside,
    /**
     *  The device has ranged a beacon from the site, but is not currently in range.
     */
            BCSiteStateOutside,
};

#pragma mark - BCCategory

/**
 *  These types reflect the category type.
 */
typedef NS_ENUM(NSUInteger, BCCategoryType) {
    /**
     *  The type of the category is unknown, has not been cached, or is not set.
     */
            BCCategoryTypeUnknown  = 0,
    /**
     *  The category is a default BlueCats category.
     */
            BCCategoryTypeBlueCats = 1,
    /**
     *  The category belongs to an individual BlueCats team.
     */
            BCCategoryTypeTeam     = 2
};

#pragma mark - BCBeacon

/**
 *  These constants indicate the known state of the beacon.
 */
typedef NS_ENUM(NSUInteger, BCBeaconState) {
    /**
     *  The state of the beacon is unknown. The device has not ranged beacon.
     */
            BCBeaconStateUnknown = 0,
    /**
     *  The device is currently ranging beacon.
     */
            BCBeaconStateInside,
    /**
     *  The device has ranged a beacon, but is not currently in range.
     */
            BCBeaconStateOutside,
};

/**
 *  These constants indicate the relative distance to a beacon.
 */
typedef NS_ENUM(NSUInteger, BCProximity) {
    /**
     *  The proximity of the beacon could not be determined.
     */
            BCProximityUnknown = 0,
    /**
     *  The beacon is in immediate proximity to the device.
     */
            BCProximityImmediate,
    /**
     *  The beacon is relatively close to the device.
     */
            BCProximityNear,
    /**
     *  The beacon is detectable, but far from the device.
     */
            BCProximityFar
};

///BlueCats internal ad types.
typedef NS_ENUM(NSUInteger, BCBlueCatsAdDataType) {
    BCBlueCatsAdDataTypeUnknown         = NSUIntegerMax,
    BCBlueCatsAdDataTypeSphynx1         = 1,
    BCBlueCatsAdDataTypeIBeacon2        = 2,
    BCBlueCatsAdDataTypeIBeacon3        = 3,
    BCBlueCatsAdDataTypeSecure1         = 4,
    BCBlueCatsAdDataTypeIBeacon4        = 5,
    BCBlueCatsAdDataTypeSecure2         = 6,
    BCBlueCatsAdDataTypeData1           = 7,
    BCBlueCatsAdDataTypeData2           = 8,
    BCBlueCatsAdDataTypeNewborn1        = 0x00,
    BCBlueCatsAdDataTypeEncryptedStatus = 0x09,
    BCBlueCatsAdDataTypeSecure16        = 0x16,
    BCBlueCatsAdDataTypeData17          = 0x17,
    BCBlueCatsAdDataTypeFullSecureData  = 0x18,
    BCBlueCatsAdDataTypeNewborn2        = 0x0A,
    BCBlueCatsAdDataTypeManagement      = 0x1A,
    BCBlueCatsAdDataTypeIdentifier      = 0x3A,
    BCBlueCatsAdDataTypeMeasurement     = 0x5A,
};

///**
// *  These constants indicate the verification status of a BlueCats beacon.
// */
//typedef NS_ENUM(NSUInteger, BCVerificationStatus) {
//    /**
//     *  The beacon has not been verified.
//     */
//            BCVerificationStatusNotVerified = 0,
//    /**
//     *  The SDK has detected that the beacon is emulating a BlueCats beacon.
//     */
//            BCVerificationStatusDetectedAttack,
//    /**
//     *  The beacon has been verified by BlueCats iBeacon ads.
//     */
//            BCVerificationStatusVerifiedViaBlueCatsIBeaconAd,
//    /**
//     *  The beacon has been verified by BlueCats Secure ads.
//     */
//            BCVerificationStatusVerifiedViaBueCatsSecureAd
//};

/**
 *  These constants indicate the encoding type of block data.
 */
typedef NS_ENUM(NSUInteger, BCBlockDataEncoding) {
    /**
     *  There is no encoding or the encoding of the block data is unknown.
     */
            BCBlockDataEncodingNone = 0,
    /**
     *  The block data is encoded in UTF8.
     */
            BCBlockDataEncodingUTF8,
    /**
     *  The block data is encoded in JSON.
     */
            BCBlockDataEncodingJSON
};

/**
 *  These constants indicate the type of block data received.
 */
typedef NS_ENUM(NSUInteger, BCBlockDataType) {
    /**
     *  The block data type is of a custom type.
     */
            BCBlockDataTypeCustom      = 0,
    /**
     *  The block data type represents a temperature.
     */
            BCBlockDataTypeTemperature = 15
};

/**
 *  The type of BlueCats device represented by the endpoint.
 */
typedef NS_ENUM(NSUInteger, BCBeaconEndpoint) {
    /**
     *  The beacon endpoint is a USB beacon connected to a host device.
     */
            BCBeaconEndpointSerial = 0
};

/**
 *  These constants indicate the ownership of a beacon.
 */
typedef NS_ENUM(NSUInteger, BCBeaconOwnership) {
    /**
     *  The ownership of the beacon is unknown.
     */
            BCBeaconOwnershipUnknown = 0,
    /**
     *  The beacon is a part of your current network.
     */
            BCBeaconOwnershipOwned   = 1,
    /**
     *  The beacon is owned by another network, but has been shared with the current app or network.
     */
            BCBeaconOwnershipShared  = 2,
    /**
     *  The beacon is in a public site.
     */
            BCBeaconOwnershipPublic  = 3
};

/**
 *  These constants indicate the level of access the current app or user has to a beacon.
 */
typedef NS_ENUM(NSUInteger, BCBeaconAccessRole) {
    /**
     *  The current app or user has access to track visits to the beacon.
     */
            BCBeaconAccessRoleVisitTracker    = 1,
    /**
     *  The current app or user has access to range the beacon.
     */
            BCBeaconAccessRoleBeaconRanger    = 2,
    /**
     *  The current app or user has access to update the settings on the beacon.
     */
            BCBeaconAccessRoleSettingsUpdater = 3
};

/**
 * These constants indicate the type of sensor measurement data. Different types have different array sizes.
 */
typedef NS_ENUM(NSInteger, BCMeasurementType) {
    BCMeasurementTypeNone = -0x01,
    BCMeasurementTypeTempAny = 0x00,
    BCMeasurementTypeAccelerometer = 0x01,
    BCMeasurementTypeTilt = 0x02,
    BCMeasurementTypeVoltage = 0x03,
    BCMeasurementTypeUptime = 0x04,
    BCMeasurementTypeTemp1Deg = 0x05,
};

typedef NS_ENUM(NSInteger, BCTiltAxis) {
    BCTiltAxisX = 0,
    BCTiltAxisY = 1,
    BCTiltAxisZ = 2,
};

#pragma mark - BCZone

/**
 *  These constants indicate the known relation of a device to a zone.
 */
typedef NS_ENUM(NSInteger, BCZoneState) {
    /**
     *  The device has not detected a beacon from the zone.
     */
            BCZoneStateUnknown,
    /**
     *  The device is currently in range of a beacon from the zone.
     */
            BCZoneStateInside,
    /**
     *  The device is no longer in range of a beacon from the zone.
     */
            BCZoneStateOutside
};

#pragma mark - BlueCatsSDK

/**
 *  These constants indicate the status of the BlueCats SDK.  If this returns `kBCStatusPurringWithErrors` check BCAppTokenVerificationStatus for more information.
 */
typedef NS_ENUM(NSInteger, BCStatus) {
    /**
     *  The SDK has not been told to startPurring
     */
            kBCStatusNeverPurred = 0,
    /**
     *  The SDK is purring and you are good to go!
     */
            kBCStatusPurring,
    /**
     *  The SDK is purring, but there was an issue. Check the app token and if the SDK has access to its required resources.
     */
            kBCStatusPurringWithErrors,
    /**
     *  The SDK has been stopped either explicitly by application code or due to an invalid app token
     */
            kBCStatusStopped
};

/**
 *  These constants indicate whether the app is authorized to use the BlueCatsSDK.
 */
typedef NS_ENUM(NSInteger, BCAppTokenVerificationStatus) {
    /**
     *  There was an error receiving the app token verification stats or startPurring has not been called.
     */
            kBCAppTokenVerificationStatusNotProvided = 0,
    /**
     *  startPurring has been called, but the app token has not been verified or marked invalid.
     */
            kBCAppTokenVerificationStatusNotVerified,
    /**
     *  The app token verification was successful.
     */
            kBCAppTokenVerificationStatusVerified,
    /**
     *  The app token is invalid. Check that the app token was entered correctly or if it is no longer valid.
     */
            kBCAppTokenVerificationStatusInvalid
};

#pragma mark - BCSyncStatus

/**
 *  These constants indicate the sync status of the SDK's local database.
 */
typedef NS_ENUM(NSInteger, BCSyncStatus) {
    /**
     *  No relevant request has been made to the server.
     */
            BCSyncStatusNotSynced,
    /**
     *  Relevant request has been made to the server and this object was not included.
     */
            BCSyncStatusUnauthorized,
    /**
     *  Full data has been synced.
     */
            BCSyncStatusSynced,
    /**
     *  Data has been restored from local DB.
     */
            BCSyncStatusRestored,
    /**
     *  Whatever data has been synced for this object is now stale.
     */
            BCSyncStatusExpired
};

typedef enum {
    BCBeaconOpcodeEraseBlock0 = 0x00,
    BCBeaconOpcodeEraseBlock1 = 0x01,
    BCBeaconOpcodeErasePointer = 0x02,
    BCBeaconOpcodeGoDFU = 0x03,
    BCBeaconOpcodePowerOn = 0x04,
    BCBeaconOpcodeOTALast = 0x04,
    BCBeaconOpcodeRestart = 0x0B, // Was 11, is not in firmware
    BCBeaconOpcodeReset = 0x0C, // Was 12 is 0x0B in firmware
    BCBeaconOpcodeEraseInternal = 0x0C,
    BCBeaconOpcodeWriteVersionLine1 = 0x0D, // 13,
    BCBeaconOpcodeWriteVersionLine2 = 0x0E, // 14,
    BCBeaconOpcodeWriteVersionLine3 = 0x0F, // 15,
    BCBeaconOpcodeWriteSettings1 = 0x0D,
    BCBeaconOpcodeWriteSettings2 = 0x0E,
    BCBeaconOpcodeWriteVer = 0x0F,
    BCBeaconOpcodeGoSecureMode = 0x10, // 16
    BCBeaconOpcodeGoIBeaconMode = 0x11, // 17
    BCBeaconOpcodeGoIBeaconPlusSecureMode = 0x12, // 18
    BCBeaconOpcodeRequestData = 0x13, // 19
    BCBeaconOpcodeDataRequest = 0x13,
    BCBeaconOpcodeResponseData = 0x14, // 20
    BCBeaconOpcodeSecureSettignsInitializationVector = 0x15, // 21
    BCBeaconOpcodeWriteIV = 0x15,
    BCBeaconOpcodeSecureSettingsBulkData = 0x16, // 22
    BCBeaconOpcodeWriteBulk = 0x16,
    BCBeaconOpcodeSecureSettingsMAC = 0x17, // 23
    BCBeaconOpcodeWriteMac = 0x17,
    BCBeaconOpcodeSettingsBulk = 0x18, // 24
    BCBeaconOpcodeWriteSettingsString = 0x18,
    BCBeaconOpcodeSettingsBulkEnd = 0x19, // 25
    BCBeaconOpcodeWriteSettingsStringLast = 0x19,
    BCBeaconOpcodePrepareFutureSettingsUpdate = 0x1A,
    BCBeaconOpcodePrepareOTA = 0x1B,
    BCBeaconOpcodeOTAPrepare = 0x1B,
    BCBeaconOpcodeGetUnencryptedStatus = 0x1C, // 28
    BCBeaconOpcodeReadUnencryptedStatus = 0x1C,
    BCBeaconOpcodeGetEncryptedStatus = 0x1D, // 29
    BCBeaconOpcodeReadEncryptedStatus = 0x1D,
    BCBeaconOpcodeBIMErase = 0x1E,
    BCBeaconOpcodeOTAHeaderWrite = 0x1F,
    BCBeaconOpcodeGetChallenge = 0x20,
    BCBeaconOpcodeTestExtFlash = 0x21,
    BCBeaconOpcodeIndicateMeasurementData = 0x22, // 33
    BCBeaconOpcodeStartPWM = 0x23,
    BCBeaconOpcodeStopPWM = 0x24,
    
    BCBeaconOpcodeExtended = 0x26,
} BCBeaconOpcode;


extern NSString *const BCAdDataTypeKey;
extern NSString *const BCAdDataTypeAppleIBeaconKey;
extern NSString *const BCAdDataTypeEddystoneTelKey;
extern NSString *const BCAdDataTypeEddystoneURLKey;
extern NSString *const BCAdDataTypeEddystoneUIDKey;
extern NSString *const BCAdDataTypeEddystoneEIDKey;
extern NSString *const BCAdDataTypeBlueCatsIBeaconKey;
extern NSString *const BCAdDataTypeBlueCatsSecureKey;
extern NSString *const BCAdDataTypeBlueCatsBlockDataKey;
extern NSString *const BCAdDataTypeBlueCatsNewbornKey;
extern NSString *const BCAdDataTypeEncryptedStatusKey;
extern NSString *const BCAdDataTypeBlueCatsMeasurementKey;
extern NSString *const BCAdDataTypeBlueCatsIdentifierKey;
extern NSString *const BCAdDataTypeBlueCatsManagementKey;

extern NSString *const BCBlueCatsAdDataTypeKey;
extern NSString *const BCAdDataLocalNameKey;
extern NSString *const BCAdDataTimestampKey;
extern NSString *const BCAdDataFirstDiscoveredAtKey;
extern NSString *const BCAdDataDiscoveredCountKey;
extern NSString *const BCAdDataDiscoveredPerMinuteKey;
extern NSString *const BCAdDataSettingsVersionKey;
extern NSString *const BCAdDataProximityUUIDStringKey;
extern NSString *const BCAdDataBluetoothAddressStringKey;
extern NSString *const BCAdDataMajorKey;
extern NSString *const BCAdDataMinorKey;
extern NSString *const BCAdDataFirmwareUIDKey;
extern NSString *const BCAdDataBatteryLevelKey;
extern NSString *const BCAdDataTxPowerLevelKey;
extern NSString *const BCAdDataMeasuredPowerAt1MeterKey;
extern NSString *const BCAdDataBeaconLoudnessLevelKey;
extern NSString *const BCAdDataTargetSpeedInMillisecondsKey;
extern NSString *const BCAdDataSequenceNumberKey;
extern NSString *const BCAdDataEddystoneUIDStringKey;
extern NSString *const BCAdDataEddystoneUIDNameSpaceKey;
extern NSString *const BCAdDataEddystoneURLSchemeKey;
extern NSString *const BCAdDataEddystoneURLStringKey;
extern NSString *const BCAdDataEddystoneEIDStringKey;
extern NSString *const BCAdDataBatteryVoltageDataKey;
extern NSString *const BCAdDataTempDataKey;
extern NSString *const BCAdDataUptimeDataKey;
extern NSString *const BCAdDataAdCountKey;
extern NSString *const BCAdDataEncryptedStatusKey;
extern NSString *const BCAdDataTeamIDKey;
extern NSString *const BCAdDataAlertKey;
extern NSString *const BCAdDataMeasurementDataKey;
extern NSString *const BCAdDataIdentifierDataKey;


extern NSString *const BCAdDataProcessorStaticIDKey;
extern NSString *const BCAdDataProcessorDataKey;

extern NSString *const BCBlockDataIdentifierKey;
extern NSString *const BCBlockDataTypeKey;
extern NSString *const BCBlockDataEncodingKey;
extern NSString *const BCBlockDataCountKey;
extern NSString *const BCBlockDataIndexKey;
extern NSString *const BCBlockDataLengthKey;
extern NSString *const BCBlockDataDataKey;
extern NSString *const BCBlockDataDataForIndexKey;
extern NSString *const BCBlockDataReassembledAtKey;

extern NSString * const BCSettingsUpdateVersionKey;
extern NSString * const BCSettingsUpdateBeaconModeIDKey;
extern NSString * const BCSettingsUpdateBluetoothAddressKey;
extern NSString * const BCSettingsUpdateProximityUUIDStringKey;
extern NSString * const BCSettingsUpdateMajorKey;
extern NSString * const BCSettingsUpdateMinorKey;
extern NSString * const BCSettingsUpdateLoudnessLevelKey;
extern NSString * const BCSettingsUpdateCurrentPasscodeKey;
extern NSString * const BCSettingsUpdateNewPasscodeKey;
extern NSString * const BCSettingsUpdateTargetSpeedInMillisecondsKey;
extern NSString * const BCSettingsUpdateLocalNameShortKey;
extern NSString * const BCSettingsUpdateEddystoneURLKey;
extern NSString * const BCSettingsUpdateEddystoneNamespaceIDKey;
extern NSString * const BCSettingsUpdateEddystoneInstanceIDKey;
extern NSString * const BCSettingsUpdateMeasuredPowerKey;
extern NSString * const BCSettingsUpdateSecurityTypeKey;
extern NSString * const BCSettingsUpdateAuthKeyKey;
extern NSString * const BCSettingsUpdatePrivacyDurationKey;
extern NSString * const BCSettingsUpdateBeaconRegionIDKey;
extern NSString * const BCSettingsUpdateAdSchemaKey;
extern NSString * const BCSettingsUpdateAdChannelsKey;
extern NSString * const BCSettingsUpdateAdAndBurstTableSchemaKey;

extern NSString *const BCEddyConfigDataSlotDictionaryKey;
extern NSString *const BCEddyConfigAdvertisingIntervalKey;
extern NSString *const BCEddyConfigRadioTxPowerKey;
extern NSString *const BCEddyConfigAdvertisedTxPowerKey;
extern NSString *const BCEddyConfigEIDIdentityKey;
extern NSString *const BCEddyConfigFactoryResetKey;
extern NSString *const BCEddyConfigRemainConnectableKey;

@interface BCDefinitions : NSObject

@end
