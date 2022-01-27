//
//  BCEvent.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 30/06/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import "BCJSONModel.h"
#import <Foundation/Foundation.h>

///The `BCEvent` class defines an object that represents an event that satisifed the `BCEventFilters` of a `BCTrigger`.
@interface BCEvent : BCJSONModel<NSCopying>

///@name Event Properties

///Unique identifier for the event.
@property (nonatomic, copy) NSString *eventID;
///The event identifier set set on creation.
@property (nonatomic, copy) NSString *eventIdentifier;
///The event name.
@property (nonatomic, copy) NSString *eventName;
///The date the event began.
@property (nonatomic, copy) NSDate *beganAt;
///The date the event ended.
@property (nonatomic, copy) NSDate *endedAt;
@end
