//
//  CSJVideoAdTracker+Preload.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/3/5.
//

#import "CSJVideoAdTracker.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJVideoAdTracker (Preload)

#pragma mark - 预加载打点

+ (NSString *)rewardVideoTagBySlotType:(BUAdSlotAdType)adType;

/// 预加载视频
/// @param trackTag 页面 tag
/// @param meta 广告信息
+ (void)reportVideoPreloadBeginWithTag:(NSString *)trackTag videoAdMeta:(CSJMaterialMeta *)meta;

/// 预加载视频成功
/// @param trackTag 页面Tag
/// @param meta 广告信息
+ (void)reportVideoPreloadSuccessWithTag:(NSString *)trackTag videoAdMeta:(CSJMaterialMeta *)meta;

/// cancel预加载视频
/// @param trackTag 页面Tag
/// @param meta 广告信息
+ (void)reportPreloadVideoCancelWithTag:(NSString *)trackTag videoAdMeta:(nonnull CSJMaterialMeta *)meta;

/// 预加载视频失败
/// @param trackTag 页面Tag
/// @param meta 广告信息
+ (void)reportVideoPreloadFaildWithTag:(NSString *)trackTag videoAdMeta:(CSJMaterialMeta *)meta;

@end

NS_ASSUME_NONNULL_END
