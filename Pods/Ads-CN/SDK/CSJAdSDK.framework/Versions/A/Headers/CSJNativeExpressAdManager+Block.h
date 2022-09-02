//
//  CSJNativeExpressAdManager+Block.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/5/19.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJNativeExpressAdManager.h"
#import "CSJNativeAd.h"
#import "CSJNativeAd+Private.h"
#import "CSJRewardedVideoPreloaderManager.h"

NS_ASSUME_NONNULL_BEGIN
@interface CSJNativeExpressAdManager () //不方便对外暴露回调时用block实现
@property (nonatomic, copy) dispatch_block_t dismissBlock;         //插屏页面点击广告时的页面关闭
@property (nonatomic, copy) dispatch_block_t videoCachedSuccess;   //激励视频、全屏视频视频下载成功
// 开屏总超时时间
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;
// 保存请求的物料为开屏兜底做准备
@property (nonatomic, strong, nullable) NSArray<CSJNativeAd *> *nativeAdDataArray;
// 用来保存打点所需的参数
@property (nonatomic, strong) NSDictionary *extraInfo;

// 一次只能获取一个
- (void)loadAdData;

/// 广告请求(建议不超过3个)
/// @param count 请求数值(最多3个)
/// @param invokeByPublisher 是否由媒体开发者调用
- (void)loadAdDataWithCount:(NSInteger)count invokeByPublisher:(BOOL)invokeByPublisher;

- (void)setMopubAdMarkUp:(NSString *)adm successLoadVideo:(successLoadVideo)videoSucess;

@end

NS_ASSUME_NONNULL_END
