//
//  CSJNativeExpressSplashVideoAdView.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/10/20.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJNativeExpressAdView.h"
@class CSJNativeExpressSplashVideoAdView;
NS_ASSUME_NONNULL_BEGIN

@protocol CSJNativeExpressSplashVideoAdViewDelegate <NSObject>

- (void)nativeExpressSplashVideoAdViewReadyToPlay:(CSJNativeExpressSplashVideoAdView *)splashView;

- (void)nativeExpressSplashVideoAdViewFinishPlayDidPlayFinish:(CSJNativeExpressSplashVideoAdView *)splashView didFailWithError:(NSError *)error;

- (void)nativeExpressSplashVideoAdViewForceQuit:(CSJNativeExpressSplashVideoAdView *)splashView;

@end

@interface CSJNativeExpressSplashVideoAdView : CSJNativeExpressAdView

@property (nonatomic, weak) id<CSJNativeExpressSplashVideoAdViewDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
