//
//  CSJDynamicAbstractView+Protected.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/23.
//  Copyright © 2020 bytedance. All rights reserved.
//


#import "CSJDynamicAbstractView.h"
#import "CSJDynamicViewDefine.h"
#import "CSJAdClickButton.h"

@class CSJDynamicClickInfo;

NS_ASSUME_NONNULL_BEGIN


static const NSString *CSJDynamic_calcuColor_bgColor = @"bgColor";
static const NSString *CSJDynamic_calcuColor_color = @"color";
static const NSString *CSJDynamic_calcuColor_borderColor = @"borderColor";

@interface CSJDynamicAbstractView ()


@property (nonatomic, strong, nullable) CALayer *gradientLayer;
@property (nonatomic, strong) NSMutableArray *calcuColorArray;

- (NSString *)debugInfo;

#pragma mark - Maybe Override
- (void)adjust_buDynamic_frameIfNeed;
// xzj_important 此函数如果base(例如隐藏显示需求)里需要定时器，子类自身也需要定时器，那么子类的功能会覆盖父类的
// 目前没有这样的控件是这样使用的
- (void)videoStateUpdateWithPlayDuration:(NSInteger)playDuration stopped:(BOOL)stopped;

#pragma mark - Protected
- (void)calcuColorIntoView:(UIView *)view;

#pragma mark - Decorator
- (void)appendDecorator:(CSJDynamicAbstractDecorator *)decorator;

#pragma mark - safeDelegate
- (void)safeDelegate_dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView videoMuted:(BOOL)muted;
- (void)safeDelegate_dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView changeVideoStateToStateType:(NSInteger)stateType;
- (void)safeDelegate_skipInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;
- (void)safeDelegate_openPrivacyAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;
- (void)safeDelegate_interstitialWebviewInCloseAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;
- (void)safeDelegate_dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView userBehaviorType:(BUAdUserBehaviorType)userBehaviorType clickAreaType:(BUDynamicClickAreaType)clickAreaType clickInfo:(CSJDynamicClickInfo *)clickInfo;
- (void)safeDelegate_dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView videoInfoFrame:(CGRect)videoInfoFrame;
- (void)safeDelegate_showSKOverlayInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;

- (void)safeDelegate_registerVideoStateTimerInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;
- (void)safeDelegate_removeVideoStateTimerInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;


- (void)safeDelegate_registerTimingInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView timingProtocol:(id<CSJDynamicAbstractViewTimingProtocol>)timingProtocol;
- (void)safeDelegate_removeTimingInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView timingProtocol:(id<CSJDynamicAbstractViewTimingProtocol>)timingProtocol;
@end

NS_ASSUME_NONNULL_END
