//
//  CSJImmersiveMiddlePageViewController.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/10/23.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJNativeAd;

@interface CSJImmersiveMiddlePageViewController : UIViewController
@property (nonatomic, copy) void(^CloseBlock)(void);

- (instancetype)initImmersiveMiddlePageWith:(CSJNativeAd *)nativeAd;
@end

NS_ASSUME_NONNULL_END
