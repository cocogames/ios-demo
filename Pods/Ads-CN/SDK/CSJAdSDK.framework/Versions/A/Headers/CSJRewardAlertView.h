//
//  CSJRewardAlertView.h
//  CSJAdSDK
//
//  Created by iCuiCui on 2019/1/25.
//  Copyright © 2019年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CSJRewardAlertView : UIView
- (instancetype)initWithFrame:(CGRect)frame confirm:(dispatch_block_t)confirm cancel:(dispatch_block_t)cancel;
- (void)showInView:(UIView *)parentView;


/// show alertView in window (alertLevel)
- (void)showInWindow;

///  update the text of cancel button
- (void)updateTextOfCancelButtonByKey:(NSString *)key;

/// update the text of  title label
- (void)updateTextOfTitleLabelByKey:(NSString *)key;

- (void)updateTextOfTitle:(NSString *)title;

- (void)updateTextOfConfirm:(NSString *)text;

- (void)updateTextOfCancel:(NSString *)text;
@end

