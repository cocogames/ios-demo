//
//  BURaptorTracker+Private.h
//  Pods
//
//  Created by Rush.D.Xzj on 2022/5/16.
//

#import "BURaptorTrackerDefine.h"

typedef NS_OPTIONS(NSInteger, BURaptorTrackerLogSubType) {
    BURaptorTrackerLogSubType_Normal        =           1 << 0,
    BURaptorTrackerLogSubType_Save          =           1 << 1,
    BURaptorTrackerLogSubType_Send          =           1 << 2,
    BURaptorTrackerLogSubType_HandleRequest          =           1 << 3,
};

@class BURaptorTrackerModel;

@interface BURaptorTracker ()

// 日志队列
@property (nonatomic, strong) dispatch_queue_t logSerialQueue;

@property (nonatomic, assign) NSInteger sdkEventIndex;

@property (nonatomic, assign) NSInteger sdkEventValidIndex;

#pragma mark - Class Method
+ (NSString *)sessionId;


#pragma mark - Log
- (void)_logWithMessage:(NSString *)message queueType:(BURaptorTrackerQueueType)queueType subType:(BURaptorTrackerLogSubType)subType;

#pragma mark - Override(Required)
- (BURaptorTrackerType)raptorTrackerType;
- (Class)raptorModelClass;
- (NSString *)eventKey;


#pragma mark - Override(Notification Name)
- (NSString *)willCleanNotificationName;
- (NSString *)didCleanNotificationName;
- (NSString *)sentNotificationName;



#pragma mark - Override(LifeCycle)
- (void)eventWillSaveWithModel:(BURaptorTrackerModel *)model;
- (void)eventDidSaveFailedWithModel:(BURaptorTrackerModel *)model error:(NSError *)error;
- (void)eventDidSaveSuccessWithModel:(BURaptorTrackerModel *)model;
- (void)eventDidSaveWithModel:(BURaptorTrackerModel *)model;

- (void)eventWillSendWithModelArray:(NSArray *)modelArray;

- (void)eventDidSendSuccessWithModelArray:(NSArray *)modelArray valid:(BOOL)valid logid:(NSString *)logid;
- (void)eventDidSendFailedWithModelArray:(NSArray *)modelArray error:(NSError *)error;
- (void)eventHaveSendResultWithModelArray:(NSArray *)modelArray;
- (void)eventDidSendWithModelArray:(NSArray *)modelArray;


- (NSDictionary *)extraInfoBeforeSend;
#pragma mark - Setting
- (NSInteger)adlog_batch;
- (NSInteger)adlog_interval;
- (NSInteger)adlog_exception_batch;

@end


