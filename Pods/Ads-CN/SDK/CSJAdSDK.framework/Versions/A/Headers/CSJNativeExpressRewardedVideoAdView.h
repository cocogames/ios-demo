//
//  CSJNativeExpressRewardedVideoAdView.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/8/6.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJNativeExpressAdView.h"
#import "CSJNativeExpressAdView+Interval.h"
@class CSJNativeExpressRewardedVideoAdView;
@class CSJDislikeContext;

NS_ASSUME_NONNULL_BEGIN

@class BUPlayer;
@protocol CSJNativeExpressRewardedVideoAdViewDelegate <NSObject>
@optional
- (void)nativeExpressRewardedVideoDidPlayRewardTime:(BUPlayer *)player;
- (void)nativeExpressRewardedVideoDidPlayFinish:(BUPlayer *)player error:(NSError *_Nullable)error;
- (void)switchToWebViewController:(BOOL)isSkip;
- (void)dismissCurrentViewControllerIsSkip:(BOOL)isSkip;
//wyl3600:激励全屏支持前置打开试玩落地页
- (void)nativeExpressRewardedVideoPushPlayableLandingPage;
- (NSDictionary *)nativeExpressInteractiveFinished:(NSDictionary *)param;
/// 在 playable 停留的时长
- (NSTimeInterval)playableStayDuration;
/// 4600 "再看一个"入口前置传递jsb "rewardPlayAgain" 事件
- (void)nativeExpressRewardedPlayAgain;
@end

@interface CSJNativeExpressRewardedVideoAdView : CSJNativeExpressAdView

@property (nonatomic, weak) id<CSJNativeExpressRewardedVideoAdViewDelegate> delegate;


@property (nonatomic, strong) CSJDislikeContext *dislikeContext;

@property (nonatomic, assign) BOOL isSkipTap;
@property (nonatomic, assign) BOOL isSkipVideoDisplay;//是否真正的跳过了激励视频的播放
- (void)checkToVerifyServerRewardIsNeedWatchPercent:(BOOL)isNeed;

/// 3900 轻互动跳过激励观看时长 默认0
@property (nonatomic, assign) NSInteger skipDuration;

@property (nonatomic, assign) BOOL hasVerifyServerReward;

- (void)stopTimers;

@end

NS_ASSUME_NONNULL_END
