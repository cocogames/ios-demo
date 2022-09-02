//
//  CSJRewardedVideoWebViewController.h
//  CSJAdSDK
//
//  Created by gdp on 2018/1/14.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJWebViewController.h"
#import "CSJVideoAdEnum.h"
#import "CSJRewardVideoWebDefine.h"
#import "CSJRewardedVideoWebViewControllerVM.h"
#import "CSJPlayableWebVM.h"
#import "CSJEndcardWebVM.h"

NS_ASSUME_NONNULL_BEGIN

@class CSJMaterialMeta;
@protocol CSJRewardedVideoWebViewDelegate;

@interface CSJRewardedVideoWebViewController :CSJWebViewController

@property (nonatomic, weak, nullable) id<CSJRewardedVideoWebViewDelegate> delegate;
@property (nonatomic, assign) BOOL isTransform;    //自己是否旋转
@property (nonatomic, assign) BUChildTransformDirection transformDirection;
@property (nonatomic, assign) BOOL isRewardedVideo; // YES: 激励视频 NO:全屏视频
//@property (nonatomic, strong) CSJMaterialMeta *materialMeta;
@property (nonatomic, copy) NSString *ritScene;
@property (nonatomic, assign) BOOL mute;//是否静音

- (instancetype)initViewControllerWithAd:(CSJMaterialMeta *)materialMeta isNativeExpress:(BOOL)isNativeExpress pageType:(BUVideoWebPageType)pageType;
- (instancetype)initViewControllerWithAd:(CSJMaterialMeta *)materialMeta size:(CGSize)size isNativeExpress:(BOOL)isNativeExpress pageType:(BUVideoWebPageType)pageType;

/// 关闭当前页面
- (void)webCloseButtonTapped;

//************************************ VM Related ************************************
@property (nonatomic, strong) CSJRewardedVideoWebViewControllerVM *videoWebVM;

- (CSJEndcardWebVM*)endcardVM;
- (CSJPlayableWebVM*)playableVM;

@end

NS_ASSUME_NONNULL_END
