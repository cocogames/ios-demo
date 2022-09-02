//
//  CSJRewardVideoWebDefine.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/27.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef BURewardVideoWebDefine_h
#define BURewardVideoWebDefine_h

@class CSJRewardedVideoWebViewController;
@protocol CSJRewardedVideoWebViewDelegate <NSObject>

@optional
// 点击关闭按钮，关闭视频广告
- (void)rewardedVideoAdClose;

// 点击下载按钮，下载APP
- (void)rewardedVideoH5AdDidClickNeedJump:(BOOL)needJump;

// 加载完毕当前页面
- (void)bu_webviewLoadFinish:(CSJRewardedVideoWebViewController *)webViewController;

/// pure playable ad callback to tell delegate that h5 could send reward
- (void)purePlayableSendRewardFromH5Callback;

/// 纯playable移除原生loading页面
- (void)purePlayableRemoveLoadingByJSB;

/// 相关推荐点击
- (void)rewardedVideoWebViewControllerClick:(CSJRewardedVideoWebViewController *)vc clickInfo:(NSDictionary *)info;

/// 纯playable 音量状态的改变
- (void)rewardedVideoWebViewControllerVolumeChange:(CSJRewardedVideoWebViewController *)vc isMute:(BOOL )isMute;

/// dislike
- (void)rewardedVideoWebViewControllerDislikeClick:(CSJRewardedVideoWebViewController *)vc;

/// 点击跳过(纯playable)
- (void)rewardedVideoWebViewControllerSkipClick:(CSJRewardedVideoWebViewController *)vc;

/// 点击关闭
- (void)rewardedVideoWebViewControllerCloseClick:(CSJRewardedVideoWebViewController *)vc;

/// 跳转endcard
- (void)rewardedVideoWebViewControllerJumpEndcard:(CSJRewardedVideoWebViewController *)vc;

/// 前置pl返回视频播放
- (void)rewardedVideoWebViewControllerBackVideo:(CSJRewardedVideoWebViewController *)vc;

- (void)rewardedVideoWebViewControllerOpenUrlWithParams:(NSDictionary *)params;


/// pl渲染失败
/// @param vc web
- (void)playableRenderFaild:(CSJRewardedVideoWebViewController *)vc;

/// 显示电商聚合页挽留弹窗
/// @param param remainTime
- (void)showRewardBrowseEcomAlert:(NSDictionary *)param;

/// 轻互动跳过时长
/// @param skipDuration 时长 单位s
- (void)rewardedVideoInteractiveSkip:(NSInteger)skipDuration;

/// 4100 h5控制native按钮是否展示
- (void)updateNativeTitleBar:(BOOL)show;


/// 当前视频进度 单位ms
- (NSInteger)currentVideoProgress;


/// 当前视频进度
/// @param progress 进度 单位ms
- (void)setCurrentVideoProgress:(NSInteger)progress;


/// 发送playable进阶奖励
- (void)sendPlayableReward;
@end


#endif /* BURewardVideoWebDefine_h */
