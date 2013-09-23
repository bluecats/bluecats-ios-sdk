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
@property (nonatomic, assign) NSInteger zipCode;
@property (nonatomic, assign) NSInteger zipPlusFour;
@property (nonatomic, copy) NSString *countryName;
@property (nonatomic, copy) NSNumber *latitude;
@property (nonatomic, copy) NSNumber *longitude;

+ (BCAddress *)addressWithStreetLine1:(NSString *)streetLine1 streetLine2:(NSString *)streetLine2 cityName:(NSString *)cityName stateAbbrev:(NSString *)stateAbbrev zipCode:(NSString *)zipCode countryName:(NSString *)countryName;

- (NSString *)formatAsCityCommaStateAbbrev;

- (BOOL)addressIsEmpty;

- (CLLocation *)location;

@end
