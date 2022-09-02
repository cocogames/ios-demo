//
//  CSJSDKAuxiliary+ThirdParty.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/9/7.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJSDKAuxiliary.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ApplogInitCallBack)(NSString *applogID);

typedef void (^StatsBlock)(NSDictionary * _Nullable dic , NSInteger type);

@interface CSJSDKAuxiliary (ThirdParty)
#pragma mark - Applog

/// 设置Applog‘s delegate
/// @param delegate delegate
+ (void)setEBApplogDelegate:(id)delegate;

/// 启动EBApplog
+ (void)initApplog:(NSDictionary *)infoDic block:(ApplogInitCallBack)block;
#pragma mark - Sec

/// 启动Sec
/// @param delegate delegate
+ (id)initSecGuardWithDelegate:(id)delegate appId:(NSString *)appId;

/**
 * 对bodyMD5Hex+deviceID+ts加签，不要在意名字
 * 原始数据格式：bodyMD5Hex_deviceID_ts
 * @param bodyMD5Hex post请求body的MD5 HEXString
 * @return 加签后的hexStr，拼接到请求里
 * @description 如果接入方自己做服务，那参数传什么都可以
 */
// 旧版本的有关sec签名
+ (NSString *)bodyEncry:(NSString *)bodyMD5Hex;
// 新版本的有关sec签名
+ (NSDictionary *)doHttpReqSignByUrl:(NSString *)urlString body:(NSData *)bodyData;
//新版本获取secdid
+ (NSString *)getMsDidToken;

/// 发送did
+ (void)sendWithDid:(NSString *)did;

+ (void)statsTrackerBlock:(void (^)(NSDictionary * _Nullable dic , NSInteger type))statsBlock;

#pragma mark - APM

/// 初始化APM:国内HeimdallrToB 国外APMInsight
/// @param rangs rangs
+ (void)initAPMWithRange:(NSArray *)rangs info:(NSDictionary *)info statsBlock:(void (^)(NSDictionary * _Nullable dic , NSInteger type))block;

#pragma mark - Gecko
+ (NSString *)gecko_IESGeckoKitAppId;
+ (NSString *)gecko_IESGeckoKitAccessKey;
+ (NSString *)gecko_IESGeckoKit_CACHE_DIRECTORY;
+ (NSArray *)gecko_IESGeckoKit_Domains;

@end

NS_ASSUME_NONNULL_END
