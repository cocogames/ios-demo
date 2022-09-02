//
//  CSJUSettingService.h
//  CSJAdSDK
//
//  Created by carl on 2017/10/20.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJURitSettingModel.h"
#import "CSJABTest.h"


@class CSJLogRateConfigModel, CSJInsertJSConfigModel, CSJClogConfigModel;



// 默认的最大
#define kBUUSettingServiceMaxCount         100

// 1:表示模板banner dislike操作后不再轮播  0:表示dislike操作后可以继续轮播
typedef NS_ENUM(NSInteger, BURotateBannerDislikeViewType) {
    BURotateBannerDislikeViewType_Rotate = 0,
    BURotateBannerDislikeViewType_NonRotate = 1,
};

/**
 adlog_enable_type:  (iOS 只支持0和3)
 0：使用旧埋点
 1：新性能埋点上报，旧广告埋点上报
 2：新广告埋点上报，旧性能上报
 3：全部使用新版的广告、性能埋点
 */
typedef NS_ENUM(NSInteger, BUAdLogEnableType) {
    BUAdLogEnableType_OldAll                    =       0,
    BUAdLogEnableType_StatusOld_ApplogNew       =       1,
    BUAdLogEnableType_StatusNew_ApplogOld       =       2,
    BUAdLogEnableType_NewAll                    =       3,
};

@interface CSJUSettingService : NSObject
/*rit粒度的配置*/
@property (atomic, strong) BUThreadSafeDictionary *configList;

/*app粒度的配置*/
/// xpath
@property (atomic, copy) NSString *xpath;
/// 请求策略
@property (atomic, strong) NSDictionary *policy;
/// 激励视频缓冲时间 默认5s
@property (atomic, strong) NSNumber *vbtt;
/// 是否开启边下边播功能,默认开启
@property (nonatomic, assign) BOOL isReadVideoFromCache;
/// 广告域名
@property (atomic, copy) NSString *adsUrl;
/// app_log上报地址
@property (atomic, copy) NSString *appLogUrl;

/// FL 圈人群的id
@property (atomic, copy) NSString *cohort_id;

/// 是否初始化pitaya
@property (nonatomic, assign) BOOL pitaya_init;

/// pitaya host
@property (atomic, copy) NSString *pitaya_host;

/// pitaya_cer_host
@property (atomic, copy) NSString *pitaya_cer_host;

/// 海外apm url
@property (atomic, copy) NSString *apmOverseaUrl;
/// 服务器所在地址，国内、新加坡、中东
//@property (nonatomic, copy) NSString *dc;
/// 动态布局模板增量的id集合
//@property (nonatomic, copy) NSArray *tplIds_infos;
//@property (nonatomic, copy) NSArray *tplIds;
/// SDK总开关
@property (nonatomic, assign, readonly) BOOL silenceSDK;
/// setting试验 是否灰度
@property (nonatomic, assign) BOOL isGrey;
/// 是否监控crash
@property (nonatomic, assign) BOOL collectCrash;
/// setting AB test
@property (atomic, strong) CSJABTest *abtest;
/// playable需要拦截的字段
@property (atomic, copy) NSArray *playableInterceptAry;
/// playable的loading页面
@property (atomic, copy) NSString *purePyloadH5;
/// v2700 0,1,2,3 默认1 https://bytedance.feishu.cn/space/doc/doccn7W9DGNpZRFG8ZIE8N287Re
//@property (nonatomic, assign) BUSplashLoadType splashLoadType;
/// v2700 默认开启校验 0:check逻辑分支不校验check接口，仅验证缓存逻辑 1:开启校验
@property (nonatomic, assign) BOOL checkTypeOpen;
/// 是否为国外
//@property (nonatomic, assign) BOOL overSeas;
/// 区域类型CN，VA，SG
//@property (nonatomic, assign) BUTerritoryType territoryType;
/// 离线化动态布局+playable宽展的headers字段
@property (atomic, strong) NSDictionary *headersExt;
/// if_both_open 开启同时打开deeplink
@property (nonatomic, assign) NSInteger bothOpen;
/// 是否支持TNC容灾切流，默认1
@property (nonatomic, assign) NSInteger supportTNC;
/// 海外隐私协议地址
@property (atomic, copy) NSString *privacy_url;
/// 用户同意链接
@property (atomic, copy) NSString *consent_url;
/// 动态布局子模板缓存的最大数量
@property (nonatomic, assign) NSInteger max_tpl_cnts;
/// 动态布局主模板地址动态下发
@property (atomic, copy) NSString *dyn_draw_engine_url;
/// 动态布局兜底超时时长配置
@property (nonatomic, assign) NSInteger fetch_tpl_timeout_ctrl;
/// 后端下发的强制语言类型
@property (atomic, copy) NSString *force_language;
/// 循环加载duration 控制 min
@property (nonatomic, assign) NSInteger circle_time;
/// 是否开启循环加载 1 开启, 2不开启(默认)
@property (nonatomic, assign) NSInteger circle_splash;
/// 落地页吊起白名单
@property (atomic, copy) NSArray *scheme_wlist;
/// 开屏点睛需求:浮窗展示时长
@property (nonatomic, assign) NSInteger icon_show_time;
/// 3200需求: gecko 容灾域名
@property (atomic, copy) NSArray *gecko_hosts;
/// 是否关闭动态代码组功能
@property (nonatomic, assign) BOOL disable_dynamic_code_group;
/// 动态代码缓存时长,单位为s,默认3600s
@property (nonatomic, assign) NSInteger dynamic_code_group_cache_time;

