//
//  CSJDynamicInteractionSwipeAnimationView.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/3/23.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJDynamicInteractionSwipeAnimationView;

@protocol CSJDynamicInteractionSwipeAnimationDelegate <NSObject>

- (void)swipeAnimationDidFinish:(CSJDynamicInteractionSwipeAnimationView *)animationView;

@end

@interface CSJDynamicInteractionSwipeAnimationView : UIView
@property (nonatomic, weak) id<CSJDynamicInteractionSwipeAnimationDelegate> delegate;

- (void)startAnimation;
- (void)stopAnimation;
@end

NS_ASSUME_NONNULL_END
