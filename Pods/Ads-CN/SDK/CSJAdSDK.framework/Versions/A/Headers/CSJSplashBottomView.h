//
//  CSJSplashBottomView.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2021/3/7.
//  Copyright © 2021 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJMaterialMeta+Private.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BUSplashBottomMaskType) {
    BUSplashBottomMaskTypeFull = 0,
    BUSplashBottomMaskTypeHalf = 1
};

/// 开屏底部合规容器
@interface CSJSplashBottomView : UIView

@property (nonatomic, copy) void(^actionBlock)(void);

- (instancetype)initWithMaterialMeta:(CSJMaterialMeta *)materialMeta;

- (CGRect)bottomMaskFrameWithCoverFrame:(CGRect)coverFrame;

- (void)startAnimating;

@end

NS_ASSUME_NONNULL_END
