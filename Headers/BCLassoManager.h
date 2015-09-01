//
//  BCLassoManager.h
//  BlueCatsSDK
//
//  Created by Zach Prager on 7/23/15.
//  Copyright (c) 2015 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCBeacon, BCLassoManager, BCLasso;

@protocol BCLassoManagerDelegate <NSObject>

@optional

- (NSDictionary *)lassoManager:(BCLassoManager *)lassoManager
            dictionaryForLasso:(BCLasso *)lasso;

- (void)lassoManager:(BCLassoManager *)lassoManager
 didRedeemDictionary:(NSDictionary *)dictionary
            forLasso:(BCLasso *)lasso
            response:(NSDictionary *)responseDictionary;

- (void)lassoManager:(BCLassoManager *)lassoManager
didFailToRedeemDictionary:(NSDictionary *)dictionary
   forLasso:(BCLasso *)lasso
               error:(NSError *)error;


- (BOOL)shouldBeginRedemptionRequest:(BCLassoManager *)lassoManager
                    forLasso:(BCLasso *)lasso;

- (void)didEnterLasso:(BCLasso *)lasso;
- (void)didExitLasso:(BCLasso *)lasso;

@end

@interface BCLassoManager : NSObject

- (void)addLassoKeys:(NSArray *)lassoKeys;
- (void)removeLassoKeys:(NSArray *)lassoKeys;
- (NSArray *)lassoKeys;

@property (nonatomic) BOOL enabled;
@property (nonatomic, weak) id <BCLassoManagerDelegate> delegate;

+ (BCLassoManager *)sharedManager;

@end

/*
 Value Type Keys
 */

extern NSString * const BCKLassoValueTypeDeviceIdKey;
extern NSString * const BCKLassoValueTypeTransactionKey;
extern NSString * const BCKLassoValueTypeAmountKey;
extern NSString * const BCKLassoValueTypeCodeKey;
extern NSString * const BCKLassoValueTypeOfferIdKey;
extern NSString * const BCKLassoValueTypeDeviceTimeKey;
extern NSString * const BCKLassoValueTypeReferenceIdKey;
extern NSString * const BCKLassoValueTypeAuxDataKey;
extern NSString * const BCKLassoValueTypeAccountUIDKey;
extern NSString * const BCKLassoValueTypeDigestKey;
extern NSString * const BCKLassoValueTypeFunctionKey;
extern NSString * const BCKLassoValueTypeMessageKey;
extern NSString * const BCKLassoValueTypeResponseCodeKey;

extern NSString * const BCKOfferTransactionTypeValueKey;
extern NSString * const BCKOfferTransactionTypeCodeKey;
extern NSString * const BCKOfferTransactionTypeDiscountKey;

extern NSString * const BCKLassoResponseCodeApproved;

extern unsigned char LassoDataTypeAlpha;

typedef NS_ENUM(NSUInteger, LassoFunctionType) {
    LassoFunctionTypeRedeem = 0x1,
    LassoFunctionTypeQuery
};

typedef NS_ENUM(NSUInteger, LassoTransactionType) {
    LassoTransactionTypeValue = 0x1,
    LassoTransactionTypeDiscount,
    LassoTransactionTypeCode
};

typedef NS_ENUM(NSUInteger, LassoValueType) {
    LassoValueTypeDeviceId                = 0x20,
    LassoValueTypeTransaction             = 0x21,
    LassoValueTypeAmount                  = 0x22,
    LassoValueTypeCode                    = 0x23,
    LassoValueTypeOfferId                 = 0x24,
    LassoValueTypeDeviceTime              = 0x25,
    LassoValueTypeReferenceId             = 0x26,
    LassoValueTypeAuxData                 = 0x27,
    LassoValueTypeAccountHolderUID        = 0x28,
    LassoValueTypeDigest                  = 0x29,
    LassoValueTypeResponseCode            = 0x2A,
    LassoValueTypeMessage                 = 0x2B,
    LassoValueTypeFunction                = 0x04
};

/*
 TODO: Remove Before Build For GitHub
 */

LassoTransactionType BCKLassoTransactionTypeForKey(NSString *key);
NSString * BCKLassoValueTypeKeyForEnum(LassoValueType valueType);
NSDictionary * BCKLassoParseData(NSData *data);

