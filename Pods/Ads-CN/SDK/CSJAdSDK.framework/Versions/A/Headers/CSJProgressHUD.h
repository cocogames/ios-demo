//
//  CSJProgressHUD.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/10/14.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, BUNumberOfLine) {//需要指定每行的内容
    BUNumberOfLine_one = 1,// 展示单行
    BUNumberOfLine_two = 2,// 展示多行
};

NS_ASSUME_NONNULL_BEGIN

@interface CSJProgressHUD : UIView
@property (nonatomic, assign) BUNumberOfLine numberOfLine;
@property (nonatomic, copy) NSString *firstLineString;
@property (nonatomic, copy) NSString *secondLineString;

- (void)showInView:(UIView *)parentView hiddenAfterDelay:(NSInteger)delay;

@end

NS_ASSUME_NONNULL_END
