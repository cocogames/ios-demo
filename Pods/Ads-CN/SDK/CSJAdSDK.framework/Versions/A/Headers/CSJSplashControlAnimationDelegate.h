//
//  CSJSplashControlAnimationDelegate.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/7/28.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@protocol CSJAnimationDelegate <NSObject>
@optional
- (void)bu_animationDidStart:(CAAnimation *)anim;
- (void)bu_animationDidStop:(CAAnimation *)anim finished:(BOOL)flag;
@end

@interface CSJSplashControlAnimationDelegate : NSObject<CAAnimationDelegate>
@property (weak, nonatomic) id<CSJAnimationDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
