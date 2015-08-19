//
//  BCTrigger.h
//  BlueCatsSDK
//
//  Created by Damien Clarke on 1/07/2014.
//  Copyright (c) 2014 BlueCats. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BCEventFilter.h"

@interface BCTrigger : NSObject<NSCopying>

@property (nonatomic, copy) NSString *eventIdentifier;
@property (nonatomic, copy) NSString *eventName;
@property (nonatomic, assign) NSInteger repeatCount;
@property (nonatomic, copy) NSDate *validFrom;
@property (nonatomic, copy) NSDate *expiresAt;
@property (nonatomic, copy) NSDictionary *filterDescriptors;

- (id)initWithIdentifier:(NSString*) identifier andFilters:(NSArray*)filters;

- (void)addFilter:(id<BCEventFilter>) filter;
- (void)clearFilters;
- (NSArray *) allFilters;

@end
