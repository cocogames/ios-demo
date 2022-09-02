//
//  CSJSplashZoomOutView+private.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/6/17.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJSplashZoomOutView.h"
#import "CSJMaterialMeta+Private.h"
#import "CSJSplashViewModel.h"
#import "CSJMaterialMeta.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJSplashZoomOutView ()
/**
The delegate for receiving state change messages.
*/
@property (nonatomic, weak) id<CSJSplashZoomOutViewDelegate> delegate;

- (instancetype)initWithViewModel:(CSJSplashViewModel *)viewModel;

- (void)continuePlayWithPlayer:(BUPlayer *)player;

- (void)showZoomOutViewInRootView:(UIView *)rootView;

@end

@protocol CSJSplashZoomOutViewDelegate <NSObject>
/**
 This method is called when splash ad is clicked.
 */
- (void)splashZoomOutViewAdDidClick:(CSJSplashZoomOutView *)splashAd;

/**
 This method is called when splash ad is closed.
 */
- (void)splashZoomOutViewAdDidClose:(CSJSplashZoomOutView *)splashAd;

@end

NS_ASSUME_NONNULL_END
