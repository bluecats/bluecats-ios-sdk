//
//  BCLassoManager.h
//  BlueCatsSDK
//
//  Created by Zach Prager on 7/23/15.
//  Copyright (c) 2015 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BCBeacon, BCLassoManager, BCLasso;

///The `BCLassoManagerDelegate` protocol defines the methods used to receive lasso updates from a `BCLassoManager` object.
@protocol BCLassoManagerDelegate <NSObject>

@optional

///@name Getting a Lasso's Dictionary
/**
 *  Tells the delegate that a dictionary for the lasso object is present.
 *
 *  @param lassoManager The lasso manager object that generated the update event.
 *  @param lasso        The lasso object.
 *
 *  @return The dictionary for the `BCLasso` object.
 */
- (NSDictionary *)lassoManager:(BCLassoManager *)lassoManager
            dictionaryForLasso:(BCLasso *)lasso;

///@name Getting a Lasso's data request payload
/**
 *  Tells the delegate that a payload for the lasso object is present.
 *
 *  @param lassoManager The lasso manager object that generated the update event.
 *  @param lasso        The lasso object.
 *
 *  @return The data to send to the `BCLasso` object.
 */
- (NSData *)lassoManager:(BCLassoManager *)lassoManager
     dataRequestForLasso:(BCLasso *)lasso;

///@name Redemptions
/**
 *  Tells the delegate that the lasso manager did redeem the specified dictionary for the included lasso object and received the specified response.
 *
 *  @param lassoManager       The lasso manager object that generated the update event.
 *  @param dictionary         The dictionary that was redeemed.
 *  @param lasso              The lasso object.
 *  @param responseDictionary The redemption response dictionary.
 */
- (void)lassoManager:(BCLassoManager *)lassoManager
 didRedeemDictionary:(NSDictionary *)dictionary
            forLasso:(BCLasso *)lasso
            response:(NSDictionary *)responseDictionary;
/**
 *  Tells the delegate that the provided dictionary did fail to be redeemed. Includes the lasso object and corresponding error.
 *
 *  @param lassoManager The lasso manager object that generated the update event.
 *  @param dictionary   The dictionary for which redemption failed.
 *  @param lasso        The lasso object.
 *  @param error        The error describing what occurred.
 */
- (void)lassoManager:(BCLassoManager *)lassoManager
didFailToRedeemDictionary:(NSDictionary *)dictionary
            forLasso:(BCLasso *)lasso
               error:(NSError *)error;
/**
 *  Tells the delegate that redemption request for the specified lasso should begin.
 *
 *  @param lassoManager The lasso manager object that generated the update event.
 *  @param lasso        The lasso object for which the redemption request should begin.
 *
 *  @return The `BOOL` value indicating whether a redemption request should begin. If `YES`, the redemption should begin; `NO` if it should not begin.
 */
- (BOOL)shouldBeginRedemptionRequest:(BCLassoManager *)lassoManager
                    forLasso:(BCLasso *)lasso;

///@name Lasso Discovery
/**
 *  Tells the delegate that the device did enter the range of the specified BCLasso.
 *
 *  @param lasso The `BCLasso` object entered by the device.
 */
- (void)didEnterLasso:(BCLasso *)lasso;
/**
 *  Tells the delegate that the device is still in range of the specified BCLasso.
 *
 *  @param lasso The `BCLasso` object entered by the device.
 */
- (void)didRangeLasso:(BCLasso *)lasso;
/**
 *  Tells the delegate that the device did exit the range of the specified BCLasso.
 *
 *  @param lasso The `BCLasso` object exited by the device.
 */
- (void)didExitLasso:(BCLasso *)lasso;

@end

///The `BCLassoManager` class defines an object that represents the central point for managing lasso based interactions.
@interface BCLassoManager : NSObject

///@name Lasso Key Methods
/**
*  Adds the specified lasso keys to the lasso manager.
*
*  @param lassoKeys An array of lasso keys to add to the manager.
*/
- (void)addLassoKeys:(NSArray *)lassoKeys;
/**
 *  Removes the specified lasso keys from the lasso manager.
 *
 *  @param lassoKeys An array of lasso keys to remove from the manager.
 */
- (void)removeLassoKeys:(NSArray *)lassoKeys;
/**
 *  Returns the lasso keys present in the lasso manager.
 *
 *  @return An array of lasso keys present in the lasso manager.
 */
- (NSArray *)lassoKeys;

///@name Enabling the Manager

///A `BOOL` value indicating whether the lasso manager object is enabled.  `YES` if the manager is enabled; `NO` if the manager is disabled.
@property (nonatomic) BOOL enabled;

///@name Accessing the Delegate

///The delegate object to receive update events.
@property (nonatomic, weak) id <BCLassoManagerDelegate> delegate;

///@name Shared Manager
/**
 *  Returns the shared lasso manager object.
 *
 *  @return A shared lasso manager object.
 */
+ (BCLassoManager *)sharedManager;

@end

///@name Value Type Keys
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

/**
 *  These constants indicate the type of lasso function being performed.
 */
typedef NS_ENUM(NSUInteger, LassoFunctionType) {
    /**
     *  The function is a redemption.
     */
    LassoFunctionTypeRedeem = 0x1,
    /**
     *  The function is a query.
     */
    LassoFunctionTypeQuery,
    /**
     *  The function is a redemption.
     */
    LassoFunctionTypeMessage,
};

/**
 *  These constants indicate the transaction type.
 */
typedef NS_ENUM(NSUInteger, LassoTransactionType) {
    /**
     *  The transaction type represents a value.
     */
    LassoTransactionTypeValue = 0x1,
    /**
     *  The transaction type represents a discount.
     */
    LassoTransactionTypeDiscount,
    /**
     *  The transaction type is determined by a custom code.
     */
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
    LassoValueTypeFunction                = 0x04,
    LassoValueTypeSequence                = 0x2C
};

