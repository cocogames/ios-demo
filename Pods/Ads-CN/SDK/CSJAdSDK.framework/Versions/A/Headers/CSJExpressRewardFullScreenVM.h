//
//  CSJExpressRewardFullScreenVM.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/16.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJNativeExpressRewardedVideoAdView.h"
#import "CSJNativeExpressAdView+Video.h"
#import "CSJNativeExpressAdView+Interval.h"
#import "CSJNativeExpressRewardedVideoAdDisplayViewController.h"
#import "CSJRewardedVideoWebViewController.h"
#import "CSJRewardedVideoModel.h"
#import "CSJMaterialMeta.h"
#import "CSJMaterialMeta+Private.h"
#import "CSJAdSlot+Private.h"
#import "CSJRewardedVideoRequestModel.h"
#import "CSJAPIClient.h"
#import "CSJAdAppActionManager.h"
#import "CSJVideoAdEnum.h"
#import "CSJUnionMacros.h"
#import "CSJPurePlayableLoadingViewController.h"
#import "CSJPlayableLandingViewController.h"
#import "CSJRewardAlertView.h"
#import "NSString+CSJLocalizedString.h"
#import "CSJAdActionManager.h"
#import "CSJDislikeContext.h"
#import "SKStoreProductViewController+CSJAPublic.h"
#import "CSJNativeExpressRewardedVideoAdViewController.h"
#import <UIKit/UIKit.h>
#import "CSJAdEventTracker.h"

@class CSJNativeExpressRewardedVideoAdView;
@class CSJNativeAd;
@class CSJAdSlot;
@class CSJDislikeContext;


NS_ASSUME_NONNULL_BEGIN

typedef void(^success)(BOOL isVerify);
typedef void(^failCompletion)(NSError *error);
//static NSInteger leftTime = -2;
//static NSInteger closeTime = -2;


@interface CSJExpressRewardFullScreenVM : NSObject

@property (nonatomic, weak) id<CSJNativeExpressVideoAdDelegate> rewardedVideoAd;
@property (nonatomic, assign) BOOL isRewardedVideo;
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, copy) dispatch_block_t purePlayableClickBlock;
//====

@property (nonatomic, strong) CSJNativeExpressRewardedVideoAdView *expressAdView;
@property (nonatomic, strong) UIViewController *currentViewController;
@property (nonatomic, strong) CSJNativeExpressRewardedVideoAdDisplayViewController *rewardedVideoDisplayViewController;
// 4100 endcardWebVC只负责加载endcard
@property (nonatomic, strong) CSJRewardedVideoWebViewController *endcardWebVC;
// 4100 playableLandingVC负责playable，其中playableLandingVC.playableWebVC为真实的playable页
@property (nonatomic, strong) CSJPlayableLandingViewController *_Nullable playableLandingVC;

@property (nonatomic, assign) UIInterfaceOrientationMask systemOrientation;
@property (nonatomic, assign) BUNativeExpressVideoOrientation videoOrientation;
@property (nonatomic, assign) BUChildTransformDirection childTransform;   //子控制器是否自己旋转

// 记录播放时间戳
@property (nonatomic, strong) NSString *startTimestamp;
@property (nonatomic, strong) NSString *endTimestamp;

/// 纯playable
@property (nonatomic, strong) CSJNativeAd *purePlayableNativeAd;
@property (nonatomic, strong) CSJURitSettingModel *ritModel;
@property (nonatomic, strong) CSJPurePlayableLoadingViewController *loadingWebView;
@property (nonatomic, strong) UILabel *leftSeconds;
@property (nonatomic, strong) BUTimer *leftTimer;
@property (nonatomic, strong) UIButton *closeButton;
@property (nonatomic, strong) UIButton *backBtn;
// 负反馈按钮
@property (nonatomic, strong, readwrite) UIButton *dislikeButton;
@property (nonatomic, strong) UIButton *silentButton;
@property (nonatomic, assign) BOOL mute;
@property (nonatomic, assign) BOOL isReportEvent;
// 标志H5告诉纯playable的是否可以发放奖励的标志
@property (nonatomic, assign) BOOL purePlayableSendRewardFromH5;
// 作为是否可以发放奖励的标志，用于控制弹窗是否显示
@property (nonatomic, assign) BOOL couldSendRewardForPurePlayable;
// 当前alertview是否展示 展示就不能开启定时器
@property (nonatomic, assign) BOOL isShowAlertView;
// 判断当前是否已经切换到endcard或者playable页面,防止多次切换
@property (nonatomic, assign) BOOL hadSwitchToWebviewVC;
// 相关推荐物料
@property (nonatomic, copy) NSArray *relatedMaterialMetas;

@property (nonatomic, strong) CSJDislikeContext *dislikeContext;
@property (nonatomic, assign) BUCloseButtonStyle closeButtonStyle;

@property (nonatomic, assign) NSInteger leftTime;
@property (nonatomic, assign) NSInteger closeTime;
/// pl渲染失败标志位
@property (nonatomic, assign) BOOL playableRenderFailed;
//vm new property
@property (nonatomic, weak) CSJNativeExpressRewardedVideoAdViewController *rootVC;

+ (instancetype)createViewModelWithExpressAdView:(CSJNativeExpressRewardedVideoAdView *)expressAdView
                                        nativeAd:(CSJNativeAd *)purePlayableNativeAd
                              rootViewController:(CSJNativeExpressRewardedVideoAdViewController *)rootVC;

- (instancetype)initViewModelWithExpressAdView:(CSJNativeExpressRewardedVideoAdView *)expressAdView
                                      nativeAd:(CSJNativeAd *)purePlayableNativeAd
                            rootViewController:(CSJNativeExpressRewardedVideoAdViewController *)rootVC;

- (void)vmLoadData;

- (void)relayoutSubViews;

- (UIInterfaceOrientationMask)vmSupportedInterfaceOrientations;

- (void)switchToPlayable;

- (void)switchToEndcard;

#pragma mark - Child Class Use
@property (nonatomic, readonly) CSJRewardedVideoWebViewController *currentWebVC;

//可关闭的时间
- (NSInteger)getCloseTimeValue;

- (void)updateTopBarButtonFrame;

- (void)sendVerifiedRewardWithDuration:(NSTimeInterval)durationTime type:(BURewardType)rewardType;

- (void)handlePurePlayableBar:(BOOL)show;

- (void)rewardedVideoH5AdDidClickNeedJump:(BOOL)needJump;

- (void)updateSlientBtnState:(BOOL)isMute;

@end

NS_ASSUME_NONNULL_END
