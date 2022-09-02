//
//  CSJNativeExpressFullscreenVideoAd+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/6.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJNativeExpressFullscreenVideoAd.h"
#import "CSJRewardedVideoModel.h"
#import "CSJAdSlot+Private.h"
#import "CSJNativeExpressRewardedVideoAdView.h"
#import "CSJDislikeContext.h"
#import "CSJAdSlot+Private.h"
#import "CSJNativeExpressAdManager.h"
#import "CSJNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJNativeExpressFullscreenVideoAd ()
@property (nonatomic, strong) CSJNativeExpressAdManager *nativeExpressAdManager;
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, assign) BOOL isShow;
/// 纯playable使用的广告物料
@property (nonatomic, strong, nullable) CSJNativeAd *purePlayableNativeAd;
// 普通或者视频playable使用的广告物料所在的动态布局view
@property (nonatomic, strong, nullable) CSJNativeExpressRewardedVideoAdView *expressAdView;

@property (nonatomic, strong) CSJDislikeContext *dislikeContext;
@property (nonatomic, assign) BOOL triggerNativeAdDidLoadCallback;
@property (nonatomic, assign) BOOL triggerNativeAdDidDownloadCallback;

// 默认是动态布局，外界可以更改
@property (nonatomic, assign) BUAdSlotRenderType realSlotRenderType;

@end

NS_ASSUME_NONNULL_END
