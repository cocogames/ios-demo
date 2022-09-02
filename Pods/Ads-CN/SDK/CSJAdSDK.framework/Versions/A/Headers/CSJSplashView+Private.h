//
//  CSJSplashView+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/9.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJSplashView.h"
#import "CSJAdSlot+Private.h"
#import "CSJNativeExpressSplashVideoAdView.h"
#import "CSJNativeExpressAdManager.h"
#import "CSJSkipButton.h"
#import "CSJDislikeContext.h"
#import "CSJSplashViewModel.h"

@class BUGifImageView;

NS_ASSUME_NONNULL_BEGIN

@protocol CSJSplashViewDelegate <NSObject>

- (void)splashResourceDidLoad:(NSError *)error;
- (void)splashRenderSuccess:(CSJSplashView *)splashView;
- (void)splashRenderFailed:(NSError *)error;
- (void)splashDidShow:(CSJSplashView *)splashView;
- (void)splashDidClose:(CSJSplashView *)splashView closeType:(CSJSplashAdCloseType)closeType;
- (void)splashDidClick:(CSJSplashView *)splashView;

/**
 This method is called when when video ad play completed or an error occurred.
 */
- (void)splashViewFinishPlayDidPlayFinish:(CSJSplashView *)splashView didFailWithError:(NSError *)error;


@end


@interface CSJSplashView ()

/**
 The delegate for receiving state change messages.
 */
@property (nonatomic, weak, nullable) id<CSJSplashViewDelegate> delegate;

@property (nonatomic, weak) UIViewController *rootViewController;

@property (nonatomic, strong) CSJSplashViewModel *splashViewModel;

- (instancetype)initWithViewModel:(CSJSplashViewModel *)viewModel;

- (BOOL)isAdValid;

- (BOOL)isRenderNative;

- (BUPlayer *)player;

@end


NS_ASSUME_NONNULL_END
