//
//  BCAddress.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

@class CLLocation;

@interface BCAddress : NSObject <NSCopying>

@property (nonatomic, copy) NSString *addressID;
@property (nonatomic, copy) NSString *streetLine1;
@property (nonatomic, copy) NSString *streetLine2;
@property (nonatomic, copy) NSString *cityName;
@property (nonatomic, copy) NSString *stateAbbrev;
@property (nonatomic, copy) NSString *postalCode;
@property (nonatomic, copy) NSString *countryName;
@property (nonatomic, copy) NSNumber *latitude;
@property (nonatomic, copy) NSNumber *longitude;
@property (nonatomic, assign) BOOL useLatLong;

+ (BCAddress *)addressWithStreetLine1:(NSString *)streetLine1
                          streetLine2:(NSString *)streetLine2
                             cityName:(NSString *)cityName
                          stateAbbrev:(NSString *)stateAbbrev
                           postalCode:(NSString *)postalCode
                          countryName:(NSString *)countryName;

- (NSString *)cityNameAndStateAbbrevJoinedByComma;
- (NSString *)latitudeAndLongitudeJoinedByComma;
- (NSString *)componentsJoinedByComma;

- (BOOL)isAddressEmpty;

- (CLLocation *)location;

@end
