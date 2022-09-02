//
//  CSJRewardedVideoPreloader.h
//  CSJAdSDK
//
//  Created by gdp on 2018/1/23.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJMaterialMeta.h"
#import "CSJAdSlot.h"
#import "CSJSplashPrecacheVideoModel.h"

@interface CSJRewardedVideoPreloader : NSObject// 扩展到支持激励、全屏、开屏视频缓存

// 成功回调缓存文件的 NSURL 地址
typedef void(^videoSuccess)(NSURL *url, NSString *videoUrlString, BOOL fromCache);
typedef void(^videoFailure)(NSError *error, NSString *videoUrlString);

+ (instancetype)sharedPreloader;

- (void)preloadVideoFileWithMaterial:(CSJMaterialMeta*)meta adSlotAdType:(BUAdSlotAdType)adType success:(videoSuccess)success failure:(videoFailure)failure;

// 品牌视频加载：优先缓存，缓存没有直接下载
- (void)loadBrandVideoFileWithMaterial:(CSJMaterialMeta *)meta
                          adSlotAdType:(BUAdSlotAdType)adType
                               success:(videoSuccess)success
                               failure:(videoFailure)failure;

// 品牌视频预加载
- (void)preloadBrandVideoFileWithMaterial:(CSJMaterialMeta *)meta
                               videoModel:(CSJSplashPrecacheVideoModel *)VideoModel
                             adSlotAdType:(BUAdSlotAdType)adType
                                  success:(videoSuccess)success
                                  failure:(videoFailure)failure;

- (NSURL *)cachedVideoLocalURLWithUrl:(NSString *)urlStr fileHash:(NSString *)filehash adSlotAdType:(BUAdSlotAdType)adType;

- (NSURL *)cachedBrandVideoLocalURLWithUrl:(NSString *)urlStr fileHash:(NSString *)filehash;

- (void)resumeLoadingQueue;
- (void)suspendedLoadingQueue;

- (void)deleteLocalVideoWithAdSlotAdType:(BUAdSlotAdType)adType;
@end
