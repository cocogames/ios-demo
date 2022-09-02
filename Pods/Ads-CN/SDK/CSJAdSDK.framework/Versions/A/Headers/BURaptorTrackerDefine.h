//
//  BURaptorTrackerDefine.h
//  Pods
//
//  Created by Rush.D.Xzj on 2022/5/23.
//

#ifndef BURaptorTrackerDefine_h
#define BURaptorTrackerDefine_h


#pragma mark - Notification Name

typedef NS_ENUM(NSInteger, BURaptorTrackerType) {
    BURaptorTrackerType_Applog,
    BURaptorTrackerType_Stats,
};

typedef NS_ENUM(NSInteger, BURaptorTrackerQueueType) {
    BURaptorTrackerQueueType_unknown,
    BURaptorTrackerQueueType_database,
};

// 内部逻辑，移除后台任务需要用到的，当前还没有这个功能
static NSString *const BURaptorTracker_kNotificationTrackSendFinish =  @"kNotificationTrackSendFinish";


/**
 *  Applog和Stats网络上报的三个时机点
 *  WillClean： 将要发送网络请求的时机点
 *  DidClean: 不需要等待网络请求的时机点
 *  Sent:  等待网络请求结果的时机点
 *
 *
 **/
/**************** applog***************/
static NSString *const BUApplogRaptorTrackerWillCleanNotification = @"CSJTrackerWillCleanNotification";
static NSString *const BUApplogRaptorTrackerDidCleanNotification = @"CSJTrackerDidCleanNotification";
static NSString *const BUApplogRaptorTrackerSentNotification = @"CSJTrackerSentNotification";


/**************** stats****************/
static NSString *const BUStatsRaptorTrackerWillCleanNotification = @"CSJStatsTrackerWillCleanNotification";
static NSString *const BUStatsRaptorTrackerDidCleanNotification = @"CSJStatsTrackerDidCleanNotification";
static NSString *const BUStatsRaptorTrackerSentNotification = @"CSJStatsTrackerSentNotification";


#endif /* BURaptorTrackerDefine_h */
