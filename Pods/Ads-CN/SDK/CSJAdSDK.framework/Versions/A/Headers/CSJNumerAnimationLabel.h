//
//  CSJNumerAnimationLabel.h
//  loadingPageTest
//
//  Created by bytedance on 2021/11/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJNumerAnimationLabel : UILabel

- (void)animationStartFromNumber:(NSInteger)startNumber toNumber:(NSInteger)endNumber duration:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
