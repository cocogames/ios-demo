//
//  CSJWebViewController+Private.h
//  CSJAdSDK
//
//  Created by Siwant on 2019/7/2.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJWebViewController.h"




NS_ASSUME_NONNULL_BEGIN

@interface CSJWebViewController ()<UIViewControllerTransitioningDelegate>
///<BUWebViewDelegate, WKScriptMessageHandler, UIViewControllerTransitioningDelegate, WKUIDelegate>
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign, readwrite) BOOL isNavBarHidden;
@property (nonatomic, strong) BUWebViewProgressView *progressView;
@property (nonatomic, assign) BOOL hasEnterBackground;

/// 4300链路优选分屏，第一次点击落地页是否需要上报click
@property (nonatomic, assign) BOOL needReportClick;

- (void)hideCloseButton;
- (void)showCloseButton;
@end

NS_ASSUME_NONNULL_END
