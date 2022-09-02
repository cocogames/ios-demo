//
//  CSJAppStoreManager.h
//  DTWebView
//
//  Created by Siwant on 2018/9/10.
//  Copyright © 2018年 www. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>
#import "SKStoreProductViewController+CSJAPublic.h"
#import "CSJSKANStoreProductModel.h"
#import "CSJAdSDKDefines+Private.h"

NS_ASSUME_NONNULL_BEGIN

@class BUStoreProductViewController;



typedef NS_ENUM(NSInteger, BUAppStorePreloadType)
{
    BUAppStorePreloadTypeNone = 0, // 不支持预加载
    BUAppStorePreloadTypeOnce = 1, // 只与预载一次
    BUAppStorePreloadTypeAlways = 2,// 总是预加载
};

typedef NS_ENUM(NSInteger, BUAppStoreOpenType)
{
    BUAppStoreOpenTypeFailed = 0,  //未能打开
    BUAppStoreOpenTypeOpenURL = 1, // 外开
    BUAppStoreOpenTypeSKStore = 2, // 内开
};

@interface CSJAppStoreManager : NSObject

/// 是否仅在wifi条件下预加载, 默认YES
@property (nonatomic, assign) BOOL preloadOnlyWIFI;

/// 最大预加载数量, 默认为1
@property (nonatomic, assign) NSUInteger maxPreloadCount;

/// 回退开关
@property (nonatomic, assign) BOOL isReusePreload;

/// 预加载支持类型
@property (nonatomic, assign, readonly) BUAppStorePreloadType supportPreloadType;

/// 控制present SKStoreProductViewController时是否动画, 默认YES.
/// 自定义转场动画有可能导致SKStoreProductViewController弹出失败，为了兼容这种情况可以
/// 设置present时没有动画，没有动画不会影响SKStoreProductViewController弹出的动画效果,
/// 设置后通过BUAppStoreManager打开的SKStoreProductViewController都会生效
@property (nonatomic, assign) BOOL isPresentAnimated;

//@property (nonatomic, assign) BOOL presenting;
//模板视频页面 jsb 传值, 如果非 0 , 则为 半屏打开App Store
@property (nonatomic, assign) CGFloat appStore_top;

+ (instancetype)sharedManager;

/**
 根据AppID进行预加载
 */
+ (void)preloadAppStoreControllerWithAppID:(NSString *)appId param:(CSJSKANStoreProductModel *)networkParam;

+ (void)preloadAppStoreControllerWithAppID:(NSString *)appId
                                     param:(CSJSKANStoreProductModel *)networkParam
                                completion:(nullable void(^)(BOOL result, NSError *__nullable error))completion;

/**
 根据AppID进行预加载
 
 @param appId 应用ID
 @param adModel 实现BUAd协议的类
 @param completion 结束block
 */
+ (void)preloadAppStoreControllerWithAppID:(NSString *)appId
                                     param:(CSJSKANStoreProductModel *)networkParam
                                   adModel:(id<CSJAd>)adModel
                                completion:(nullable void(^)(BOOL result, NSError *__nullable error))completion;

+ (void)preloadAppStoreControllerWithAppID:(NSString *)appId
                                     param:(CSJSKANStoreProductModel *)networkParam
                                   adModel:(id<CSJAd>)adModel
                               isDuplicate:(BOOL)isDuplicate
                                completion:(nullable void(^)(BOOL result, NSError *__nullable error))completion;


/**
 打开SKController页面，默认使用预加载资源
 
 @param appId AppStoreID
 @param controller 显示SKController的容器Controller
 */
+ (BUAppStoreOpenType)openAppStoreControllerWithAppID:(NSString *)appId
                                  param:(CSJSKANStoreProductModel *)networkParam
                           byController:(UIViewController *)controller;

+ (BUAppStoreOpenType)openAppStoreControllerWithAppID:(NSString *)appId
                                  param:(CSJSKANStoreProductModel *)networkParam
                           byController:(UIViewController *)controller
                      presentCompletion:(void (^ __nullable)(void))presentCompletion
                      dismissCompletion:(void (^ __nullable)(void))dismissCompletion;

+ (BUAppStoreOpenType)openAppStoreControllerWithAppID:(NSString *)appId
                                  param:(CSJSKANStoreProductModel *)networkParam
                                              adModel:(id<CSJAd>)adModel
                           byController:(UIViewController *)controller
                      presentCompletion:(void (^ __nullable)(void))presentCompletion
                      dismissCompletion:(void (^ __nullable)(void))dismissCompletion;

