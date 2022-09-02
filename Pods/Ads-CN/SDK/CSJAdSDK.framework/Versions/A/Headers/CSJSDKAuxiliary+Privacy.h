//
//  CSJSDKAuxiliary+Privacy.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/9/2.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJSDKAuxiliary.h"

@class CTTelephonyNetworkInfo;

NS_ASSUME_NONNULL_BEGIN

static NSString *const CSJ_Auxiliary_idfa              = @"idfa";
static NSString *const CSJ_Auxiliary_pb                = @"pb";
static NSString *const CSJ_Auxiliary_longitude         = @"longitude";
static NSString *const CSJ_Auxiliary_latitude          = @"latitude";
static NSString *const CSJ_Auxiliary_mcc               = @"mcc";
static NSString *const CSJ_Auxiliary_mnc               = @"mnc";
static NSString *const CSJ_Auxiliary_phone_name        = @"phone_name";
static NSString *const CSJ_Auxiliary_boot              = @"boot";
static NSString *const CSJ_Auxiliary_power_on_time     = @"power_on_time";

@interface CSJSDKAuxiliary (Privacy)
///开启定位
+ (void)requestLatestStatus;
///设置隐私控制
+ (void)bu_setPrivacyInfo:(NSDictionary *)privacyInfo;
///0 (不进行 ad 请求/上报) 1 (执行 ad 请求/上报）3300 add
+ (NSInteger)bu_AdEnable;
///0不下发广告 1下发非个性化 2下发个性化）3300 add
+ (NSInteger)bu_personalized_ad;
///0(不初始化) 1(初始化) - 目前不支持GDPR，之后sdk合入新版本后，依据版本号打开  3300 add
+ (NSInteger)bu_sladar_enable;
///0(不输出debug日志) 1(SDK默认值，服务端不下发、或下发异常值时认定为1 输出debug日志) 3800 add
+ (NSInteger)bu_debugLog_enable;
///0(不初始化) 1(初始化) - 目前不支持GDPR）3300 add
+ (NSInteger)bu_app_log_enable;
///0(不初始化) 1(初始化) ）3300 add
+ (NSInteger)bu_sec_enable;
///隐私字段白名单3300 add
+ (NSArray *)bu_fields_allowed_array;
///隐私字段白名单3300 add
+ (BOOL)bu_fields_allowed:(NSString *)key;
///获取隐私字段
+ (id)bu_getInformation:(NSString *)key;

+ (void)bu_setCustomIDFA:(NSString *)IDFA;
///获取原始idfa
+ (NSString *)bu_getOriginalIDFA;
///兜底的network id
+ (NSArray *)bu_skadNetwork_id_array;
///获取countryCode
+ (NSString *)bu_countryOrderNum;

#pragma mark - test method
+ (void)bu_setTestLongitude:(NSNumber * _Nullable)testLongitude;
+ (void)bu_setTestLatitude:(NSNumber * _Nullable)testLatitude;
@end

NS_ASSUME_NONNULL_END
