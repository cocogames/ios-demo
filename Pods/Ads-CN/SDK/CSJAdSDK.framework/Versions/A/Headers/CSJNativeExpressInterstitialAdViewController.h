//
//  CSJNativeExpressInterstitialAdViewController.h
//  CSJAdSDK
//
//  Created by xxx on 2019/5/16.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJNativeExpressAdView;
@class CSJNativeExpressInterstitialAd;

static const CGSize closeSize = {24, 24};

@interface CSJNativeExpressInterstitialAdViewController : UIViewController
@property (nonatomic, strong) CSJNativeExpressInterstitialAd *interstitialAd;

- (instancetype)initViewControllerWithExpressAdView:(CSJNativeExpressAdView *)expressAdView adSize:(CGSize)adsize;
@end

NS_ASSUME_NONNULL_END
