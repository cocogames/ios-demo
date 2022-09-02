//
//  CSJRewardedVideoAdViewController.h
//  CSJAdSDK
//
//  Created by gdp on 2018/1/11.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJMaterialMeta;
@class CSJAdSlot;
@protocol CSJVideoAdDelegate;


@interface CSJRewardedVideoAdViewController : UIViewController

@property (nonatomic, strong) id<CSJVideoAdDelegate> rewardedVideoAd;

- (instancetype)initViewControllerWithAd:(CSJMaterialMeta *)materialMeta slot:(CSJAdSlot *)slot;

// 调起应用内 App Store，子 VC 调用
- (void)openAppStore;

// 切换到 WebView，当视频播放完成子 VC 调用
- (void)switchToWebViewMute:(BOOL)mute;

@end

NS_ASSUME_NONNULL_END
