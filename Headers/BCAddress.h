//
//  BCAddress.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 2/13/13.
//  Copyright (c) 2013 Bluecats. All rights reserved.
//

#import "BCJSONModel.h"
@class CLLocation;

///The `BCAddress` class defines an object that represents a physical address.
@interface BCAddress : BCJSONModel <NSCopying>

///@name Address Properties

///The resource ID.
@property (nonatomic, copy) NSString *addressID;
///Line one of the street address.
@property (nonatomic, copy) NSString *streetLine1;
///Line two of the street address.
@property (nonatomic, copy) NSString *streetLine2;
///The name of the City.
@property (nonatomic, copy) NSString *cityName;
///State abbreviation.
@property (nonatomic, copy) NSString *stateAbbrev;
///Postal code.
@property (nonatomic, copy) NSString *postalCode;
///Country name.
@property (nonatomic, copy) NSString *countryName;
///The latitude of the address.
@property (nonatomic, copy) NSNumber *latitude;
///The longitude of the address.
@property (nonatomic, copy) NSNumber *longitude;
///`BOOL` option to use coordinates rather than address.  `YES` lat-log is used; `NO` address is used.
@property (nonatomic, assign) BOOL useLatLong;

///@name Creating an Address
/**
 *  Returns a address object defined by the specified parameters.
 *
 *  @param streetLine1 Line one of the street address.
 *  @param streetLine2 Line two of the street address.
 *  @param cityName    Address city.
 *  @param stateAbbrev State abbreviation.
 *  @param postalCode  Postal code.
 *  @param countryName Name of the country.
 *
 *  @return A `BCAddress` object created from specified address information.
 */
+ (BCAddress *)addressWithStreetLine1:(NSString *)streetLine1
                          streetLine2:(NSString *)streetLine2
                             cityName:(NSString *)cityName
                          stateAbbrev:(NSString *)stateAbbrev
                           postalCode:(NSString *)postalCode
                       andCountryName:(NSString *)countryName;
/**
 *  Returns a address object defined by the specified coordinates.
 *
 *  @param latitude  Latitude.
 *  @param longitude Longitude.
 *
 *  @return A `BCAddress` object with the provided latitude, longitude and useLatLong set to `YES`.
 */
+ (BCAddress *)addressWithLatitude:(NSNumber *)latitude
                      andLongitude:(NSNumber *)longitude;

///@name Getting a CoreLocation Object
/**
 *  Returns a `CoreLocation` object representing the address.
 *
 *  @return `CoreLocation` object representing the address.
 */
- (CLLocation *)location;

@end
