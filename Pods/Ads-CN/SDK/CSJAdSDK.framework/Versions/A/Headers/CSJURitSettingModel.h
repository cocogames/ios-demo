//
//  CSJURitSettingModel.h
//  CSJAdSDK
//
//  Created by 崔亚楠 on 2018/9/29.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJMaterialMeta+Private.h"
typedef NS_ENUM(NSInteger, BUVideoPrefetchType) {
    BUVideoPrefetchTypeWifi           = 1,    //仅wifi预加载
    BUVideoPrefetchTypeWifiAnd4GAnd5G = 2,    //wifi || 4G || 5G都预加载
    BUVideoPrefetchTypeNone           = 3,    //不预加载
};

typedef NS_ENUM(NSInteger, BUVideoAutoPlayType) {
    BUVideoAutoPlayTypeWifi           = 1,    //仅wifi自动播放
    BUVideoAutoPlayTypeWifiAnd4GAnd5G = 2,    //wifi || 4G || 5G都播放
    BUVideoAutoPlayTypeNone           = 3,    //不自动播放
    BUVideoAutoPlayTypecCustom        = 4,    //开发者配置是否自动播放(取外部配置逻辑,默认自动播放)
    BUVideoAutoPlayTypeWifiAnd5G      = 5,    //wifi || 5G都播放
};

typedef NS_ENUM(NSInteger, BURewardedVoiceControl) {
    BURewardedVoiceControl_mute = 1,    //静音
    BURewardedVoiceControl_unMute = 2  //不静音
};

typedef NS_ENUM(NSInteger, BURewardedShowAlert) {
    BURewardedShowAlert_unShow = 0,    //不展示
    BURewardedShowAlert_show = 1  //展示
};

/// 关于激励视频广告奖励发放的类型定义
typedef NS_ENUM(NSInteger, BURewardAdSendRewardType) {
    BURewardAdSendRewardTypeC2C = 0, //发放奖励时无需询问服务端
    BURewardAdSendRewardTypeS2S = 1 //发放奖励时需询问服务端
};



typedef NS_ENUM(NSInteger, BUSplashLoadType) {
    BUSplashLoadTypeRealTimeAD                = 0, //不使用缓存广告的逻辑,每次load开屏广告时仅请求实时广告
    BUSplashLoadTypeCacheFirstAD              = 1, //若本地有缓存,则优先校验缓存广告,若缓存没有或不可用则用实时广告
    BUSplashLoadTypeConcurrentRealTimeFirstAD = 2, //同步校验,优先使用实时加载广告
    BUSplashLoadTypeConcurrentFastestFirstAD  = 3, //同步校验,优先使用最先返回的广告
};


typedef NS_ENUM(NSInteger, BUSplashTimeOutControlType) {
    BUSplashTimeOutControlType_Default              =       0, // 采用原先的time_out计算方案，即 较长超时-耗时buffer；
    BUSplashTimeOutControlType_Shorter              =       1, // 较短超时时长；
    BUSplashTimeOutControlType_ServerTimeOut        =       2, // 直接使用服务端下发时长（time_out_control）
};


FOUNDATION_EXPORT NSString *CSJNSStringFromBUSplashLoadType(BUSplashLoadType splashLoadType);
FOUNDATION_EXPORT NSString *CSJNSStringFromCSJSplashLoadType(BUSplashLoadType splashLoadType);
FOUNDATION_EXPORT NSString *CSJNSStringFromCSJSplashCacheSort(NSInteger cacheSort);

#define BUAdDefaultSplashBufferTime     (100)