+ (BUAppStoreOpenType)openAppStoreControllerWithAppID:(NSString *)appId
                                  param:(CSJSKANStoreProductModel *)networkParam
                            downloadUrl:(nullable NSString *)downloadUrl
                                              adModel:(id<CSJAd>)adModel
                           byController:(UIViewController *)controller
                      presentCompletion:(void (^ __nullable)(void))presentCompletion
                      dismissCompletion:(void (^ __nullable)(void))dismissCompletion;


- (BUAppStoreOpenType)openAppStoreOpenTypeWithAppID:(NSString *)appId
                                        downloadUrl:(nullable NSString *)downloadUrl;
/**
 获取已预加载SKController
 如果没有预加载资源或预加载失败则返回nil,需外部设置delegate.
 */
+ (nullable SKStoreProductViewController *)controllerPreloadedByAppID:(NSString *)appId;

+ (BOOL)hasControllerPreloadedByAppID:(NSString *)appId;

/**
 清除指定appId的预加载资源
 */
+ (void)clearPreloadCacheByAppID:(NSString *)appId;

+ (void)clearPreloadCacheBySKController:(SKStoreProductViewController *)controller;



///**
// 获取 SKStoreProductViewController 方法，此方法必须在主线程调用！！！
// 
// @param appId 要加载的 Apple ID
// @param adId 广告 ID
// @param logExtra 广告相关数据
// @return 对应 SKStoreProductViewController，可能是新创建的，可能是从预加载队列中获取的。
// */
//+ (nonnull SKStoreProductViewController *)controllerWithAppID:(NSString *)appId
//                                                          adId:(NSString *)adId
//                                                      logExtra:(NSString *)logExtra;
//
///**
// 获取 SKStoreProductViewController 方法，此方法必须在主线程调用！！！
// 
// @param appId 要加载的 Apple ID
// @param adId 广告 ID
// @param logExtra 广告相关数据
// @param animated SKStoreProductViewController dismiss 时是否有动画
// @return 对应 SKStoreProductViewController，可能是新创建的，可能是从预加载队列中获取的。
// */
//+ (nonnull SKStoreProductViewController *)controllerWithAppID:(NSString *)appId
//                                                          adId:(NSString *)adId
//                                                      logExtra:(NSString *)logExtra
//                                              dismiassAnimated:(BOOL)animated;


/**
 获取半屏的 SKStoreProductViewController
 
 @param appId 要加载的 Apple ID
 @param animated SKStoreProductViewController dimiss 时是否有动画
 @return 对应 SKStoreProductViewController，从预加载队列中获取。
 */
+ (nonnull SKStoreProductViewController *)duplicatedControllerWithAppID:(NSString *)appId
                                                        dismiassAnimated:(BOOL)animated;

/**
 从url中提取AppID (废弃)
 */
+ (nullable NSString *)appIDInURL:(NSString *)urlString DEPRECATED_MSG_ATTRIBUTE("Method deprecated");


/// 获取是否已经打开
- (BOOL)isPresenting;

@end

/**
 Notifications
 */
typedef NSString *BUAppStoreNotificationName NS_EXTENSIBLE_STRING_ENUM;

FOUNDATION_EXTERN BUAppStoreNotificationName const CSJAppStorePreloadStartNotification;
FOUNDATION_EXTERN BUAppStoreNotificationName const CSJAppStorePreloadFinishNotification;
FOUNDATION_EXTERN BUAppStoreNotificationName const CSJAppStorePreloadErrorNotification;
FOUNDATION_EXTERN BUAppStoreNotificationName const CSJAppStoreOpenLoadSuccessNotification;
FOUNDATION_EXTERN BUAppStoreNotificationName const CSJAppStoreOpenLoadFailNotification;

FOUNDATION_EXTERN BUAppStoreNotificationName const CSJAppStoreControllerWillAppearNotification;
FOUNDATION_EXTERN BUAppStoreNotificationName const CSJAppStoreControllerDidAppearNotification;
FOUNDATION_EXTERN BUAppStoreNotificationName const CSJAppStoreControllerDidDisappearNotification;

FOUNDATION_EXTERN NSString * const CSJAppStoreNotificationAppIDKey;
FOUNDATION_EXTERN NSString * const CSJAppStoreNotificationShowTimeKey;
FOUNDATION_EXTERN NSString * const CSJAppStoreNotificationErrorKey;
FOUNDATION_EXTERN NSString * const CSJAppStoreNotificationIsHalfKey;
FOUNDATION_EXTERN NSString * const CSJAppStoreNotificationAdModel;

NS_ASSUME_NONNULL_END
