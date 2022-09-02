//
//  CSJHorizontalScrollTextView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/8/13.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 描述字符串滚动前端起始位置：
 */
typedef NS_ENUM(NSInteger, BUTextScrollMoveMode) {
    BUTextScrollMoveModeContinuous,     // 从控件内开始连续滚动
    BUTextScrollMoveModeIntermittent,   // 从控件内开始间断滚动
    BUTextScrollMoveModeFromOutside,    // 从控件外开始滚动
    BUTextScrollMoveModeWandering       // 在控件中往返滚动（不受设置方向影响）
};

/**
 描述字符串移动的方向
 */
typedef NS_ENUM(NSInteger, BUTextScrollMoveDirection) {
    BUTextScrollMoveDirectionLeft,
    BUTextScrollMoveDirectionRight
};


@interface CSJHorizontalScrollTextView : UIView

@property (nonatomic,copy)   NSString  * text;
@property (nonatomic,copy)   UIFont  * textFont;
@property (nonatomic,copy)   UIColor * textColor;

@property (nonatomic,assign) CGFloat speed;

@property (nonatomic,assign) BUTextScrollMoveMode moveMode;
@property (nonatomic,assign) BUTextScrollMoveDirection moveDirection;

- (void)move;
- (void)stop;

@end

NS_ASSUME_NONNULL_END
