//
//  BCMicroLocation.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 4/8/13.
//
//

@class BCSite, BCMapPoint;

@interface BCMicroLocation : NSObject <NSCopying>

@property (nonatomic, strong) BCSite *site;
@property (nonatomic, copy) NSString *message;
@property (nonatomic, copy) NSArray *categories;
@property (nonatomic, strong) BCMapPoint *mapPoint;
@property (nonatomic, copy) NSDate *timestamp;

@end
