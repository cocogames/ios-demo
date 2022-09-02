//
//  CSJFullScreenInterstitialAdDelegate.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/1/24.
//

#ifndef BUInterstitialAdDelegate_h
#define BUInterstitialAdDelegate_h

@protocol CSJInterstitialAdDelegate <NSObject>
@optional
/// 全屏广告即将关闭
- (void)interstitialAdWillClose;

/// 全屏广告已关闭
- (void)interstitialAdDidClose;

/// 全屏广告被点击(插屏，全屏图片)
- (void)interstitialAdDidClick;


/// 广告内关闭AppStore回调
- (void)didCloseOtherControllerWithInteractionType:(BUInteractionType)interactionType;
@end

#endif /* BUFullScreenInterstitialAdDelegate_h */
