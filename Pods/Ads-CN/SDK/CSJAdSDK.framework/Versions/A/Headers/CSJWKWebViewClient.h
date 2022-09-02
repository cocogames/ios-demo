//
//  CSJWKWebViewClient.h
//  CSJAdSDK
//
//  Created by 李盛 on 2019/10/21.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJMaterialMeta+Private.h"

#import "CSJAdInfoViewModel.h"

NS_ASSUME_NONNULL_BEGIN

// xzj_todo 这个枚举值放在这里不一定好
typedef NS_ENUM(NSUInteger, BULinkLogType) {
    BULinkLogTypeExpress = 1,
    BULinkLogTypeEndcard = 2,
    BULinkLogTypePlayable = 3,
    BULinkLogTypeLandingPage = 4,
    BULinkLogTypeVideoDetail = 5
};

@class CSJJSB3ExecuteUnitViewModel;

@protocol CSJWKWebViewClientResponseDelegate <NSObject>

@optional
- (void)responseView:(UIView*)view hitTest:(CGPoint)point withEvent:(UIEvent *)event;

@end

@protocol CSJWKWebViewClientInterceptionDelegate <NSObject>

@optional
- (void)buWKWebViewClientInterceptedWithStartTime:(NSTimeInterval)startTime url:(NSString *)urlStr type:(NSString *)type isCache:(BOOL)isCache extraDic:(NSDictionary *_Nullable)extraDic;

@end

@interface CSJWKWebViewClient : BUWKWebView
/// 统计各个阶段打点的数据
@property (nonatomic, strong, readonly) BUThreadSafeDictionary *logDictinary;
/// 存储 webview 拦截的信息
@property (nonatomic, strong) BUThreadSafeMutableArray *interceptArray;
/// 3200落地页预加载, 需要传递物料信息
@property (nonatomic, strong) CSJMaterialMeta *targetMaterialMeta;
@property (nonatomic, strong) CSJAdInfoViewModel *targetInfoViewModel;

// 是否渲染成功了
@property (nonatomic, assign) BOOL reallyRenderSuccess;

//3400需求: 帮助前端统计资源加载列表
@property (nonatomic, assign) CGFloat startLoadTime;
@property (nonatomic, strong) BUThreadSafeMutableArray *interceptResourceList;

/// 拦截资源的代理
@property (nonatomic, weak) id <CSJWKWebViewClientInterceptionDelegate>interceptDelegate;

/// 3900 add
@property (nonatomic, weak) id <CSJWKWebViewClientResponseDelegate> responseDelegate;

/// 是否操作过
@property (nonatomic, assign) BOOL haveTouched;
@property (nonatomic, assign) BOOL didShow;

- (instancetype)initWithFrame:(CGRect)frame offlineMode:(BOOL)offlineMode;
- (instancetype)init NS_UNAVAILABLE;
//- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame configuration:(WKWebViewConfiguration *)configuration NS_UNAVAILABLE;

#pragma mark - Dynamic Layout track
/// 设置当前打点时机
- (void)setCurrentLogType:(NSString *)logType extraDic:(NSDictionary *_Nullable)extraDic;


- (nullable NSDictionary *)getInterceptDictWithStartTime:(NSTimeInterval)startTime url:(NSString *)urlStr type:(NSString *)type isCache:(BOOL)isCache extraDic:(NSDictionary *_Nullable)extraDic;

//3400需求: 帮助前端统计资源加载列表
- (NSDictionary *)getInterceptResourceListDictWithStartTime:(NSTimeInterval)startTime url:(NSString *)urlStr data:(NSData *)data extraDic:(NSDictionary *_Nullable)extraDic;

/// 获取当前时间
- (NSTimeInterval)getCurrentTime;

#pragma mark - JSB3
@property (nonatomic, copy) void(^jsCallNativeBlock)(CSJJSB3ExecuteUnitViewModel *viewModel);
- (void)addScriptMessageWithHandler:(id<WKScriptMessageHandler>)handler name:(NSString *)name;

@end



NS_ASSUME_NONNULL_END
