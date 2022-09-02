//
//  CSJRewardedAgianAlertView.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2021/6/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJRewardedAgianAlertView : UIView
- (instancetype)initWithFrame:(CGRect)frame confirm:(dispatch_block_t)confirm cancel:(dispatch_block_t)cancel;
- (void)showInView:(UIView *)parentView;
- (void)disappear;

/// update the text of  title label
- (void)updateTextOfTitle:(NSString *)title;
//- (void)updateTextOfMessage:(NSString *)text;
//- (void)updateConfirmBtnColor:(UIColor *)color;
//- (void)updateIcon:(UIImage *)image;
@end

NS_ASSUME_NONNULL_END
