//
//  CSJSplashRippleAnimationView.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/7/7.
//

#import <UIKit/UIKit.h>
#import "CSJAnimationConfiguration.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJSplashRippleAnimationView : UIView

- (instancetype)initWithConfiguration:(CSJAnimationConfiguration *)configuration;

- (void)startRippleAnimation;
@end

NS_ASSUME_NONNULL_END
