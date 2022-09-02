//
//  CSJAPIClient.h
//  CSJAdSDK
//
//  Created by chenren on 18/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJAdSlot.h"
#import "CSJMaterialMeta.h"
#import "CSJResponseModel.h"
#import "CSJAPIThrottling.h"
#import "CSJAdSDKDefines+Private.h"
#import "CSJUnionResponseModel.h"
#import "CSJAPIClientConfiguration.h"
NS_ASSUME_NONNULL_BEGIN
@class BUBaseRequest;

typedef NS_ENUM(NSInteger, BUSplashAdLogType) {
    BUSplashAdLogTypeOuter_call = 0,    //外部调用
    BUSplashAdLogTypeOuter_call_send = 1,    //返回外部调用
    BUSplashAdLogTypeOuter_call_no_rsp = 2,    //外部调用无返回
    BUSplashAdLogTypeLoad_creative_error = 3,    //加载素材失败
    BUSplashAdLogTypeLoad_timeout = 4,    //加载超时
    BUSplashAdLogTypeLoad_material_check = 5,  //物料缓存校验结果
};

typedef NS_ENUM(NSInteger,BURewardedVideoRequestType){
    BURewardedVideoRequestType_customer = 1,  //主动调接口 -> update:zth 20210729 表示开发者主动发起的请求
    BURewardedVideoRequestType_auto = 2,      //自动调接口 -> update:zth 20210729 表示sdk自动发起的预加载请求
};

typedef NS_ENUM(NSInteger,BUMissingParameterErrorType){
    BUMissingTitleError = 0,
    BUMissingDescriptionError = 1,
    BUMissingCtaError = 2,
    BUMissingScoreError = 3,
    BUMissingCommentError = 4,
    BUMissingIconError = 5,
};

typedef void (^BUJSONFetchCompletion)(NSDictionary * _Nullable resposeJSON, NSError * _Nullable error);
typedef void (^BUNativeAdsDataFetchCompletion)(NSArray<CSJMaterialMeta *> * _Nullable materialMetas, NSError * _Nullable error);
typedef void (^BUAdFetchCompletion)(id<CSJResponseModel> _Nullable  responseModel, NSError * _Nullable error);
typedef void (^BUAdFetchFailure)(NSError * _Nullable error);
typedef void (^BURewardedVideoCompletion)(NSDictionary * _Nullable dic, NSError * _Nullable error);
typedef void (^BURewardedLiveCompletion)(BOOL isOpen, NSError * _Nullable error);
typedef void (^BUSplashMaterialMetaValid)(BOOL valid);
typedef void (^BUResponseCompletion)(BUBaseRequest *request);
typedef void (^BUNativeAdsJsonDataFetchCompletion)(NSArray<CSJMaterialMeta *> * _Nullable materialMetas, NSDictionary * _Nullable materialMetasJson, NSError * _Nullable error);

@interface CSJAPIClient : NSObject

@property (nonatomic, strong) CSJAPIThrottling *throttling;

+ (instancetype)sharedInstance;

/// 请求动态代码位与rit的映射
- (void)fetchSlotWithCodeGroupId:(NSInteger)codeGroupId completionHandler:(BUJSONFetchCompletion)completion;

/// 正常请求reqtype = 0
- (void)fetchNativeAdsWithAdSlot:(CSJAdSlot *)adslot completionHandler:(BUNativeAdsDataFetchCompletion)completion;

/// 请求物料数据
/// @param configuration 请求配置
/// @param completion 完成callback
- (void)fetchNativeAdsJsonWithConfiguration:(CSJAPIClientConfiguration *)configuration completionHandler:(BUNativeAdsJsonDataFetchCompletion)completion;

/// rewardVideo预加载使用，手动传参reqtype
- (void)fetchNativeAdsWithAdSlot:(CSJAdSlot *)adslot reqType:(BURewardedVideoRequestType)reqType completionHandler:(BUNativeAdsDataFetchCompletion)completion;

/// 鲁班回流页
- (void)fetchNativeAdsJSONWithAdSlot:(CSJAdSlot *)adslot sourceTemaiProductIds:(NSArray *)temaiIds completionHandler:(BUJSONFetchCompletion)completion;

/// 开屏使用的请求
- (void)fetchSplashAdsWithAdSlot:(CSJAdSlot *)adslot requestDictionary:(nullable NSDictionary *)requestDictionary completionHandler:(BUAdFetchCompletion)completion;

/// 4400 serverbidding 预请求
/// @param configuration 请求配置
/// @param completion completion callback
- (void)fetchPreFetchJsonWithConfiguration:(CSJAPIClientConfiguration *)configuration completionHandler:(BUNativeAdsDataFetchCompletion)completion;

/// v4400 server bidding 预请求
- (void)preFetchBiddingAdsWithAdSlot:(CSJAdSlot *)adslot requestID:(NSString *)requestID requestDictionary:(nullable NSDictionary *)requestDictionary completionHandler:(BUNativeAdsDataFetchCompletion)completion;
/// v4400 server bidding 预缓存
- (void)preCacheBiddingAdsWithAdSlot:(CSJAdSlot *)adslot requestDictionary:(nullable NSDictionary *)requestDictionary completionHandler:(BUNativeAdsJsonDataFetchCompletion)completion;
/// v4400 server bidding 异步打包获取物料
- (void)fetchAsyncPackageMaterialsWithAdSlot:(CSJAdSlot *)adslot requestDictionary:(nullable NSDictionary *)requestDictionary completionHandler:(BUNativeAdsDataFetchCompletion)completion;


