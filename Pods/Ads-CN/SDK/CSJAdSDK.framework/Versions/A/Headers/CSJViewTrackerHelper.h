//
//  CSJViewTrackerHelper.h
//  CSJAdSDK
//
//  Created by carl on 2018/1/7.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CSJViewTrackerHelper : NSObject
+ (BOOL)checkIfViewInScreen:(UIView *)view;

/// 检测当前view是否完全显示
/// @param view 检测的view
+ (BOOL)checkIfViewFullDisplayInScreen:(UIView *)view;

/// 当前屏幕内展示的面积
+ (CGFloat)visibleAreaWithView:(UIView *)view;

/// 当前superview内展示的面积
+ (CGFloat)visibleAreaWithView:(UIView *)view superView:(UIView *)superView;
@end
