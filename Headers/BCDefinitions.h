//
//  BCDefinitions.h
//  BlueCatsSDK
//
//  Created by Cody Singleton on 10/14/15.
//  Copyright © 2015 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BCSyncStatus)
{
    //No relevant request has been made to the server
    BCSyncStatusNotSynced,
    //Relevant request has been made to the server and this object was not included
    BCSyncStatusUnauthorized,
    //Basic access information has been synced
    BCSyncStatusAccessSynced,
    //Full data has been synced
    BCSyncStatusSynced,
    //Data has been restored from local DB
    BCSyncStatusRestored,
    //Whatever data has been synced for this object is now stale
    BCSyncStatusExpired
};

@interface BCDefinitions : NSObject

@end
