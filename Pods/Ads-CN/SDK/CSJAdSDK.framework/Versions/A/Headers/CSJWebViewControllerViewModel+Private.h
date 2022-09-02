//
//  CSJWebViewControllerViewModel+Private.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

//#import "CSJWebViewControllerViewModel.h"
//
//NS_ASSUME_NONNULL_BEGIN
//
//@interface CSJWebViewControllerViewModel (Private)
//
//@end
//
//NS_ASSUME_NONNULL_END





#import "CSJCustomNavigationBarView.h"
NS_ASSUME_NONNULL_BEGIN
@class CSJCustomNavigationBarView, CSJWebViewBottomBar;
@interface CSJWebViewControllerViewModel () <WKScriptMessageHandler, UIViewControllerTransitioningDelegate, WKUIDelegate, CSJCustomNavigationBarDelegate>
@property (nonatomic, assign) CGSize size;
@property (nonatomic, strong) CSJCustomNavigationBarView *customNavigationView;
@property (nonatomic, strong) CSJWebViewBottomBar *bottomBar;
@property (nonatomic, assign, readwrite) BOOL isNavBarHidden;
@property (nonatomic, strong) BUWebViewProgressView *progressView;
@property (nonatomic, assign) BOOL hasEnterBackground;

/// 4300链路优选分屏，第一次点击落地页是否需要上报click
@property (nonatomic, assign) BOOL needReportClick;

- (void)hiddenCloseButton;
- (void)showCloseButton;
@end

NS_ASSUME_NONNULL_END
