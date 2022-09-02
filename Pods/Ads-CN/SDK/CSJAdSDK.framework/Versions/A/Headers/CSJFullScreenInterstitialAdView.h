//
//  CSJFullScreenInterstitialAdView.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/12/24.
//

#import <UIKit/UIKit.h>
#import "CSJPlayerPublicDefine.h"
@class CSJMaterialMeta;
@class CSJAdSlot;
@class CSJFullScreenInterstitialAdView;
@class CSJVideoAdView;
/// 插屏事件代理
@protocol CSJFullScreenInterstitialAdDelegate <NSObject>

@optional

/** -----------点击关闭、dislike、logo事件回调----------- */

/// 点击关闭按钮
- (void)fullScreenInterstitialAdViewDidTapCloseButton:(CSJFullScreenInterstitialAdView * _Nonnull)interstitialAdView;
/// 点击dislike面板
- (void)fullScreenInterstitialAdViewDidTapDislikeButton:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView;

/// 点击logo
- (void)fullScreenInterstitialAdViewDidTapLogoImageView:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView;
/// 点击下载bar，只有横屏样式有下载bar
- (void)fullScreenInterstitialAdView:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView downloadBarTapped:(id _Nullable )sender extraDic:(NSDictionary *_Nullable)extraDic;
/// 点击下载按钮，竖版样式的下载按钮
- (void)fullScreenInterstitialAdView:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView downloadButtonTapped:(id _Nullable )sender extraDic:(NSDictionary *_Nullable)extraDic;

/// 整个广告的点击事件
- (void)fullScreenInterstitialAdViewDidClick:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView extraDic:(NSDictionary *_Nullable)extraDic;
/// 插屏比例，视频准备播放
- (void)fullScreenInterstitialAdPlayerReadyToPlay:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView;
/// 插屏比例，视频播放完成
- (void)fullScreenInterstitialAdPlayerDidPlayFinish:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView;
/// 插屏比例，视频加载失败
- (void)fullScreenInterstitialAdView:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView videoDidLoadFailWithError:(NSError *_Nullable)error;
/// 插屏比例，视频view点击事件
- (void)fullScreenInterstitialAdVideoViewDidClick:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView;

/// 插屏比例，视频状态回调
- (void)fullScreenInterstitialAdView:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView videoStateDidChanged:(BUPlayerPlayState)playerState;

/** -----------全屏图片点击事件回调----------- */

/// 由 SDK 端上控制的可点击区域，默认图片、icon、CTA button、描述等服务端下发的物料 都可以点击进行跳转回调
- (void)fullScreenImageAdDidClick:(CSJFullScreenInterstitialAdView *_Nonnull)interstitialAdView extraDic:(NSDictionary *_Nullable)extraDic;
@end

NS_ASSUME_NONNULL_BEGIN
@interface CSJFullScreenInterstitialAdView : UIView
@property (nonatomic, weak) id<CSJFullScreenInterstitialAdDelegate> intersitialDelegate;
- (CSJVideoAdView *)interstitialPlayer;

+ (instancetype)fullScreenInterstitialAdViewWithMaterial:(CSJMaterialMeta *)materialMeta adSlot:(CSJAdSlot *)adSlot;
@end

NS_ASSUME_NONNULL_END
