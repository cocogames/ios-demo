//
//  CSJRewardFullScreenBaseVM.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/13.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJRewardedVideoAdViewController.h"
#import "CSJMaterialMeta.h"
#import "CSJMaterialMeta+Private.h"
#import <StoreKit/StoreKit.h>
#import "CSJRewardedVideoAd.h"
#import "CSJRewardedVideoWebViewController.h"
#import "CSJRewardedVideoDisplayViewController.h"
#import "CSJAdEventTracker.h"
#import "CSJRewardedVideoRequestModel.h"
#import "CSJAPIClient.h"
#import "CSJRewardedVideoModel.h"
#import "CSJVideoAdDelegate.h"
#import "CSJAdActionManager.h"
#import "CSJWebViewController.h"
#import "CSJAdSlot+Private.h"
#import "CSJAppStoreTracker.h"
#import "CSJAppStoreManager.h"
#import "CSJAdAppActionManager.h"
#import "CSJPurePlayableLoadingViewController.h"
#import "CSJUSettingService.h"
#import "CSJUnionMacros.h"
#import "CSJDeepLink.h"
#import "CSJRewardAlertView.h"
#import "NSString+CSJLocalizedString.h"
#import "CSJDislikeContext.h"
#import "CSJInterstitialAdDelegate.h"
#import "CSJPlayableLandingViewController.h"


typedef enum : NSUInteger {
    BUVideoOrientationPortrait,            //竖屏
    BUVideoOrientationMaskLandscape,       //横屏
} BUVideoOrientation;

//static NSInteger leftTime = -2;
//static NSInteger closeTime = -2;

NS_ASSUME_NONNULL_BEGIN

@interface CSJRewardFullScreenBaseVM : NSObject

@property (nonatomic, strong) UIViewController *currentViewController;
//*************** public 需要外部赋值 ***************
@property (nonatomic, strong) id<CSJVideoAdDelegate, CSJInterstitialAdDelegate> rewardedVideoAd;


//*************** 内部和子类使用 ***************
@property (nonatomic, strong) CSJRewardedVideoDisplayViewController *rewardedVideoDisplayViewController;
// 4100 endcardWebVC只负责加载endcard
@property (nonatomic, strong) CSJRewardedVideoWebViewController *endcardWebVC;
// 4100 playableLandingVC负责playable，其中playableLandingVC.playableWebVC为真实的playable页
@property (nonatomic, strong) CSJPlayableLandingViewController *_Nullable playableLandingVC;
@property (nonatomic, strong) CSJPurePlayableLoadingViewController *loadingWebView;
@property (nonatomic, strong) CSJMaterialMeta *materialMeta;
@property (nonatomic, strong) CSJAdSlot *slot;
// 记录播放时间戳
@property (nonatomic, strong) NSString *startTimestamp;
@property (nonatomic, strong) NSString *endTimestamp;
@property (nonatomic, assign) BOOL isChildLandscapeRotate;   //子控制器是否自己旋转
@property (nonatomic, assign) BOOL isRotate;                 //当前控制器是否旋转
@property (nonatomic, assign) BUVideoOrientation videoOrientation;
@property (nonatomic, assign) BOOL supportPortraitLandscape;
@property (nonatomic, assign) NSTimeInterval startLoadTime;     //开始预加载时间
@property (nonatomic, assign) NSTimeInterval startShowTime;     //开始展示时间
@property (nonatomic, strong) CSJURitSettingModel *ritModel;
//倒计时 纯playable
@property (nonatomic, strong) UILabel *leftSeconds;
@property (nonatomic, strong) BUTimer *leftTimer;
// close关闭按钮
@property (nonatomic, strong) UIButton *closeButton;
@property (nonatomic, strong) UIButton *backBtn;
// 负反馈按钮
@property (nonatomic, strong, readwrite) UIButton *dislikeButton;
// 静音按钮
@property (nonatomic, strong) UIButton *silentButton;
@property (nonatomic, assign) BOOL mute;
@property (nonatomic, assign) BOOL isReportEvent;
// 标志H5告诉纯playable的是否可以发放奖励的标志
@property (nonatomic, assign) BOOL purePlayableSendRewardFromH5;
// 作为是否可以发放奖励的标志，用于控制弹窗是否显示
@property (nonatomic, assign) BOOL couldSendRewardForPurePlayable;
// 当前alertview是否展示 展示就不能开启定时器
@property (nonatomic, assign) BOOL isShowAlertView;
// 相关推荐物料
@property (nonatomic, copy) NSArray *relatedMaterialMetas;
// 判断当前是否已经切换到endcard或者playable页面,防止多次切换
@property (nonatomic, assign) BOOL hadSwitchToWebviewVC;

@property (nonatomic, strong) CSJDislikeContext *dislikeContext;
@property (nonatomic, assign) BUCloseButtonStyle closeButtonStyle;

//vm new property
@property (nonatomic, weak) CSJRewardedVideoAdViewController *rootVC;

@property (nonatomic, assign) NSInteger leftTime;
@property (nonatomic, assign) NSInteger closeTime;
/// pl渲染失败标志位
@property (nonatomic, assign) BOOL playableRenderFailed;
@property (nonatomic, readonly) CSJRewardedVideoWebViewController *currentWebVC;

+ (instancetype)createViewModelWithMeta:(CSJMaterialMeta *)meta rootViewController:(CSJRewardedVideoAdViewController *)rootVC slot:(nonnull CSJAdSlot *)slot;

- (instancetype)initViewModelWithMeta:(CSJMaterialMeta *)meta rootViewController:(CSJRewardedVideoAdViewController *)rootVC  slot:(nonnull CSJAdSlot *)slot;

- (void)vmLoadData;

- (void)relayoutSubViews;

- (UIInterfaceOrientationMask)vmSupportedInterfaceOrientations;

- (void)openAppStore;

#pragma mark - Child Class Use
//获取播放时长
- (NSInteger)getDurationValue;
//可关闭的时间
- (NSInteger)getCloseTimeValue;

- (void)updateTopBarButtonFrame;

- (void)switchToWebViewMute:(BOOL)mute;

#pragma mark - CSJRewardedVideoDisplayDelegate
- (void)playerDidPlayedRewardTime:(nullable BUPlayer *)player duration:(NSTimeInterval)duration;

#pragma mark - CSJPurePlayableLoadingViewControllerDelegate
- (void)rewardedVideoH5AdDidClickNeedJump:(BOOL)needJump;

- (void)handlePurePlayableBar:(BOOL)show;

- (void)updateSlientBtnState:(BOOL)isMute;

@end

NS_ASSUME_NONNULL_END
