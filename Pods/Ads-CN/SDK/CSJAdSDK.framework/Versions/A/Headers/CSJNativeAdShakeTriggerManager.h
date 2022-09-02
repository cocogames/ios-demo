//
//  CSJNativeAdShakeTriggerManager.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/6/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJNativeAd;

@interface CSJNativeAdShakeTriggerManager : NSObject
+ (instancetype)manager;

/// 注册广告以及视图容器
/// @param containerView 广告视图容器
/// @param nativeAd 广告对象
- (void)registerWithContainerView:(nonnull UIView *)containerView nativeAd:(CSJNativeAd *)nativeAd;

/// 根据广告对象注销广告视图
/// @param nativeAd 广告对象
- (void)unregisterWithNativeAd:(nonnull CSJNativeAd *)nativeAd ;

/// 开启摇一摇监听
/// @param amplitude 摇一摇幅度
+ (void)startAccelerometerWithNativeAd:(nonnull CSJNativeAd *)nativeAd;

/// 停止摇一摇监听
+ (void)stopAccelerometer;

@end

NS_ASSUME_NONNULL_END
