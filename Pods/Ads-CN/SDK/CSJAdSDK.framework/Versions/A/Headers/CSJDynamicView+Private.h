//
//  CSJDynamicView+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/7/30.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJDynamicView.h"
#import "CSJDynamicRootView.h"
#import "CSJDynamicNativeViewModel.h"

NS_ASSUME_NONNULL_BEGIN



//// xzj_important 此函数如果base(例如隐藏显示需求)里需要定时器，子类自身也需要定时器，那么子类的功能会覆盖父类的
//// 目前没有这样的控件是这样使用的
//- (void)videoStateUpdateWithPlayDuration:(NSInteger)playDuration stopped:(BOOL)stopped;

@interface CSJDynamicView ()

@property (nonatomic, strong) CSJDynamicRootView *dynamicRootView;

- (void)associateWithDynamicRootView:(CSJDynamicRootView *)dynamicRootView;

@end

NS_ASSUME_NONNULL_END
