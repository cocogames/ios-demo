//
//  CSJTrackerHeader.h
//  CSJAdSDK
//
//  Created by Siwant on 2019/11/13.
//  Copyright © 2019 bytedance. All rights reserved.
//

//上报触发场景
typedef NS_ENUM(NSInteger, BUTrackerClockType) {
    BUTrackerClockTypeNow                       = 1,
    BUTrackerClockTypeInit                      = 1 << 1,
    BUTrackerClockTypeTimer                     = 1 << 2,
    BUTrackerClockTypeAppWillEnterForground     = 1 << 3,
    BUTrackerClockTypeAppDidEnterBackground     = 1 << 4
};

typedef NS_ENUM(NSInteger, BUTrackerType) {
    BUTrackerType_Applog     = 1, // 广告埋点
    BUTrackerType_Stats      = 2  // 性能埋点
};

/**************** applog***************/
static NSString *const CSJEventTrackFileName = @"BUEventTrack";
static const char *    BUTrackerSendQueueName = "CSJAdSDK.applog.sending";
static NSString *const CSJTrackerCleanPostKey = @"CSJTrackerCleanPostKey";

static NSString *const CSJTrackerWillCleanNotification = @"CSJTrackerWillCleanNotification";
static NSString *const CSJTrackerDidCleanNotification = @"CSJTrackerDidCleanNotification";
static NSString *const CSJTrackerSentNotification = @"CSJTrackerSentNotification";



/**************** stats****************/
static NSString *const CSJStatsTrackerFileName = @"CSJStatsTracker";
static const char *    BUStatsTrackerSendQueueName = "CSJAdSDK.stats.sending";
static NSString *const CSJStatsTrackerCleanPostKey = @"CSJStatsTrackerCleanPostKey";

static NSString *const CSJStatsTrackerWillCleanNotification = @"CSJStatsTrackerWillCleanNotification";
static NSString *const CSJStatsTrackerDidCleanNotification = @"CSJStatsTrackerDidCleanNotification";
static NSString *const CSJStatsTrackerSentNotification = @"CSJStatsTrackerSentNotification";

