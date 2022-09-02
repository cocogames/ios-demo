//
//  CSJSplashBottomBaseComponentView.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/9/15.
//

#import <UIKit/UIKit.h>
#import "CSJMaterialMeta+Private.h"
#import "CSJSplashBottomViewInterface.h"
NS_ASSUME_NONNULL_BEGIN

#define BUSplashBottomMask_arrowW 14
#define BUSplashBottomMask_heightMargin 30
#define BUSplashBottomMask_bottomMargin 0

/// 开屏底部合规样式基类
@interface CSJSplashBottomBaseComponentView : UIView
@property (nonatomic, strong) id<CSJSplashBottomViewInterface> configuration;
/// 默认合规标题
@property (nonatomic, strong) UILabel *tipLabel;
/// 当有两行文字时用到, 顶部文字
@property (nonatomic, strong) UILabel *tipTitleLabel;
/// 轻扫动画layer
@property (nonatomic, strong) CAGradientLayer *swipeLayer;
@property (nonatomic, copy) void(^actionBlock)(void);

/// 底部合规动画样式
/// @param configuration 广告动画配置
- (instancetype)initWithComponentConfiguration:(id<CSJSplashBottomViewInterface>)configuration;

/// 开始动画    注意：需要子类重写
- (void)startSplashBottomAnimation;

/// 停止移除动画    注意：需要子类重写
- (void)stopSplashBottomAnimation;

/// 当前视图的frame      注意：需要子类重写
/// @param containerFrame 父视图的frame
- (CGRect)splashBottomFrameWithContainerFrame:(CGRect)containerFrame;

/// 当前视图距离底部高度      注意：不不不需要子类重写
/// @param containerFrame 父视图的frame
- (CGFloat)splashBottomBlankHeightWithContainerFrame:(CGRect)containerFrame;
@end

NS_ASSUME_NONNULL_END
