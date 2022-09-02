//
//  CSJTrackerCleaner.h
//  Tracker
//
//  Created by fengyadong on 17-3-14.
//  Copyright (c) 2017 toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJTrackerHeader.h"
@class CSJTrackerProxy;

NS_ASSUME_NONNULL_BEGIN

@interface CSJTrackerCleaner : NSObject
@property (nonatomic, strong, readonly) dispatch_queue_t sendingQueue;

- (instancetype)initWithQueueName:(const char *)queueName
            willcleanNotification:(NSString *)willcleanNotification
             didcleanNotification:(NSString *)didcleanNotification
                          typeKey:(NSString *)notificationTypeKey
                     trackerProxy:(CSJTrackerProxy *)trackerProxy
                         eventKey:(NSString *)eventKey;

- (void)startClean:(BUTrackerClockType)fromType;

@end

NS_ASSUME_NONNULL_END


