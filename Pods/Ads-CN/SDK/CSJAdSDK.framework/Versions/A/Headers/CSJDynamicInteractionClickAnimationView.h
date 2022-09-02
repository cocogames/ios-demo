//
//  CSJDynamicInteractionClickAnimationView.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/11/10.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicInteractionClickAnimationView : UIView
- (instancetype)initWithSize:(CGSize)size lineWidth:(CGFloat)lineWidth;
- (void)startAnimation;
@end

NS_ASSUME_NONNULL_END
