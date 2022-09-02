//
//  CSJSDKAuxiliary+NetWorkConstant.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/8/27.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJSDKAuxiliary.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJSDKAuxiliary (NetWorkConstant)
/* ************************************** BUNetWorkConstant ************************************** */
#pragma mark - 广告域名
/// 广告默认域名
+ (NSString *)bu_URL_BASE_AD;
/// 广告默认备用域名
+ (NSString *)bu_URL_BASE_AD_BACKUP;
/// 请求联盟广告的 服务器地址
+ (NSString *)bu_URI_UnionAd;
/// 激励视频发放奖励验证
+ (NSString *)bu_URI_RewardedVideoRewardVerify;
/// 激励直播
+ (NSString *)bu_URI_RewardedLive;
/// 开屏缓存数据验证接口
+ (NSString *)bu_URI_SplashCheckCacheVaild;
/// 广告频控报警
/// V1.9.3 SDK开屏新增埋点 SDK目前开屏展示率较低，为了方便排查及针对开屏广告位切换新的展示率计算方式，需要新增埋点统计；
/// V1.9.8 新增原生广告埋点,请求数据到获得数据的事件
+ (NSString *)bu_URI_Stats;
/// 2700 stats替代接口，支持批量上传，@available(V2.7.0.0, *)
+ (NSString *)bu_URI_Batch;
/// 网盟 setting 接口 V1.9.5 新加接口(旧接口放弃维护) https://wiki.bytedance.net/pages/viewpage.action?pageId=217636563
+ (NSString *)bu_URI_Setting;
/// Dislike 上报接口
+ (NSString *)bu_URI_Dislike;
/// 发券
+ (NSString *)bu_URI_ApplyCoupon;
#pragma mark - 埋点域名
+ (NSString *)bu_URL_BASE_Extlog;
/// 测试包ET平台上报地址
+ (NSString *)bu_URL_BASE_Extlog_ForETTest;
#pragma mark - TNC域名
+ (NSArray<NSString*> *)bu_URL_BASE_TNC;
/// TNC get - domin
+ (NSString *)bu_URI_TNC_GetDomins;
#pragma mark - Other
+ (NSString *)bu_URL_template;
///GDPR合规协议兜底地址
+ (NSString *)bu_GDPR_URL;
/// playable_test_icon_url
+ (NSString *)bu_playable_test_icon_url;
/// playable_test_video_url
+ (NSString *)bu_playable_test_video_url;
/// AEM upload URL
+ (NSString *)bu_aem_upload_url;
/// 动态代码位映射
+ (NSString *)bu_URI_Get_Dynamic_Slot;

/// 4400 serverbidding 预缓存
+ (NSString *)bu_URI_Serverbidding_PreCache;
/// 4400 serverbidding 预请求
+ (NSString *)bu_URI_Serverbidding_PreFetch;
/// 4400 serverbidding 异步打包获取物料
+ (NSString *)bu_URI_Servidebidding_GetMaterials;

/// 4600 playable signal url
+ (NSString *)bu_url_playable_cold_start;

/// 4700 渠道检测信息上传
+ (NSString *)bu_URI_Channel_Detect;

@end

NS_ASSUME_NONNULL_END
