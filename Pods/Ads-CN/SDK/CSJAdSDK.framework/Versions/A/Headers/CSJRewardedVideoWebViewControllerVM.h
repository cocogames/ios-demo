//
//  CSJRewardedVideoWebViewControllerVM.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/27.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJWebViewControllerViewModel.h"
#import <UIKit/UIKit.h>
#import "CSJVideoAdEnum.h"
#import "CSJRewardVideoWebDefine.h"
#import "CSJJSB3ExecuteUnitViewModel.h"
#import "CSJRewardedVideoWebDefaultView.h"

NS_ASSUME_NONNULL_BEGIN

#define BURewardAgainCloseNotificationKey @"CSJRewardAgainCloseNotificationKey"

@class CSJRewardedVideoWebViewControllerVM;

@protocol CSJRewardedVideoWebAdapterProtocol <NSObject>
@required
- (NSString *)pageUrlInRewardVideoWebViewModel:(CSJRewardedVideoWebViewControllerVM *)viewModel;
- (NSString *)trackTagInRewardVideoWebViewModel:(CSJRewardedVideoWebViewControllerVM *)viewModel;
@end

@class CSJMaterialMeta;
@class CSJRewardedVideoWebViewController;
@protocol CSJRewardedVideoWebViewDelegate;

// 视频播放但是webview未展示时，为不可见；home键退出时，为不可见
typedef NS_ENUM(NSInteger, BUWebVCLifeCycleStatus) {
    BUWebVCLifeCycleStatus_ViewDidDisappear = 0,
    BUWebVCLifeCycleStatus_ViewWillAppear = 1,
};

@interface CSJRewardedVideoWebViewControllerVM : CSJWebViewControllerViewModel
<CSJRewardedVideoWebDefaultViewDelegate>

@property (nonatomic, weak, nullable) id<CSJRewardedVideoWebViewDelegate> delegate;
@property (nonatomic, assign) BOOL isTransform;    //自己是否旋转
@property (nonatomic, assign) BUChildTransformDirection transformDirection;
@property (nonatomic, assign) BOOL isRewardedVideo; // YES: 激励视频 NO:全屏视频
@property (nonatomic, strong) CSJMaterialMeta *materialMeta;
@property (nonatomic, copy) NSString *ritScene;
/// 是否静音
@property (nonatomic, assign) BOOL mute;
@property (nonatomic, assign) BOOL isLoadFinish;
@property (nonatomic, assign) BOOL hasClosed;
/// 渲染失败出现兜底页
@property (nonatomic, assign) BOOL renderFailed;
/// 3800:再看一个需求
@property (nonatomic, weak) id rewardAd;
/// 弱引用vc
@property (nonatomic, weak) CSJRewardedVideoWebViewController  *videoWebVC;

+ (instancetype)newWithAd:(CSJMaterialMeta *)materialMeta isNativeExpress:(BOOL)isNativeExpress pageType:(BUVideoWebPageType)pageType;

- (instancetype)initViewControllerWithAd:(CSJMaterialMeta *)materialMeta isNativeExpress:(BOOL)isNativeExpress pageType:(BUVideoWebPageType)pageType;

/// 尝试关闭当前页面
- (void)webCloseButtonTapped;

/// 跳过时长
/// @param duration 时长
- (void)skipRewardDuration:(NSInteger)duration;

#pragma mark - subclass use
@property (nonatomic, strong) CSJRewardedVideoWebDefaultView *defaultView;
@property (nonatomic, strong) UIButton *silentButton;
@property (nonatomic, strong) UIButton *dislikeButton;
@property (nonatomic, strong) UIButton *closeButton;
/// 倒计时长，delayTimeCount初始值无穷大
@property (nonatomic, assign) NSInteger delayTimeCount;
/// 记录页面状态
@property (nonatomic, assign) BUWebVCLifeCycleStatus VCLifeCycleStatus;
/// 3000版本以后,兜底展示逻辑 依赖 js 返回是否渲染成功
@property (nonatomic, assign) BOOL isRenderSuc;
/// 记录 view 状态
@property (nonatomic, assign) BOOL isViewShow;
/// 4200半屏新插屏支持pl落地页，增加该字段，以便布局时区分新插屏和pl落地页
@property (nonatomic, assign) CGSize customSize;



/// jsb注册
- (void)registerJSB_Plugin;
/// 点击跳转appstore
- (NSDictionary *)jsCallNative_open_app_store;
/// h5音量事件
- (void)sendEndcardControlEvent:(BOOL)mute;
/// 更新关闭按钮
- (void)updateCloseButton;
/// 关闭页面
- (void)webCloseAction;
/// 点击音量按钮
- (void)silentButtonTapped;
/// 点击反馈按钮
- (void)dislikeButtonTapped;

- (BOOL)shouldShowRewardAgainAlert;
/// 4600 原生激励是否要展示“再看一个”前置入口
- (BOOL)shouldShowRewardAgainEntrance;
- (void)showRewardAgainAlert;
- (void)showRewardAgainMethod;

- (void)jsCallNative_sendPlayableReward;
- (void)jsCallNative_sendVideoProgress:(NSDictionary *)param;
- (NSDictionary *)jsCallNative_getVideoInfo;
@end

NS_ASSUME_NONNULL_END
