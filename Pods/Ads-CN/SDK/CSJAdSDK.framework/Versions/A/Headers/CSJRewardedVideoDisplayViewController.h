//
//  CSJRewardedVideoDisplayViewController.h
//  CSJAdSDK
//
//  Created by gdp on 2018/1/14.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJMaterialMeta;
@class CSJAdSlot;
@class BUPlayer;
@class CSJDislikeContext;
@class CSJRewardedVideoTopBarView;

@protocol CSJRewardedVideoDisplayDelegate;

@interface CSJRewardedVideoDisplayViewController : UIViewController

/// 代理
@property (nonatomic, weak, nullable) id<CSJRewardedVideoDisplayDelegate> delegate;
/// 播放器
@property (nonatomic, strong, nullable) BUPlayer* player;

// 视图上方的倒计时和静音等的按钮
@property (nonatomic, strong) CSJRewardedVideoTopBarView *topBarView;

/// 自己是否旋转
@property (nonatomic, assign) BOOL  isTransform;

/// YES: 激励视频 NO:全屏视频
@property (nonatomic, assign) BOOL isRewardedVideo;

/// 是否已经打开appstore
@property (nonatomic, assign) BOOL storeKitOpened;

/**
 初始化函数
 */
- (instancetype)initViewControllerWithAd:(CSJMaterialMeta *)materialMeta  slot:(CSJAdSlot *)slot;

/**
 继续播放视频，当 SKStoreProductViewControll dismiss 时会调用
 */
- (void)continuePlay;

@end

@protocol CSJRewardedVideoDisplayDelegate <NSObject>

@optional

// 播放完成回调
- (void)playerDidPlayFinish:(BUPlayer *)player error:(NSError *)error;

//播放到80%回调
- (void)playerDidPlayedRewardTime:(nullable BUPlayer *)player duration:(NSTimeInterval)duration;

// 开始播放
- (void)playerReadyToPlay:(BUPlayer *)player;

// 点击下载
- (void)rewardedVideoClickDownload;

// 点击跳过
- (void)rewardedVideoClickSkip;

// 新插屏没有endcard，直接close，回调给业务层
- (void)fullScreenImageAndInterstitialDidClose;

/// 全屏插屏合并图片广告点击
- (void)fullScreenInsertitalAdDisplayViewDidClick;
@end

NS_ASSUME_NONNULL_END
