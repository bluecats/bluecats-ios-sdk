//
//  BCPoint.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/24/13.
//
//

#import "BCJSONModel.h"
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

///The `BCPoint` class represents an x/y coordinate on a `BCMap`.
@interface BCPoint : BCJSONModel<NSCopying>

///@name Coordinate Properties

///The x-coordinate of the point.
@property (nonatomic, assign) CGFloat x;
///The y-coordinate of the point.
@property (nonatomic, assign) CGFloat y;

///@name Getting the Point

///Returns the current `BCPoint` object.
- (CGPoint)CGPoint;

///@name Initialization
/**
 *  Initializes and returns a `BCPoint` with the specified coordinates.
 *
 *  @param x The x-coordinate of the point to construct.
 *  @param y The y-coordinate of the point to construct.
 *
 *  @return A `BCPoint` object initialized with the specified x-y coordinates.
 */
+(BCPoint *)pointWithX:(CGFloat)x y:(CGFloat)y;
/**
 *  Initializes and returns a `BCPoint` from the specified `CGPoint`.
 *
 *  @param point The `CGPoint` of the `BCPoint` to construct.
 *
 *  @return The `BCPoint` object initialized from the provided `CGPoint`.
 */
+(BCPoint *)pointWithCGPoint:(CGPoint)point;

@end
