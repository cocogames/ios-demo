//
//  CSJDislikeNewRealInputView.h
//  CSJAdSDK
//
//  Created by xzj on 2020/4/22.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDislikeNewRealInputView : UIView

@property (nonatomic, strong, readonly) UITextView *textView;

@property (nonatomic, copy) void (^cancelBlock)(void);
@property (nonatomic, copy)  void (^submitBlock)(NSString *text);

@end

NS_ASSUME_NONNULL_END
