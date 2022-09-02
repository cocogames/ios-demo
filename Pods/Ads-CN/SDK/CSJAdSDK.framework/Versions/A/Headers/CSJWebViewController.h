//
//  CSJWebViewController.h
//  CSJAdSDK
//
//  Created by 曹清然 on 2017/6/4.
//  Copyright © 2017年 chenren. All rights reserved.
//


#import "CSJAdSDKDefines+Private.h"
#import "CSJWebViewController.h"
#import "CSJAdSlot.h"
#import <UIKit/UIKit.h>
#import "CSJWKWebViewClient.h"
#import "CSJWebViewControllerViewModel.h"

@class CSJDislikeContext;


typedef void(^BUWebViewNotifyForAnchor)(BOOL endDragging, CGFloat offsetY);


@interface CSJWebViewController : UIViewController

@property (nonatomic, strong) CSJWKWebViewClient *webView;
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, copy) NSString *webTitle;
@property (nonatomic, copy) void(^CloseBlock)(void);
@property (nonatomic, strong) NSDictionary *relatedMaterialMeta; // 相关推荐物料或者鲁班聚合页引流广告
@property (nonatomic, copy) dispatch_block_t hasLoadLubanListPage;  // 加载鲁班聚合页
@property (nonatomic, copy) BUWebViewNotifyForAnchor webViewNotifyForAnchor;    // 滑到顶部继续向下滑触发视频view展示 add in V3300 by chaors
@property (nonatomic, assign) CGFloat videoViewHeight;    // 与视频组合页的视频view高度 add in V3300 by chaors
@property (nonatomic, assign) BOOL isFromClick;

/*
 @param isNavBarHidden业务方使用，可选是否隐藏navigationBar，例如encard、视频详情页下半部分可以设置成YES，落地页可以设置成NO
 @param size webview的size，需要前置确定，为了兼容playable使用wkwebview进行预加载，必须提前传入frame
 */

- (instancetype)initWithRequestURL:(NSURL *)requestURL adinfo:(id<CSJAd>)adinfo size:(CGSize)size isNavBarHidden:(BOOL)isNavBarHidden;

- (instancetype)initWithRequestURL:(NSURL *)requestURL adinfo:(id<CSJAd>)adinfo size:(CGSize)size isNavBarHidden:(BOOL)isNavBarHidden landingPageType:(BULandingPageType)landingPageType;

- (instancetype)initWithRequestURL:(NSURL *)requestURL adinfo:(id<CSJAd>)adinfo size:(CGSize)size isNavBarHidden:(BOOL)isNavBarHidden isNativeExpress:(BOOL)isNativeExpress pageType:(BUVideoWebPageType)pageType;

- (instancetype)initWithRequestURL:(NSURL *)requestURL adinfo:(id<CSJAd>)adinfo size:(CGSize)size isNavBarHidden:(BOOL)isNavBarHidden landingPageType:(BULandingPageType)landingPageType isFromClick:(BOOL)isFromClick;

- (void)bu_loadRequest:(NSURL *)requestURL;

/**************** VM related ****************/
@property (nonatomic, strong) CSJWebViewControllerViewModel *webViewModel;

@end

