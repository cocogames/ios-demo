//
//  CSJSplashArrowAnimationView.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/7/2.
//  Copyright © 2021 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJSplashArrowAnimationView : UIView
- (instancetype)initSplashArrowAnimationWith:(NSInteger)arrowCount translateX:(NSArray<NSNumber *> *)values delay:(CGFloat)delay;
- (void)startArrowAnimation;
@end

NS_ASSUME_NONNULL_END
