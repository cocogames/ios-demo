//
//  BUSplashZoomOutView.h
//  BUAdSDK
//
//  Created by wangyanlin on 2020/6/17.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "BUInterfaceBaseView.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BUSplashZoomOutViewDelegate;

__attribute__((objc_subclassing_restricted))

/// Please note: This Class does not take effect on Pangle global, only use it when you have traffic from mainland China.
@interface BUSplashZoomOutView : BUInterfaceBaseView
/*
Root view controller for handling ad actions.
*/
@property (nonatomic, weak) UIViewController *rootViewController;

/**
Suggested size for show.
*/
@property (nonatomic, assign, readonly) CGSize showSize;


@end

NS_ASSUME_NONNULL_END
