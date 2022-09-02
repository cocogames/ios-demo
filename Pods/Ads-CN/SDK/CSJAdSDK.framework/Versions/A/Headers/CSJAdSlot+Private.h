//
//  CSJAdSlot+Private.h
//  CSJAdSDK
//
//  Created by bytedance_yuanhuan on 2018/9/3.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import "CSJAdSlot.h"
#import "CSJMaterialMeta.h"
#import "CSJAdBannerSlot.h"

typedef NS_ENUM(NSInteger, BUAdSlotRenderType) {
    BUAdSlotRenderType_native = 0,    //原生渲染方式
    BUAdSlotRenderType_template = 1,  //动态布局渲染方式
};

typedef NS_ENUM(NSInteger, BUAdSlotRewardAdType) {
    BUAdSlotRewardAdType_normal = 0,    //激励视频广告
    BUAdSlotRewardAdType_first = 1,  //激励视频一请广告
    BUAdSlotRewardAdType_second = 2,  //激励视频二请广告  注: 二请的各种预加载逻辑和 普通 是完全一致的
};


FOUNDATION_EXPORT NSString *CSJNSStringFromBUAdSlotRenderType(BUAdSlotRenderType slotRenderType);

FOUNDATION_EXPORT NSString *CSJNSStringFromBUAdSlotAdType(BUAdSlotAdType slotAdType);

#define BUAdLoadTypeSDKAuto 2  // 表示sdk自动发起的预加载请求

FOUNDATION_EXPORT NSString *CSJNSStringLogFromBU_SDImageCacheType(BU_SDImageCacheType cacheType);



@interface CSJAdSlot ()
/** 广告数量，AdCount默认是1
 AdCount=1广告适用于banner、开屏、插屏、激励视频、全屏视屏、单条原生广告,在BUNativeAd中使用
 AdCount大于1主要适用于feed流广告，在BUNativeAdsManager初始化中使用
 */
@property (nonatomic, assign) NSInteger AdCount;

@property (nonatomic, copy) NSString *ritScene;

@property (nonatomic, assign) BUAdSlotRenderType renderType;

@property (nonatomic, copy) NSArray *parentTplIds;//当前rit的父模板信息
/// 视图的 size
@property (nonatomic, assign) CGSize viewSize;

/// 开屏广告上报用，开发者在客户端配置的超时时长，单位 ms
@property (nonatomic, assign) NSInteger splashPublisherTimeoutControl;
/// 开屏广告上报用，服务端配置的开屏超时时长，settings下发，单位 ms
@property (nonatomic, assign) NSInteger splashTimeOutControl;
/// 开屏广告上报用，最终判定的超时时长，实际执行的超时时长，单位 ms
@property (nonatomic, assign) NSInteger splashTimeOut;
// optional. 监控banner轮播信息的model
@property (nonatomic, strong) CSJAdBannerSlot *adBannerSlot;
// 3800 激励视频二请广告携带的参数
@property (nonatomic, copy) NSString *preSessions;
@property (nonatomic, copy) NSString *playAgainRit;
// 3800 再看一个 技术方案 https://bytedance.feishu.cn/docs/doccnfmzD06q6HL9ZB2P8TzKqJh
// 注:第一个物料回来之后,这个参数才有值. 不影响 3800 当前缓存逻辑
@property (nonatomic, assign) BUAdSlotRewardAdType rewardAdType;//初始化赋值.业务过程中不要改动
@property (nonatomic, assign) BOOL needPreloadNormalReward;//一请广告强退,需要预加载正常广告
// 是否请求失败了
@property (nonatomic, assign) BOOL requestFailed;
/**materialMeta 是否来自预加载*/
@property (nonatomic, assign) BOOL materialMetaFromPreload;
/**materialMeta 的过期时间戳*/
@property (nonatomic, assign) NSTimeInterval expireTimestamp;


#pragma mark - Internal & Private
- (NSString *)trackTag;
- (NSString *)trackTagWithInteractionType:(BUInteractionType)interactionType ignoreLandscape:(BOOL)ignoreLandscape;
- (BOOL)isSplashAd;

- (BOOL)isBannerAd;
- (BOOL)isInterstitialAd;
- (BOOL)isFeedAd;
// sdk_important: adSlot是否是自渲染的Feed广告, 不是指物料是否是自渲染，模板渲染
- (BOOL)isNativeFeedAd;

// adSlot是否是模板的Feed广告
- (BOOL)isExpressFeedAd;

// sdk_important: adSlot是否是自渲染的Banner和Interstitial广告, 不是指物料是否是自渲染，模板渲染
- (BOOL)isNativeBannerOrInterstitialAd;
- (BOOL)isRewardedAd;
- (BOOL)isFullscreenAd;
- (BOOL)isRewardedOrFullscreenAd;

@end
