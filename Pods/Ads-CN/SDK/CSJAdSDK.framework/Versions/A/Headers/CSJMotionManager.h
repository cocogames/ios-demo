//
//  CSJMotionManager.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/6/22.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class CSJMotionModel;

NS_ASSUME_NONNULL_BEGIN

@interface CSJMotionModel : NSObject
@property (nonatomic, assign) NSInteger code;
@property (nonatomic, copy) NSString *codeMsg;
@end

@interface CSJMotionManager : NSObject
+ (instancetype)sharedInstance;
//加速计 自动回调
- (CSJMotionModel *)startAccelerometerObserverInterval:(CGFloat)interval
                                   webView:(WKWebView <BURexxarEngine>*)webView;
- (CSJMotionModel *)stopAccelerometerObserverWithWebView:(WKWebView <BURexxarEngine>*)webView;

//陀螺仪 自动回调
- (CSJMotionModel *)startGyroObserverInterval:(CGFloat)interval
                          webView:(WKWebView <BURexxarEngine>*)webView;
- (CSJMotionModel *)stopGyroObserverObserverWithWebView:(WKWebView <BURexxarEngine>*)webView;

- (CSJMotionModel *)startWobbleObserverWebView:(WKWebView <BURexxarEngine>*)webView shakeAmplitude:(CGFloat)shakeAmplitude calculateSize:(NSInteger)calculateSize;
- (CSJMotionModel *)stopWobbleObserverWithWebView:(WKWebView <BURexxarEngine>*)webView;
- (void)wobbleObserverCallBack;

/// 开启监听扭一扭事件
/// @param threshold 单方向超过多少度触发摇一摇事件
/// @param webView webView
- (CSJMotionModel *)startTwistObserverWithThreshold:(NSInteger)threshold
                                           webView:(WKWebView <BURexxarEngine>*)webView;
/// 停止监听扭一扭事件
/// @param webView webView
- (CSJMotionModel *)stopTwistObserverWithWebView:(WKWebView <BURexxarEngine>*)webView;

@end

NS_ASSUME_NONNULL_END
