//
//  CSJWebViewPoolManager.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/3.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJWebViewOwner.h"

NS_ASSUME_NONNULL_BEGIN
/**
 1. 动态布局用的webview缓存池
 2. 提高iOSWebView渲染进程渲染SDK的WKWebView的渲染优先级
 */
@interface CSJWebViewPoolManager : NSObject

// 当前的所有的缓存的webView数量
@property (nonatomic, readonly) NSInteger webviewCount;
// 当前的所有的可用的缓存的webView数量
@property (nonatomic, readonly) NSInteger availableCacheCount;
// 当前的所有的正在被使用的webView数量
@property (nonatomic, readonly) NSInteger usedCount;
#pragma mark - WKWebView Priority
- (void)promote_webViewPriorityWithView:(UIView *)view;
- (void)resume_webViewPriorityWithView:(UIView *)view;

#pragma mark - Public
- (CSJWebViewOwner *)usableWebViewOwnerWithFrame:(CGRect)frame;
// 当出现加载失败的时候
- (void)removeCacheWebViewClient:(CSJWKWebViewClient *)client;
- (void)clearAll;

#pragma mark - Signal
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