// webView缓存池最大数量
@property (nonatomic, assign) NSInteger webViewPoolCacheMaxCount;
// webView最大并发渲染数
@property (nonatomic, assign) NSInteger webViewRenderMaxConcurrentOperationCount;
// dislike操作后的是否轮播标识
@property (nonatomic, assign) BURotateBannerDislikeViewType rotateBannerDislike;

/// 是否初始化apm模块 默认为YES
@property (nonatomic, assign, readonly) BOOL isInitCrashModule;
/// 内开浏览器样式
@property (nonatomic, assign) BOOL lpNewStyle;

/**
 配置的SD最大缓存个数 , 默认值为: 6
 @Version 4100
 */
@property (nonatomic, assign) NSInteger sdMaxMemoryCount;

///视频缓存动态下发
@property (nonatomic, assign) NSInteger video_cache_splash_num;

@property (nonatomic, assign) NSInteger video_cache_reward_num;

@property (nonatomic, assign) NSInteger video_cache_brand_num;

@property (nonatomic, assign) NSInteger video_cache_other_num;

/**
 配置的SD最大缓存大小 默认值为:24 , 单位为M
 @Version 4100
 */
@property (nonatomic, assign) NSInteger sdMaxMemoryCost ;

/// 4300是否开启webview黑白屏检测，1：开启 0：关闭 默认下发1
@property (nonatomic, assign) NSInteger enable_bw_screen_detection;
@property (atomic, strong) CSJInsertJSConfigModel *insertJSConfig;
@property (atomic, strong) CSJClogConfigModel *clogConfig;

// 是否有并发渲染的功能
- (BOOL)hasWebViewRenderConcurrentFunction;

/// 3300需求：支持iOS 14，穿山甲的SKAdNetwork IDs，不会为nil
@property (atomic, copy, readonly) NSArray<NSString *> *network_id_list;
/// 3500 需求：服务端会在 settings 返回报文增加埋点采样率字段
@property (atomic, strong) CSJLogRateConfigModel *logRateConf;
// 4250 海外需求 服务端在settings下发 appstore拦截域名以及appId匹配正则
@property (atomic, strong, readonly) NSArray<NSString *> *lp_hook_host_list;
@property (atomic, copy, readonly) NSString *lp_hook_reg_rule;

// 4500 开屏卡片每天展示次数 若未下发，取默认值3
@property (nonatomic, assign) NSInteger splashCardShowMaxCount;

// 4600 品牌视频预缓存最大数量
@property (nonatomic, assign) NSInteger precacheBrandVideoCount;

/// 预渲染数量控制
@property (nonatomic, assign) NSInteger playable_landing_cache_count;
+ (instancetype)service;
- (void)fetchSetting;
- (CSJURitSettingModel *)modelWithRit:(NSString *)rit;
+ (void)deleteLocalSetting;


// 新旧埋点 控制字段  https://bytedance.feishu.cn/wiki/wikcniIx9ve1eilblF7mVrUgRPh
@property (nonatomic, assign) BUAdLogEnableType adlog_enable_type;
@property (atomic, assign) NSInteger adlog_interval;
@property (atomic, assign) NSInteger adlog_batch;
@property (atomic, assign) NSInteger adlog_exception_batch;
@property (atomic, assign) NSInteger adlog_debug;

@end

@interface CSJUSettingService (BUUnion_Logic)

@property (atomic, copy, class, readonly) NSString *jsActLogURLString;
+ (NSString *)shouldEvaluateActLogJsWith:(NSString *)adID;

@end
