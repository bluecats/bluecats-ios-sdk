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

@property (nonatomic, assign) NSInteger x;
@property (nonatomic, assign) NSInteger y;

+(BCPoint *)pointWithX:(NSInteger)x y:(NSInteger)y;

@end
