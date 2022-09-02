//
//  CSJWebViewControllerViewModel.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJAdSlot.h"
#import <UIKit/UIKit.h>
#import "CSJWKWebViewClient.h"

@class CSJDislikeContext;

struct BUWebViewClickStruct {
    CGPoint point;
    NSString *tag;
};

typedef NS_ENUM(NSUInteger, BUWebViewHeartBeatState) {
    BUWebViewHeartBeatState_Stable, //正常稳定状态(暂不适用)
    BUWebViewHeartBeatState_Break, //断开
};

typedef NS_ENUM(NSUInteger, BULandingPageType) {
    BULandingPageType_None = 0, //非落地页类型
    BULandingPageType_Direct = 1, //全屏直出落地页场景
    BULandingPageType_Split = 2, //7分屏落地页
};

typedef void (^BUWebViewHeartBeatCallback)(BUWebViewHeartBeatState type);


@interface CSJWebViewControllerViewModel : NSObject <BUWebViewDelegate>

@property (nonatomic, strong) CSJWKWebViewClient *webView;
@property (nonatomic, readonly) id<CSJAd> adInfo;
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, copy) NSString *webTitle;
@property (nonatomic, assign, readonly) BOOL isNavBarHidden;
@property (nonatomic, assign) BOOL isHiddenProgress; //展示进度条，默认为NO
@property (nonatomic, copy) void(^CloseBlock)(void);
@property (nonatomic, strong) NSURL *requestURL;
@property (nonatomic, assign, getter=isSupportAlert) BOOL supportAlert; // 是否支持前端 alert 弹窗，默认为 YES
@property (nonatomic, assign) BOOL hasTerminateTrack;//是否已经上报过一次 webview 崩溃
@property (nonatomic, strong) NSDictionary *relatedMaterialMeta; // 相关推荐物料或者鲁班聚合页引流广告
@property (nonatomic, copy) NSString *createExtraString; // H5落地页自建站增加的字段
@property (nonatomic, copy) dispatch_block_t hasLoadLubanListPage;  // 加载鲁班聚合页
@property (nonatomic, assign) BULandingPageType landingPageType; // 海外链路优选七分屏落地页
@property (nonatomic, assign) BOOL isFromClick;
@property (nonatomic, assign) BUVideoWebPageType pageType;

/// 落地页适配iOS 14.5 商店关闭回调
@property (nonatomic, copy) dispatch_block_t downloadDidCloseStoreController;
/*
 @param isNavBarHidden业务方使用，可选是否隐藏navigationBar，例如encard、视频详情页下半部分可以设置成YES，落地页可以设置成NO
 @param size webview的size，需要前置确定，为了兼容playable使用wkwebview进行预加载，必须提前传入frame
 */
- (instancetype)initWithRequestURL:(NSURL *)requestURL adinfo:(id<CSJAd>)adinfo size:(CGSize)size isNavBarHidden:(BOOL)isNavBarHidden;

/*
 @param isNavBarHidden业务方使用，可选是否隐藏navigationBar，例如encard、视频详情页下半部分可以设置成YES，落地页可以设置成NO
 @param size webview的size，需要前置确定，为了兼容playable使用wkwebview进行预加载，必须提前传入frame
 @param isLandingpageSplitScreen 海外优选链路专用字段
 */
- (instancetype)initWithRequestURL:(NSURL *)requestURL adinfo:(id<CSJAd>)adinfo size:(CGSize)size isNavBarHidden:(BOOL)isNavBarHidden landingPageType:(BULandingPageType)landingPageType;
- (instancetype)initWithRequestURL:(NSURL *)requestURL adinfo:(id<CSJAd>)adinfo size:(CGSize)size isNavBarHidden:(BOOL)isNavBarHidden landingPageType:(BULandingPageType)landingPageType isFromClick:(BOOL)isFromClick;

- (void)bu_loadRequest:(NSURL *)requestURL;


/**************** subclass overwrite ****************/
- (void)sendTrackDataWithParameters:(NSDictionary *)dict;
- (void)goback:(id)sender;
- (void)goClose:(id)sender;
- (void)appDidEnterBackgroundNotification:(NSNotification *)notification;
- (void)appWillEnterForegroundNotification:(NSNotification *)notification;
- (void)handleError:(NSError *)error;
/// 是否使用拦截cache
- (BOOL)useCache;
///注册点击监听
- (void)registJS_Tap;
/// 获取埋点tag
- (NSString *)getTrackTag;
///监听h5心跳, 同一个实例只有一份监听
- (void)observeHeartBeatWithOverTime:(NSInteger)overTime callback:(BUWebViewHeartBeatCallback)callback;
///取消监听h5心跳
- (void)cancelObserveHeartBeat;

//- (void)removeAllScriptMsgHandleForName:(NSString *)name;
/**************** subclass overwrite ****************/

/**************** VM related ****************/
@property (nonatomic, weak) UIView *view;//containerView

@property (nonatomic, weak) UIViewController *parentVC;//optional 落地页点击 返回/关闭 pop vc 使用; 设置 VC 的 title 使用

// VC lift cycle
- (void)handleViewDidLoad;

- (void)handleViewWillLayoutSubviews;

- (void)handleViewWillAppear:(BOOL)animated;

- (void)handleViewDidAppear:(BOOL)animated;

- (void)handleViewWillDisappear:(BOOL)animated;

- (void)handleViewDidDisappear:(BOOL)animated;

- (void)handleDidReceiveMemoryWarning;

///web点击事件
- (void)handleTapWithInfo:(NSString *)info;

- (BOOL)isRealPlayablePage;
// 子类重写
- (BOOL)shouldTrack;
- (NSString *)trackTag;
- (BOOL)useLandingPageNewStyle;

- (void)responseViewClick:(struct BUWebViewClickStruct)click;
- (void)responseViewDidScroll:(struct BUWebViewClickStruct)click offset:(CGPoint)offset;
// 链路优选需求第一次点击webview上报埋点
- (void)responseViewFirstClick:(struct BUWebViewClickStruct)click;
- (BOOL)isOverseaLPNewStyle;

@end

