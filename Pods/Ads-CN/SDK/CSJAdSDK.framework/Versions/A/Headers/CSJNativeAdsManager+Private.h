//
//  CSJNativeAdsManager+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/10/30.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJNativeAdsManager.h"
#import "CSJRewardedVideoPreloaderManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJNativeAdsManager ()

- (void)setMopubAdMarkUp:(NSString *)adm successLoadVideo:(successLoadVideo)videoSucess;

/// 广告请求(建议不超过3个)
/// @param count 请求数值(最多10个)
/// @param invokeByPublisher 是否由媒体开发者调用
- (void)loadAdDataWithCount:(NSInteger)count invokeByPublisher:(BOOL)invokeByPublisher;

#pragma mark - 预加载中间模板信息
- (void)preLoadMiddlePageWithAd:(CSJNativeAd *)nativeAd;


@end

NS_ASSUME_NONNULL_END
