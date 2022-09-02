//
//  CSJDislikeNewInputView.h
//  CSJAdSDK
//
//  Created by xzj on 2020/4/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJDislikeNewInputView;

@protocol CSJDislikeNewInputViewDelegate <NSObject>

- (UIView *)containerViewInDislikeNewInputView:(CSJDislikeNewInputView *)dislikeNewInputView;
- (void)dislikeNewInputView:(CSJDislikeNewInputView *)dislikeNewInputView inputText:(NSString *)inputText;
- (void)keyboardWillShowInDislikeNewInputView:(CSJDislikeNewInputView *)dislikeNewInputView;
- (void)keyboardDidShowInDislikeNewInputView:(CSJDislikeNewInputView *)dislikeNewInputView;
- (void)keyboardWillHideInDislikeNewInputView:(CSJDislikeNewInputView *)dislikeNewInputView;
- (void)keyboardDidHideInDislikeNewInputView:(CSJDislikeNewInputView *)dislikeNewInputView;

@end

@interface CSJDislikeNewInputView : UIView
/// inputAccessoryView是否可用
@property (nonatomic, assign) BOOL validInputAccessoryView;
@property (nonatomic, assign, readonly) BOOL showKeyboard;
@property (nonatomic, weak) id<CSJDislikeNewInputViewDelegate> delegate;

#pragma mark - Public
- (void)hideKeyboard;

@end

NS_ASSUME_NONNULL_END
