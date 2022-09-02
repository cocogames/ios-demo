//
//  CSJNativeExpressInterstitialAd+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/10/14.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJNativeExpressInterstitialAd.h"
#import "CSJNativeExpressAdManager.h"
#import "CSJNativeExpressInterstitialAdViewController.h"
#import "CSJNativeExpressAdView+Interval.h"
#import "CSJAdSDKError.h"
#import "CSJNativeExpressAdManager+Block.h"
#import "CSJUSettingService.h"
#import "CSJUnionMacros.h"
#import "CSJAdSlot+Private.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJNativeExpressInterstitialAd ()

@property (nonatomic, strong, nullable) CSJNativeExpressAdManager *nativeExpressAdManager;
@property (nonatomic, strong, nullable) CSJNativeExpressAdView *expressAdView;
@property (nonatomic, assign) CGSize adSize;

// 默认是动态布局，外界可以更改
@property (nonatomic, assign) BUAdSlotRenderType realSlotRenderType;


#pragma mark - safeDelegate
- (void)safeDelegate_nativeExpresInterstitialAdDidLoad:(CSJNativeExpressInterstitialAd *)interstitialAd;
- (void)safeDelegate_nativeExpresInterstitialAd:(CSJNativeExpressInterstitialAd *)interstitialAd didFailWithError:(NSError * __nullable)error;
- (void)safeDelegate_nativeExpresInterstitialAdRenderSuccess:(CSJNativeExpressInterstitialAd *)interstitialAd;
- (void)safeDelegate_nativeExpresInterstitialAdRenderFail:(CSJNativeExpressInterstitialAd *)interstitialAd error:(NSError * __nullable)error;
- (void)safeDelegate_nativeExpresInterstitialAdWillVisible:(CSJNativeExpressInterstitialAd *)interstitialAd;
- (void)safeDelegate_nativeExpresInterstitialAdDidClick:(CSJNativeExpressInterstitialAd *)interstitialAd;
- (void)safeDelegate_nativeExpresInterstitialAdWillClose:(CSJNativeExpressInterstitialAd *)interstitialAd;
- (void)safeDelegate_nativeExpresInterstitialAdDidClose:(CSJNativeExpressInterstitialAd *)interstitialAd;
- (void)safeDelegate_nativeExpresInterstitialAdDidCloseOtherController:(CSJNativeExpressInterstitialAd *)interstitialAd interactionType:(BUInteractionType)interactionType;
@end

NS_ASSUME_NONNULL_END