@interface CSJURitSettingModel : NSObject
/// codeId
@property (nonatomic, copy) NSString *codeId;
/// 是否自动播放 默认1
@property (nonatomic, assign) BUVideoAutoPlayType videoAutoPlayType;
/// YES:关闭声音 NO:开启声音 默认静音
@property (nonatomic, assign) BOOL muteSwitch;
/// 原生视频是否预加载 默认1
@property (nonatomic, assign) BUVideoPrefetchType videoPrefetchType;
/// 激励视频是否预加载 默认2
@property (nonatomic, assign) BUVideoPrefetchType rewardVideoPrefetchType;
/// 竖版原生视频是否自动播放 默认2
@property (nonatomic, assign) BUVideoAutoPlayType drawVideoAutoPlayType;
/// 竖版原生视频是否静音 默认有声音
@property (nonatomic, assign) BOOL drawMuteSwitch;
/// 全屏视频跳过前是否显示5，4，3，2，1的倒计时 默认NO
@property (nonatomic, assign) BOOL skipTimeEnable;
/// 全屏视频点击跳过按钮后跳endcard（2）还是直接退出（1） 默认2
@property (nonatomic, assign) BUSkipResult skipResult;
/// 奖励视频播放下载bar跳过以及动画 -1 为无动画
@property (nonatomic, assign) NSInteger rewardbarShowTime;
/// 激励视频是否展示跳过按钮 单位秒 默认-1,不展示
@property (nonatomic, assign) NSInteger rewardedSkipTime;
/// 激励视频、全屏视频是否静音，默认2，不静音
@property (nonatomic, assign) BURewardedVoiceControl voiceControl;
/// 激励视频点击跳过是否展示奖励弹窗，0不展示 1展示,  默认1
@property (nonatomic, assign) BURewardedShowAlert showAlert;
/// 插屏动态布局视频是否静音 默认有声音
@property (nonatomic, assign) BOOL interstitialMuteSwitch;
/// 父模板tpl_ids
//@property (nonatomic, copy) NSArray *parentTplIds;
/// 全屏视频跳过按钮显示时间
@property (nonatomic, assign) NSInteger fullscreen_skipBtnShowTime;
/// 开屏视频是否wifi下预加载 0wifi 1wifi+4G 默认0
@property (nonatomic, assign) BUVideoPrefetchType splash_prefetchType;
/// 开屏卡顿跳过时间 毫秒 默认1500ms
@property (nonatomic, assign) NSInteger splash_stopTime;
/// set the type of reward send
@property (nonatomic, assign) BURewardAdSendRewardType rewardAdSendRewardType;
/// time_out_control 开屏超时时间
@property (nonatomic, assign) double timeOutControl;
/// slotType
@property (nonatomic, assign) NSInteger slotType;
// https://bytedance.feishu.cn/wiki/wikcnO2zt9iz0aqw0HjychvF5rb
// 需求内容2 中的 a需求
@property (nonatomic, assign) BUSplashLoadType splashLoadType;
// 需求内容2 中的 c需求,  单位 ms
@property (nonatomic, assign) NSInteger splashBufferTime;

@property (nonatomic, assign) BUSplashTimeOutControlType time_out_contorl_type;

/// 新插屏广告点击是否自动关闭， true 时点击广告自动关闭插屏，默认false
@property (nonatomic, assign) BOOL autoCloseOnClick;

/// 4300 pl延时关闭
@property (nonatomic, assign) NSInteger nativePlayableDelay;

/// 4400 server bidding 是否开启预请求
@property (nonatomic, assign) BOOL enable_bidding_pre_fetch;

/// 4400 server bidding 是否开启预缓存
@property (nonatomic, assign) BOOL enable_bidding_cache;
/// 4400 server bidding 单位毫秒，表示xx毫秒内客户端生成的token只有一个附带缓存信息，
/// 为0或不下发时不做并发控制
@property (nonatomic, assign) NSInteger bidding_cache_skip_time;

- (instancetype)initWithDictionary:(NSDictionary *)configDic;

@end

#pragma mark - 非中开屏相关字段

@interface CSJURitSettingModel ()

/// 跳过选项出现的时间时长设置
@property (nonatomic, assign) NSTimeInterval splashSkipTime;

/// 图片展示结束时长
@property (nonatomic, assign) NSTimeInterval splashImageCountdownTime;

@end
