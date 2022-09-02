//
//  CSJNativeExpressAdView+Interval.h
//  CSJAdSDK
//
//  Created by bytedance_yuanhuan on 2019/1/20.
//  Copyright © 2019年 bytedance. All rights reserved.
//

#import "CSJNativeExpressAdView.h"
#import "CSJNativeAd.h"
#import "CSJNativeExpressAdManager.h"
#import "CSJWKWebViewClient.h"
#import "CSJAdInfoViewModel.h"
#import "CSJRenderEngineDefine.h"
#import "CSJRenderEngine.h"

NS_ASSUME_NONNULL_BEGIN






@class CSJNativeExpressAdView;




@protocol CSJNativeExpressAdViewDismissDelegate <NSObject>
@optional
// 新插屏广告在点击关闭增加willDismiss
- (void)nativeExpressAdViewWillDismiss:(CSJNativeExpressAdView *)nativeExpressAdView;
- (void)nativeExpressAdViewDismiss:(CSJNativeExpressAdView *)nativeExpressAdView;
@end

@interface CSJNativeExpressAdView ()<BUWebViewDelegate, CSJNativeAdDelegate>
//@property (nonatomic, strong) CSJWKWebViewClient *webview;
@property (nonatomic, strong) CSJRenderEngine *renderEngine;
@property (nonatomic, strong) CSJNativeAd *nativeAd;
@property (nonatomic, assign, readwrite) BOOL isReady;
// 把NativeExpressAdManager 改成了如下的两个代理去实现的BUNativeExpressAdViewDelegate和CSJNativeExpressAdViewDismissDelegate
@property (nonatomic, weak) id<CSJNativeExpressAdViewDelegate> expressAdViewDelegate;
@property (nonatomic, weak) id<CSJNativeExpressAdViewDismissDelegate> expressAdViewDismissDelegate;
@property (nonatomic, assign, readwrite) BUAdUserBehaviorType userBehaviorType;
@property (nonatomic, copy) NSDictionary *clickInfo;
@property (nonatomic, copy) NSString *clickAreaType;
@property (nonatomic, assign) NSInteger areaType;
@property (nonatomic, assign) BUExpressClickAreaCategory clickAreaCategory;

@property (nonatomic, assign) BOOL storeKitOpened;
// defalut : BUNativeExpressAdViewSourceOrigin
@property (nonatomic, assign) BUNativeExpressAdViewSource nativeExpressAdViewSource;

// 渲染超时时间
@property (nonatomic, assign) NSTimeInterval renderTimeout;

// 是否已经开始渲染
@property (nonatomic, assign) BOOL hasStartRender;

// 是否是兜底动态渲染
@property (nonatomic, readonly) BOOL renderDynamicTemplate;

// 使用兜底渲染
- (BOOL)renderNative;

// 是否渲染成功了:包括动态渲染和兜底渲染
@property (nonatomic, assign) BOOL isRenderSuccess;



@property (nonatomic, strong) CSJAdInfoViewModel *infoViewModel;

// 附属VC的关闭按钮，用于click打点上报
@property (nonatomic, strong) UIButton *closeButton;

@property (nonatomic, readonly) BURenderEngineRenderType currentDynamicShowType;


@property (nonatomic, assign) NSInteger renderIndex;

//tracker data
@property (nonatomic, copy, readwrite) NSDictionary *adAnalysisData;

- (instancetype)initWithFrame:(CGRect)frame nativeAd:(CSJNativeAd *)nativeAd nativeExpressAdViewSource:(BUNativeExpressAdViewSource)nativeExpressAdViewSource;

//- (void)setNativeAd:(CSJNativeAd *)nativeAd;
- (nullable NSDictionary *)c_xyDict;
- (void)handleClickEventIsVideoClicked:(BOOL)isVideo isEndcardClicked:(BOOL)isEndcard;
- (void)handleClickCallback;



@property (nonatomic, copy) void(^renderFinishBlock)(void);
@property (nonatomic, copy) void(^renderFailBlock)(NSError *error);

@property (nonatomic, strong) UIView *successView;

/// 轻互动交互完成 父类默认实现为返回调用失败 @{code:-1} 子类需根据实际逻辑覆写方法
/// @param param @{finish:0失败/1成功,reduce_duration:减免的秒数}
- (NSDictionary *)handleInteractiveFinished:(NSDictionary *)param;




#pragma mark - safeDelegate
// xzj_important 在此类中只关心nativeExpressAdView的方法，不需要关心nativeExpressAdManager方法
- (void)safeDelegate_nativeExpressAdViewRenderSuccess:(CSJNativeExpressAdView *)nativeExpressAdView;

- (void)safeDelegate_nativeExpressAdViewRenderFail:(CSJNativeExpressAdView *)nativeExpressAdView error:(NSError *_Nullable)error;
- (void)safeDelegate_nativeExpressAdViewWillShow:(CSJNativeExpressAdView *)nativeExpressAdView;

- (void)safeDelegate_nativeExpressAdViewDidClick:(CSJNativeExpressAdView *)nativeExpressAdView;
- (void)safeDelegate_nativeExpressAdView:(CSJNativeExpressAdView *)nativeExpressAdView stateDidChanged:(BUPlayerPlayState)playerState;

- (void)safeDelegate_nativeExpressAdViewPlayerDidPlayFinish:(CSJNativeExpressAdView *)nativeExpressAdView error:(NSError *)error;
- (void)safeDelegate_nativeExpressAdView:(CSJNativeExpressAdView *)nativeExpressAdView dislikeWithReason:(NSArray<CSJDislikeWords *> *)filterWords;

- (void)safeDelegate_nativeExpressAdViewWillPresentScreen:(CSJNativeExpressAdView *)nativeExpressAdView;
- (void)safeDelegate_nativeExpressAdViewDidCloseOtherController:(CSJNativeExpressAdView *)nativeExpressAdView interactionType:(BUInteractionType)interactionType;

@end

NS_ASSUME_NONNULL_END
