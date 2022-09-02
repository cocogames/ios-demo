//
//  CSJSplashControlAnimation.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/7/9.
//

#import <Foundation/Foundation.h>
#import "CSJAnimationConfiguration.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJSplashControlAnimation : NSObject
/// 缩放动画
/// @param duraiton 时长
/// @param scale 缩放因子
+ (CAKeyframeAnimation *)splashControlZoomAnimationWithDuration:(CGFloat)duraiton scale:(CGFloat)scale;

/// 算色动画
/// @param fromValue 算色起始值
/// @param toValue 算色终值
+ (CABasicAnimation *)splashControlDestColorAnimationFromValue:(id)fromValue toValue:(id)toValue;

/// 摇一摇动画
+ (CAAnimationGroup *)splashControlShakeAnimation;

/// 轻扫动画
+ (CAAnimationGroup *)splashControlSweepAnimation;

/// 箭头动画
/// @param opacityValues 箭头动画透明度参数
/// @param positionValues 箭头动画位置参数
+ (CAAnimationGroup *)arrowAnimationGroupWithOpacity:(NSArray<NSValue *> *)opacityValues position:(NSArray<NSValue *> *)positionValues;


/// 波纹动画
/// @param configuration 动画参数配置

+ (CAAnimationGroup *)splashControlRippleAnimationWithConfiguration:(CSJAnimationConfiguration *)configuration;


/// Animaiton with configuration
+ (nullable CAAnimation *)animationWithConfiguration:(CSJAnimationConfiguration *)configuration;
+ (CAKeyframeAnimation *)keyFrameAnimationWithConfiguration:(CSJAnimationConfiguration *)configuration;
+ (CABasicAnimation *)baseAnimationWithConfiguration:(CSJAnimationConfiguration *)configuration;
+ (CAAnimationGroup *)groupAnimationWithConfiguration:(CSJAnimationConfiguration *)configuration;

///----------------轻互动----------------------
+ (CAAnimationGroup *)interactionGradientTrailAnimationGroup;
+ (CAAnimationGroup *)interactionRippleTranslateGradientAnimationGroup;
+ (CAAnimationGroup *)interactionHandleZoomOutAnimationGroup;
+ (CAAnimationGroup *)interactionUnlockAnimationWithConfiguration:(CSJAnimationConfiguration *)configuration;
@end

NS_ASSUME_NONNULL_END
