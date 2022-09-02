//
//  SSEventProxy.h
//  Tracker
//
//  Created by fengyadong on 17-3-14.
//  Copyright (c) 2017 toutiao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJTrackerClock.h"
#import "CSJTrackerSender.h"
#import "CSJTrackerStorage.h"
#import "CSJTrackerCleaner.h"
#import "CSJTrackerHeader.h"

@interface CSJTrackerProxy : NSObject
@property (nonatomic, strong, readonly) CSJTrackerCleaner *trackerCleaner;
@property (nonatomic, strong, readonly) CSJTrackerStorage *trackerStore;
@property (nonatomic, strong, readonly) CSJTrackerSender *trackerSender;
@property (nonatomic, strong, readonly) CSJTrackerClock *trackClock;
@property (nonatomic, assign, readonly) BUTrackerType trackerType;
@property (nonatomic, weak) id tracker;

- (instancetype)initWithStoreName:(NSString *)storeName
                        queueName:(const char *)queueName
            willcleanNotification:(NSString *)willcleanNotification
             didcleanNotification:(NSString *)didcleanNotification
                 sentNotification:(NSString *)sentNotification
              notificationTypeKey:(NSString *)notificationTypeKey   
                        clockType:(NSInteger)clockType                  // now/init/Timer/Background/Foreground
                      trackerType:(BUTrackerType)trackerType
                         eventKey:(NSString *)eventKey;                 // 第一层json的key值

    
/// 包括 持久化 + clean + send
- (void)startHandleTrack:(NSDictionary *)data clockType:(NSInteger)clockType;

/// 包括 clean + send过程
- (void)startCleanFromType:(BUTrackerClockType)fromType;

/// 包括 send过程
- (BOOL)startSendTrack:(NSDictionary *)track v1TrackIDs:(NSArray *)v1TrackIDs;

/// 结束发送
- (void)finishSend;

+ (NSDictionary *)trackHeaderParameters;
@end

