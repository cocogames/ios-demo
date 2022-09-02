//
//  BUSplashBottomShakeAnimationView.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/9/15.
//

#import "CSJSplashBottomBaseComponentView.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    BUSplashShakeComponentViewLayoutTypeShake       = 0,
    BUSplashShakeComponentViewLayoutTypeShakeAndTap = 1,
} BUSplashShakeComponentViewLayoutType;

@interface CSJSplashShakeComponentView : CSJSplashBottomBaseComponentView

- (instancetype)initWithComponentConfiguration:(id<CSJSplashBottomViewInterface>)configuration
                                    layoutType:(BUSplashShakeComponentViewLayoutType)layoutType;

@end

NS_ASSUME_NONNULL_END
