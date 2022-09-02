//
//  CSJAdServerBiddingMaterialManager.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/2/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJMaterialMeta;
@class CSJAdSlot;

typedef void(^BUServerBiddingMaterialSuccessBlock)(NSArray<CSJMaterialMeta *> * _Nullable materials);
typedef void(^BUServerBiddingMaterialFailureBlock)(NSError * _Nullable error);
@interface CSJAdServerBiddingMaterialManager : NSObject
+ (instancetype)manager;

/// 设置的Adm是否可用
/// @param decrypyAdm adm
+ (BOOL)invalidDecrypyAdm:(NSDictionary *)decrypyAdm;

/// 获取预缓存物料信息，不是完整物料
/// @param slot An ad slot instance
/// @param error error
+ (nullable NSDictionary *)getBiddingPreCacheInfoWithSlot:(CSJAdSlot *)slot error:(NSError **)error;

/// 获取预缓存物料，完整物料
/// @param slot An ad slot instance
/// @param error error
+ (nullable CSJMaterialMeta *)getBiddingPreCacheMaterialWithSlot:(CSJAdSlot *)slot error:(NSError **)error;
/// 获取预请求物料，完整物料
/// @param creatives adm creatives
/// @param slot An ad slot instance
+ (NSArray<CSJMaterialMeta *> *)getBiddingPreFetchMaterialWithAdmCreatives:(NSArray *)creatives slot:(CSJAdSlot *)slot;

/// 预请求
/// @param slot Ad slot instance
/// @param requestID GetBiddingToken的requestID
/// @param success success callback
/// @param failure failure callback
+ (void)biddingPreFetchMaterialWithSlot:(CSJAdSlot *)slot requestID:(NSString *)requestID success:(BUServerBiddingMaterialSuccessBlock _Nullable)success failure:(BUServerBiddingMaterialFailureBlock _Nullable)failure;

/// 预缓存
/// @param slot Ad slot instance
/// @param success success callback
/// @param failure failure callback
+ (void)biddingPreCacheMaterialWithSlot:(CSJAdSlot *)slot success:(BUServerBiddingMaterialSuccessBlock _Nullable)success failure:(BUServerBiddingMaterialFailureBlock _Nullable)failure;

/// 异步打包，请求物料
/// @param slot An ad slot instance
/// @param adm adm
/// @param success success callback
/// @param failure failure callback
+ (void)biddingGetMaterialWithSlot:(CSJAdSlot *)slot adm:(NSDictionary *)adm success:(BUServerBiddingMaterialSuccessBlock _Nullable)success failure:(BUServerBiddingMaterialFailureBlock _Nullable)failure;

/// 移除缓存物料
/// @param materialMeta material key
/// @param adSlot An Ad slot Instance
+ (void)removeMaterialWithMaterialMeta:(CSJMaterialMeta *)materialMeta adSlot:(CSJAdSlot *)adSlot;

@end

NS_ASSUME_NONNULL_END
