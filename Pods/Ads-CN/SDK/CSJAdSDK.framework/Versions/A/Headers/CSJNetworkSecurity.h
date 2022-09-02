//
//  CSJNetworkSecurity.h
//  CSJAdSDK
//
//  Created by 袁欢 on 2019/4/2.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
@class BUBaseRequest;
@class CSJUnionRequestModel;
@class CSJAdSlot;
@class BUBaseRequest;

NS_ASSUME_NONNULL_BEGIN

@interface CSJNetworkSecurity : NSObject
@property (nonatomic, assign, readonly, class) BOOL needEncrypt;

/// 升级加密，>=V1990，只用于广告请求
+ (nullable NSDictionary *)encryptRequestModel:(CSJUnionRequestModel *)requestModel adslot:(CSJAdSlot *_Nullable)adSlot;
/// 升级加密，>=V2100，用于setting请求； >=2800用于一般2类加密
+ (nullable NSDictionary *)encryptRequestDictionary:(NSDictionary *)dictionary;
/// 升级加密，>=V2100，用于setting请求； >=2800用于一般2类加密
+ (nullable NSDictionary *)encryptRequestDictionaryWithOutSign:(NSDictionary *)dictionary;
/// 升级加密，>=V2200，用于crash请求
+ (nullable NSDictionary *)encryptRequestArray:(NSArray *)array;
/// 升级加密，>=V3500，用于开屏验证请求
+ (nullable NSString *)encryptString:(NSString *)string;
/// 升级解密，>=V2100，用于广告接口
+ (nullable NSDictionary *)decryptRequestModel:(BUBaseRequest *)requestModel error:(NSError **)error;
/// Mopub AdMarkUp解密，>=V3100
+ (nullable NSDictionary *)decryptAdMarkUp:(NSDictionary *)adm error:(NSError **)error;
/// 升级setting解密，>=V2800，返回message里面的json 字符串，如果解析失败返回message，再则返回空字符串
+ (nullable NSString *)decryptSettingModel:(BUBaseRequest *)requestModel error:(NSError **)error;


/// 加密字符串
+ (nullable NSString *)encryptString:(NSString *)str key:(NSString *)key iv:(nullable NSString *)iv;

/// 加密字典、数组等jsonObject
+ (nullable NSString *)encryptJSONObject:(id)obj key:(NSString *)key iv:(nullable NSString *)iv;

/// 加密NSData
+ (nullable NSString *)encryptData:(NSData *)data key:(NSString *)key iv:(nullable NSString *)iv;
@end

NS_ASSUME_NONNULL_END
