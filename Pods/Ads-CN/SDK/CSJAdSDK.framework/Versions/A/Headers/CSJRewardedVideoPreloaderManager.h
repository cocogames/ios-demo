//
//  BURewardedVideoPreNativeAd.h
//  CSJAdSDK
//
//  Created by 崔亚楠 on 2018/9/14.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>



@class CSJAdSlot;
@class CSJMaterialMeta;
@class BUPersistence;

typedef void(^successGetMateria)(CSJMaterialMeta *materialMeta);
typedef void(^failureGetMateria)(NSError *error);
typedef void(^successLoadVideo)(CSJMaterialMeta *materialMeta,BOOL isPreLoad);
typedef void(^failureLoadVideo) (NSError *error,BOOL isPreLoad);
/**
 缓存复用的结果
 @param isReuse 是否命中了缓存复用, 参看: https://bytedance.feishu.cn/wiki/wikcncIhOV0szdGiwKmAq4uPOGp
 @param preloadType 请求复用预加载时，复用的结果枚举
 @param materialMeta 物料资源, 当preloadType = BUAdPreloadResultNone时, 该值为nil
 */
typedef void(^materiaReuseBlock)(BOOL isReuse, BUAdPreloadResultType preloadType,CSJMaterialMeta * materialMeta);

@interface CSJRewardedVideoPreloaderManager : NSObject
BU_SINGLETION(CSJRewardedVideoPreloaderManager);

/// 请求获取激励video物料
/// @param slot slot实例
/// @param reuse 物料复用结果回调
/// @param success 物料下载成功回调
/// @param failure 物料下载失败回调
/// @param videoSucess 物料中视频资源下载成功回调
- (void)materialMetaForRewardedVideoSlot:(CSJAdSlot *)slot materiaReuse:(materiaReuseBlock)reuse sucess:(successGetMateria)success failure:(failureGetMateria)failure successLoadVideo:(successLoadVideo)videoSucess;

- (void)materialMetaForRewardedVideoSlot:(CSJAdSlot *)slot sucess:(successGetMateria)success failure:(failureGetMateria)failure successLoadVideo:(successLoadVideo)videoSucess;
- (void)loadPreMaterialMetaWithSlot:(CSJAdSlot *)slot;
- (void)callSuccessBlock:(successGetMateria)success withMaterial:(CSJMaterialMeta *)materialMeta;

//激励视频再看一个: 如果展示了一请之后, 直接退出没有展示二请, 此时要清掉内存中的二请
- (void)cleanRewardAgianSecondAdWithSlotId:(NSString *)slotId;
/**
 * Mopub AdMarkUp
*/

- (void)preloadWithMaterialMeta:(CSJMaterialMeta *)materialMeta adSlot:(CSJAdSlot *)adSlot successLoadVideo:(successLoadVideo)videoSucess;

/// 清除全屏激励缓存物料，番茄畅听定制
+ (void)clearCacheRewardedMaterial;

@property (nonatomic, assign) BOOL isAdMarkUp;

@end
