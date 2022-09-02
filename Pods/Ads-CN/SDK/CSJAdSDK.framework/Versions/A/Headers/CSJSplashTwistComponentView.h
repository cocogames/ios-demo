//
//  BUSplashBottomTwistAnimationMask.h
//  CSJAdSDK
//
//  Created by Willie on 2021/9/18.
//

#import "CSJSplashBottomBaseComponentView.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    BUSplashTwistComponentViewLayoutTypeTwist       = 0,
    BUSplashTwistComponentViewLayoutTypeTwistAndTap = 1,
} BUSplashTwistComponentViewLayoutType;

@interface CSJSplashTwistComponentView : CSJSplashBottomBaseComponentView

@property (nonatomic, assign) CGFloat twistRotationThreshold;

- (instancetype)initWithComponentConfiguration:(id<CSJSplashBottomViewInterface>)configuration
                                    layoutType:(BUSplashTwistComponentViewLayoutType)layoutType;

- (void)startTwistUpdates;

@end

NS_ASSUME_NONNULL_END
