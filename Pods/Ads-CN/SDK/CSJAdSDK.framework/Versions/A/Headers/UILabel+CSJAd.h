//
//  UILabel+CSJAd.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/11/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UILabel (CSJAd)

+ (UILabel *)csj_labelWithTextColor:(UIColor *)textColor fontSize:(CGFloat)fontSize alignment:(NSTextAlignment)alignment;

- (void)csj_setTextColor:(UIColor *)textColor fontSize:(CGFloat)fontSize alignment:(NSTextAlignment)alignment;

@end

NS_ASSUME_NONNULL_END