/// 4500请求微信小程序deeplink链接
/// @param materialMeta 物料信息
/// @param completion 结果回调
- (void)fetchWCMiniappInfoWithMaterialMeta:(CSJMaterialMeta<CSJAd> *)materialMeta completionHandler:(BUJSONFetchCompletion)completion;

/// 检查是否缓存有效
- (void)checkSplashMaterialMetaValid:(CSJMaterialMeta<CSJAd> *)materialMeta completionHandler:(BUSplashMaterialMetaValid)completion;

/// 激励视频上报接口
- (void)rewardedVideoAdRewardVerify:(NSDictionary *)dic completionHandler:(BURewardedVideoCompletion)completion;

/// 激励直播奖励状态
- (void)checkRewardedLiveStateWithMeta:(CSJMaterialMeta<CSJAd> *)materialMeta
    completionHandler:(BURewardedLiveCompletion)completion;

/// bidding链路上报接受聚合平台物料的时间
- (void)reportBiddingReceiveUnionMetarialTimeWithSlot:(CSJAdSlot *)slot;

- (void)reportBiddingADLoadDurationWithSlot:(CSJAdSlot *)slot;

/// download_creative_duration 大图素材下载完成的时长
- (void)reportDownloadImageAdSlot:(CSJAdSlot *)adslot
                     materialMeta:(CSJMaterialMeta *)materialMeta
                         startTime:(CFTimeInterval)startTime
                         imageUrl:(NSURL *)imageUrl
                            image:(nullable UIImage *)image
                        imageData:(nullable NSData * )imageData;

/// load_creative_error 加载素材失败
- (void)reportCreativeErrorWithSlot:(CSJAdSlot *)slot
                        materialMeta:(CSJMaterialMeta *)materialMeta
                            imageUrl:(NSURL *)imageURL
                          imageData:(nullable id)imageData
                              error:(nullable NSError *)error;

/**
 检查遗失字段埋点

 @param slot 请求物料
 @param materialMeta 请求的广告物料material
 */
- (void)checkMaterialMetaMissingparameter:(CSJAdSlot *)slot withMaterialMeta:(CSJMaterialMeta *)materialMeta;

/**
 开屏新增统计展示率埋点

 @param adslot 请求物料
 @param splashAdLogType 事件类型
 @param otherParameter 业务参数字典
 */
- (void)splashAdLogWithAdSlot:(CSJAdSlot *)adslot splashAdLogType:(BUSplashAdLogType)splashAdLogType otherParameter:(nullable NSDictionary *)otherParameter;

- (void)fetchSplashAdsWithAdSlot:(CSJAdSlot *)adslot requestDictionary:(NSDictionary *)requestDictionary reqType:(BURewardedVideoRequestType)reqType completionHandler:(BUAdFetchCompletion)completion;

/**
 nativeExpress新增异常打点统计
 @param adslot 请求物料的adslot
 @param error 发生的error
 */
- (void)nativeExpressAdLogWithAdSlot:(nullable CSJAdSlot *)adslot
                        materialMeta:(nullable CSJMaterialMeta *)materialMeta
                               error:(NSError *)error;

- (void)nativeExpressRetry107WithAdSlot:(CSJAdSlot *)adslot
                           materialMeta:(CSJMaterialMeta *)materialMeta
                                   type:(NSString *)type;
- (void)nativeExpressFetch103WithAdSlot:(CSJAdSlot *)adslot
                           materialMeta:(CSJMaterialMeta *)materialMeta
                                   type:(NSString *)type;

- (void)nativeExpress103TemplateDataDeleteError;
/**
 奖励视频、全屏视频新增icon预加载失败打点
 @param slot 请求物料的adslot
 @param material 请求的广告物料material
 @param error 发生的error
 */
- (void)iconLogWithSlot:(CSJAdSlot*)slot material:(CSJMaterialMeta *)material error:(NSError *)error;

/**
 奖励视频、全屏视频新增兜底endcard展示打点
 @param slot 请求物料的adslot
 @param material 请求的广告物料material
 @param error 展示兜底时webview的error
 */
- (void)rewardVideoWebDefaultViewShowWithSlot:(CSJAdSlot*)slot material:(CSJMaterialMeta *)material error:(NSError *)error;


/// webview reload/崩溃兜底数量+广告信息 统计
/// @param eventName 事件name
/// @param slot 请求物料的adslot
/// @param material 请求的广告物料material
/// @param error 展示兜底时webview的error
- (void)playableWebViewReloadLogWithEventName:(NSString *)eventName slot:(CSJAdSlot *)slot material:(CSJMaterialMeta *)material error:(nullable NSError *)error;
/**
 applog打点
 */
- (void)applogWithParams:(NSDictionary *)params completionHandler:(BUResponseCompletion)completion;

/**
 applog打点
 */
- (void)batchWithParams:(NSDictionary *)params completionHandler:(BUResponseCompletion)completion;

/// 上报广告加载耗时数据
/// @param slot 广告的 slot
- (void)reportADLoadDurationWithSlot:(CSJAdSlot *)slot;

/// 上报素材加载耗时数据
/// @param slot 广告的 slot
- (void)reportDownloadImageDurationWithSlot:(CSJAdSlot *)slot;


/// 上报模版加载耗时数据
/// @param slot 广告的 slot
- (void)reportLoadTemplateDurationWithSlot:(CSJAdSlot *)slot;

/// 上报渲染耗时数据
/// @param slot 广告的 slot
- (void)reportRenderDurationWithSlot:(CSJAdSlot *)slot;


/// 上报加载总耗时耗时数据
/// @param slot 广告的 slot
- (void)reportTotalLoadDurationWithSlot:(CSJAdSlot *)slot;

/// 更新extraData的数组
- (void)updateExtraDict:(NSDictionary*)extraDict;

@end


NS_ASSUME_NONNULL_END
