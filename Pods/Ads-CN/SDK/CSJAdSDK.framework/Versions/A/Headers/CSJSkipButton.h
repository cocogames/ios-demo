//
//  CSJSkipButton.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/4.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CSJSkipButton : UIButton

@property (nonatomic, copy) void(^timeOut)(void);

- (void)beginCountDown:(NSTimeInterval)countdobuTimeInterval;
- (void)pauseCoutDown;
- (void)resumeCoutDown;
- (void)stopCoutDown;
- (void)updateText:(CGFloat)lastSeconds;

@end
