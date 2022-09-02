//
//  UIView+CSJAd.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/9/6.
//  Copyright © 2020 bytedance. All rights reserved.
//



#import <UIKit/UIKit.h>
#import "CSJAdTapGestureRecognizer.h"
#import "CSJAdClickButton.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUAdUserBehaviorType) {
    BUAdUserBehaviorType_Unknow = 0, // 未知点击类型
    BUAdUserBehaviorType_Tap = 1,  // 纯点击
    BUAdUserBehaviorType_SwipeClick = 2, // 支持点击+内部滑动
};

@interface UIView (CSJAd)

@property (nonatomic, strong, nullable) CSJAdTapGestureRecognizer *csj_clickInfoTgr;
@property (nonatomic, strong, nullable) CSJAdClickButton *csj_clickButtonInfoTgr;
@property (nonatomic, strong, nullable) id csj_actionControl;

// 点击手势事件，会移除旧的手势
- (void)csj_addClickInfoGestureRecognizerWithTarget:(id)target action:(SEL)action;

// 点击按钮事件，会移除旧的按钮
- (void)csj_addClickInfoButtonWithTarget:(id)target action:(SEL)action;

// 点击事件，通过枚举值区分按钮或者手势
- (void)csj_addClickActionWithTarget:(id)target action:(SEL)action clickType:(BUAdUserBehaviorType)clickType;

// 移除所有按钮和手势操作
- (void)csj_removeClickAction;

// 设置安全的CTA区域，如果滑到CTA区域，按钮滑动事件不生效，不响应滑动点击事件
- (void)csj_setCtaArea:(CGRect)ctaArea;

// 点击滑动埋点字段
- (NSDictionary *)csj_eventDict_clickAction;

@end

NS_ASSUME_NONNULL_END
