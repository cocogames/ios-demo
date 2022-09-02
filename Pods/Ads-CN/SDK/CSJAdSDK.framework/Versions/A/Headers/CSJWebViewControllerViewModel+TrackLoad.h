//
//  CSJWebViewControllerViewModel+TrackLoad.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJWebViewControllerViewModel.h"

typedef NS_ENUM(NSInteger, BUlandscapeStatus) {
    BUlandscapeStatus_Start = 0,
    BUlandscapeStatus_loading = 1,
    BUlandscapeStatus_finish = 2,
    BUlandscapeStatus_fail = 3
};

NS_ASSUME_NONNULL_BEGIN

@interface CSJWebViewControllerViewModel (TrackLoad)
@property (nonatomic, strong, nullable) NSDate *startdate;
@property (nonatomic, assign) BUlandscapeStatus currentStatus;
@property (nonatomic, assign) BUlandscapeStatus backgroundStatus;
@property (nonatomic, assign) NSInteger js_max_scroll_percent;

/// 是否出现了一次Finish
@property (nonatomic, assign) BOOL isTrackLoad_Finish;
/// 是否打点有结果，只要出现finish或者fail就算YES
@property (nonatomic, assign) BOOL isTrackLoad_result;
/// 是否第一次上报Load_start
@property (nonatomic, assign) BOOL isFirstLoad_start;
/// load失败的error
@property (nonatomic, strong) NSError *loadFailError;
/// 正在加载页面时候关闭页面
@property (nonatomic, assign) BOOL isLoadingAndClose;

- (void)trackOpenWithTag:(NSString *)tag;
- (void)trackLoadStartWith:(BUlandscapeStatus)status tag:(NSString *)tag;
- (void)trackLoading;
- (void)trackLoadFinishWithTag:(NSString *)tag;
- (void)trackLoadFailWithError:(NSError *)error tag:(NSString *)tag;
- (void)trackStayWithTag:(NSString *)tag;
- (void)trackShow;
- (void)trackEnterForeground;
- (void)trackCloseWith:(BUlandscapeStatus)status tag:(NSString *)tag;

@end

NS_ASSUME_NONNULL_END
