//
//  CSJDynamicInteractionAbstractDecorator.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/9/17.
//

#import "CSJDynamicAbstractDecorator.h"
#import "CSJDynamicBrickValuesModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicInteractionAbstractDecorator : CSJDynamicAbstractDecorator

+ (nullable instancetype)interactionDecoratorWithInfo:(CSJDynamicBrickValuesModel *)interactionInfo;

/// ----------override------------
/// 展示轻互动动画
- (void)showInteractionAnimation;
/// 隐藏轻互动动画
- (void)hiddenInteractionAnimaiton;
/// 当前视图触发了 show 事件
- (void)interactionViewDidShow;

@end

NS_ASSUME_NONNULL_END
