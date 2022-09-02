//
//  CSJSplashBottomViewInterface.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/9/23.
//

#ifndef BUSplashBottomViewInterface_h
#define BUSplashBottomViewInterface_h

@class CSJSplashControlSlideAreaModel;

@protocol CSJSplashBottomViewInterface <NSObject>

@optional
/// 开屏合规第一行文字
- (NSString *)splashBottomViewTopClickText;
/// 开屏合规第二行文字
- (NSString *)splashBottomViewClickText;

/// 开屏合规第一行文字大小
- (CGFloat)splashBottomViewClickTopTextFontSize;
/// 开屏合规第二行文字大小
- (CGFloat)splashBottomViewClickTextFontSize;

/// 开屏合规算色
- (NSString *)splashBottomViewBtnBackgroundDestColor;

/// 开屏合规摇一摇幅度
- (CGFloat)splashBottomViewShakeAmplitude;

/// 宽
- (CGFloat)splashBottomViewAreaWidth;

/// 高
- (CGFloat)splashBottomViewAreaHeight;

/// 距离底部高度
- (CGFloat)splashBottomViewAreaBlankHeight;

/// 半屏开屏时距离底部高度
- (CGFloat)splashBottomViewHalfBlankHeight;

/// 滑动识别区域
- (CSJSplashControlSlideAreaModel *)slideArea;

/// 扭一扭触发阈值
- (NSInteger)twistRotationThreshold;

/// 摇一摇触发阈值
- (NSInteger)shakeValue;

/// 是否开启轻互动验证
- (BOOL)interactionValidate;

/// 上划样式可以触发点击的滑动长度
- (CGFloat)upSwipeThreshold;

@end

#endif /* BUSplashBottomViewInterface_h */
