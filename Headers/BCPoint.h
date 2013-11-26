//
//  BCPoint.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 7/24/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface BCPoint : NSObject <NSCopying>

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;

- (CGPoint)CGPoint;

+(BCPoint *)pointWithX:(CGFloat)x y:(CGFloat)y;
+(BCPoint *)pointWithCGPoint:(CGPoint)point;

@end
