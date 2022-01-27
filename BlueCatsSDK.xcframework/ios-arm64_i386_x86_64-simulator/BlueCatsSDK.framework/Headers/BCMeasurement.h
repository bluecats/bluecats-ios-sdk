//
//  BCMeasurement.h
//  Pods
//
//  Created by Ron Holmes on 12/10/16.
//
//

#import "BCJSONModel.h"
#import "BCDefinitions.h"

@interface BCMeasurement : NSObject <NSCopying>

//BCMeasurement Public Properties
@property (readonly, nonatomic) NSDate *measuredAt;
@property (readonly, nonatomic, assign) BCMeasurementType measurementType;
@property (readonly, nonatomic) NSArray<NSNumber *> *values;

//BCMeasurement Public methods
- (id)initWithMeasurementData:(NSData *)newData measurementType:(BCMeasurementType)measurementType;

@end
