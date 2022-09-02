//
//  CSJMaterialMeta+Private.h
//  CSJAdSDK
//
//  Created by carl on 2017/11/26.
//  Copyright © 2017年 bytedance. All rights reserved.
//


#import "CSJAdSDKDefines+Private.h"
#import "CSJMaterialMeta.h"
#import "CSJAppInfo.h"
#import "CSJVideoInfo.h"
#import "CSJTplInfo.h"
#import "CSJPersonalizationPrompts.h"
#import "CSJMiddleTplInfo.h"
#import "CSJPlayableInfo.h"
#import "CSJRenderModel.h"
#import "CSJSKANStoreProductModel.h"
#import "CSJRewardAgainModel.h"
#import "CSJClickActionModel.h"
#import "CSJRewardLiveModel.h"
#import "CSJCloudGameInfo.h"
#import "CSJDirectLandingPageInfo.h"
#import "CSJInteractionMethodParams.h"
#import "CSJPlayableCommonInfo.h"
#import "CSJWCMiniappInfo.h"
#import "CSJLandingPageConfModel.h"
#import "CSJEcomCouponModel.h"

@class CSJURitSettingModel, CSJSkipControlModel;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSInteger, BUAdExtraDataType) {//ad_extra_data上报的字段
    BUAdExtraDataType_none                  = 0,
    BUAdExtraDataType_ritScene              = 1 << 0,//请求场景
    BUAdExtraDataType_videoStartDuration    = 1 << 1,//起播时长，单位毫秒
    BUAdExtraDataType_videoResolution       = 1 << 2,//视频分辨率
    BUAdExtraDataType_videoSize             = 1 << 3,//视频大小
    BUAdExtraDataType_playType              = 1 << 4,//播放类型 0完全预加载 1实时播放 2边缓存边播 3未开始播放
    BUAdExtraDataType_buffersTime           = 1 << 5,//用户体验到的缓冲时长
    BUAdExtraDataType_vbttSikpType          = 1 << 6,//vbtt视频跳过 0缓冲超时 1非缓冲
    BUAdExtraDataType_loadTime              = 1 << 7,//下载时长
    BUAdExtraDataType_errorCode             = 1 << 8,//错误码
    BUAdExtraDataType_errorMessage          = 1 << 9,//错误信息
    BUAdExtraDataType_skipReason            = 1 << 10//跳过原因
};

typedef NS_ENUM(NSInteger, BUEncardSkipType) {
    BUEncardSkipType_bufferTimeout = 0,         // 播放缓冲累计超时
    BUEncardSkipType_firstRenderTimeout = 1,    // 首帧缓冲超时
    BUEncardSkipType_player = 2,                // 播放器报错
    BUEncardSkipType_vendor = 3,                // 厂商报错
    BUEncardSkipType_path = 4,                  // 资源文件、路径出错
    BUEncardSkipType_playerNoResponse = 5,      //到达 vbtt 但是播放器无响应
    BUEncardSkipType_other = -1,                // 其他原因
};

typedef NS_ENUM(NSUInteger, BUPlayerBreakType) {
    BUPlayerBreakType_PlayerError = 0,           // 播放器发生错误
    BUPlayerBreakType_PlayerBufferTimeout = 1,  // 播放器缓冲超时（包括首帧超时）
    BUPlayerBreakType_CloseApplication = 2,      // App 关闭
    BUPlayerBreakType_CloseAd = 3,               // 广告页面被关闭
    BUPlayerBreakType_ClickSkip = 4,             // 用户点击了跳过
    BUPlayerBreakType_SlidAway = 5,              // 用户滑走
    BUPlayerBreakType_URLEmpty = 6,              // 播放链接为空
};


typedef NS_ENUM(NSInteger, BURewardVideoPlayBarStyle) {
    BURewardVideoPlayBarStyle_normal                          = 0,  //当前线上下载bar样式
    BURewardVideoPlayBarStyle_verticalShow_horizontalVideo    = 1, //优化竖版流量+横版素材情况下的样式
    BURewardVideoPlayBarStyle_hiddenDownloadBar_fullscreen    = 2, //全屏视频，无下载bar样式
    BURewardVideoPlayBarStyle_longtitle_international         = 3, //国际版appname加长，下载button变短
};

typedef NS_ENUM(NSInteger, BUVideoAdaptationType) {
    BUVideoAdaptationTypeNormal        =  0,     //激励视频和全屏视频不进行适配
    BUVideoAdaptationTypeFullScreen    =  1,     //激励视频和全屏视频进行适配
    BUVideoAdaptationTypeNoUsed        =  2,
    BUVideoAdaptationTypeRemoveBar     =  3      //激励视频和全屏视频移除上下bar进行适配
};

typedef NS_ENUM(NSInteger, BURenderControl) {
    BURenderControlNone         =           0,  // 未知
    BURenderControlNative       =           1,  // 自渲染
    BURenderControlTemplate     =           2,  // 动态布局
};


typedef NS_ENUM(NSUInteger, BULandingPageTypeStyle) {
    BULandingPageTypeStyleNormal      = 0,        // 非中间页
    BULandingPageTypeStyleImmersive    = 1,        // 普通中间页，对应Feed流竖视频
    BULandingPageTypeStyleRecommend = 2,        // 相关推荐页，对应下载类广告
};

typedef NS_ENUM(NSUInteger, BUReleateRecommendParentType) {
    BUReleateRecommendParentType_reward      = 2,        // 激励
    BUReleateRecommendParentType_middle      = 3,        // 全量推广相关推荐，非激励
};

typedef NS_ENUM(NSUInteger, BUPlayerPlayType) {
    BUPlayerPlayType_LocalFile = 1, // 本地文件播放
    BUPlayerPlayType_Cache = 2,     // 边播边缓存
    BUPlayerPlayType_Online = 3,    // 播放器直接播放
};

// https://bytedance.feishu.cn/docx/doxcnN629BCcuoshAIF6VJLmCNf
// 文档中的  客户端处理规则
typedef NS_ENUM(NSUInteger, BUAdDynamicJoinType) {
    BUAdDynamicJoinType_None = 0, // 默认值，没有任何策略
    BUAdDynamicJoinType_VideoMax60 = 2,     // 视频播放至60s时停止视频并给到完播回调
    BUAdDynamicJoinType_BlackMode = 3,    // 客户端通过黑边的方式实时进行视频横竖转换
    BUAdDynamicJoinType_GasoiMode = 4, // 客户端通过高斯模糊的方式实时进行视频横竖转换
    BUAdDynamicJoinType_Carousel = 5,    // 客户端实时进行图片轮播  暂时废弃
};


    
typedef NS_ENUM(NSUInteger, BUOrientation) {
    BUOrientationPortrait = 1,    // 广告竖屏样式
    BUOrientationLandscape = 2,   // 广告横屏样式
};

/// 纯playable奖励发放类型
typedef NS_ENUM(NSInteger, BUPurePlayableRewardSendType) {
    BUPurePlayableRewardSendTypeNativeH5   = 0,  // need h5 and playable_close_time meet condition
    BUPurePlayableRewardSendTypeNative     = 1,  // original send type
};

typedef NS_ENUM(NSUInteger, BUVideoWebPageType) {
    BUVideoWebPageTypeEndcard                = 0,        // endcard
    BUVideoWebPageTypeLandingPage            = 1,        // playable 落地页
    BUVideoWebPageTypeRewardPlayable         = 2,        // 激励全屏playable页
    BUVideoWebPageTypeNone                   = 3,        // 普通落地页
};

/// 4100, playable、cloudgame等解耦，但逻辑高度复用，统一相关的类型判断
typedef NS_ENUM(NSInteger, BUPlayfulPageType) {
    BUPlayfulPageType_None, //不是相关类型
    BUPlayfulPageType_VideoPlayable, //激励全屏playable
    BUPlayfulPageType_PurePlayable, //纯playable
    BUPlayfulPageType_PlayableLandingPage, //playable落地页
//    BUPlayfulPageType_CloudGame, //云游戏
};

typedef NS_ENUM(NSInteger, BURewardBrowseType) {
    BURewardBrowseTypeNormal            = 0, // 非激励浏览
    BURewardBrowseTypeRewardBrowse      = 1, // 激励浏览落地页 （目前暂不支持）
    BURewardBrowseTypeRewardAggregation = 2, // 激励浏览聚合页（废弃，目前不支持）
    BURewardBrowseTypeRewardEcommerce   = 3  // 激励浏览电商聚合页
};

typedef NS_ENUM(NSInteger, BUPlayableLandingConvertType) {
    BUPlayableLandingConvertTypeBoth = 0,   // 播放后自动进入pl落地页+点击进入pl落地页
    BUPlayableLandingConvertTypeAuto,       // 播放后自动进入pl落地页
    BUPlayableLandingConvertTypeClick       // 点击进入pl落地页
};

// 4250 链路优选需求 (仅国外, 拼接页面包含4种样式  1. 上部分视频下部分webview 2.上部分视频下部appstore 3.上部分图片下部分webview 4.上部分图片下部分appstore)
typedef NS_ENUM(NSInteger, BUInteractionMethod) {
    BUInteractionMethodNormal_native = 0, // native/banner:兜底逻辑（4250发布前的线上逻辑）
    BUInteractionMethodADdetail_createClickArea_native = 1, // native/banner:点击按钮打开落地页/应用商店，点击素材等区域打开拼接页
    BUInteractionMethodADdetail_allClickArea_native = 2, // native/banner:点击所有可点区域均打开拼接页
    BUInteractionMethodLandingPage_allClickArea_native = 3, // native/banner:点击所有可点区域均直接打开落地页/应用商店
    BUInteractionMethodPlayable_native = 4, // native/banner: 视频/图片点击打开playable，playable点击跳转落地页/应用商店
    BUInteractionMethodLandingPage_reward = 5, // 激励/全屏: 直接展示落地页，没有视频,不是拼接页
    BUInteractionMethodADdetail_reward = 6, // 激励/全屏: 拼接页。上方视频/图片下方落地页/应用商店
    BUInteractionMethodNormal_endcard_landingpage_reward = 7, // 激励/全屏: video/image+endcard+落地页/应用商店
    BUInteractionMethodNormal_landingpage_reward = 8, // 激励/全屏: video/image+落地页
    BUInteractionMethodNormal_Playable_landingpage_reward = 9, // 激励/全屏: video/image+playable+落地页/应用商店
    BUInteractionMethodNormal_PurePlayable_reward = 12, //  激励/全屏: playable+落地页/应用商店
};

typedef NS_ENUM(NSInteger, BUSkipResult) {
    /// 直接退出
    BUSkipResult_back = 1,
    /// 展示endCard
    BUSkipResult_endCard = 2,
    /// 主动点击跳过按钮时不展示endcard, 不点击跳过按钮时视频播放结束时展示endcard
    BUSkipResult_tap = 3,
    /// 停留在最后一帧，点击跳过关闭广告
    BUSkipResult_Standby = 4,
    /// 停留在最后一帧，展示封面，点击跳过关闭广告
    BUSkipResult_Cover = 5,
    // 不展示endcard，循环播放视频
    BUSkipResult_LoopPlay = 6
};

/// 4700 自渲染信息流支持摇一摇
typedef NS_ENUM(NSInteger, CSJClickTriggerType) {
    /// 点击触发转化
    CSJClickTriggerType_Click = 0,
    /// 摇一摇触发转化
    CSJClickTriggerType_Shake = 1
};

FOUNDATION_EXPORT NSString *CSJNSStringFromRenderControl(BURenderControl renderControl);
FOUNDATION_EXPORT NSString *CSJNSStringFromBUFeedADMode(BUFeedADMode feedADMode);

typedef void(^FinishVideoViewBlcok)(CGFloat playTime);

@interface CSJMaterialMeta () <CSJAd,CSJActionDeepLinkModel,CSJActionWebModel,CSJActionPhoneModel,NSCoding>

@property (nonatomic, assign) BOOL is_html;

@property (nonatomic, copy) NSString *dsp_html;

// 展现监测URL的列表
@property (nonatomic, copy) NSArray<NSString *> *show_urls;

// 点击监测的URL列表
@property (nonatomic, copy) NSArray<NSString *> *click_urls;

// 区分明暗投，0为暗投，否则为明投
@property (nonatomic, assign) NSInteger unionSpecial;

// 激励视频区分 endcard是playable类型还是普通类型
@property (nonatomic, assign) BOOL isPlayable;

/// 开屏广告展示时间，其他广告忽略
@property (nonatomic, assign) NSInteger countDown;

/// 广告过期时间
@property (nonatomic, assign) NSTimeInterval expireTimestamp;

/// 广告存储时当前时间
@property (nonatomic, assign) NSInteger saveTimestamp;

/// 激励视频广告缓存时间，其他广告忽略
//@property (nonatomic, assign) NSTimeInterval preloaderTimestamp;

/// 应用下载类广告信息
@property (nonatomic, strong) CSJAppInfo *appInfo;

/// 服务端云控 h265 = 1，h264 = 0 视频使用相应的 CSJVideoInfo 结构体
@property (nonatomic, assign) BUVideoEncodeType video_encode_type;

/// 当前使用的广告信息
@property (nonatomic, strong, readonly) CSJVideoInfo *videoInfo;

/// 视频广告信息
@property (nonatomic, strong) CSJVideoInfo *h264VideoInfo;

/// H265 视频广告信息
@property (nonatomic, strong) CSJVideoInfo *h265VideoInfo;

/// 视频播放完成回调
@property (atomic, copy) FinishVideoViewBlcok finishBlock;
/// 激励、全屏视频是否展示负反馈按钮
@property (nonatomic, assign) BOOL showDislike;

/// 奖励视频播放下载bar跳过实验v1990, 因为为int型,无法判断接口是否有返回,所以字段改为-200为接口无返回
@property (nonatomic, assign) NSInteger playbarShowtime;

/// 动态布局延迟渲染，单位毫秒
@property (nonatomic, assign) NSInteger render_delay_time;

/// 动态布局参数
@property (nonatomic, strong) CSJTplInfo *tplInfo;

/// 3700 为物料增加creativeExtraJson字段【Sdk 3700支持pangle 自建站需求】
@property (nonatomic, copy) NSString *creative_extra;

/// 中间动态布局参数
@property (nonatomic, strong) CSJMiddleTplInfo *middleTplInfo;

/// 动态布局开屏兜底图片
@property (nonatomic, strong) CSJImage *coverImage;

/// 激励视频点击事件
@property (nonatomic, strong) NSDictionary *clickAreaDic;

/// 是否展示广告标识 默认1 展示
@property (nonatomic, assign) NSInteger showAdLogo;

/// 可设置整数值，表示不同样式。
@property (nonatomic, assign) BURewardVideoPlayBarStyle playBarStyle;

#pragma mark - 视频播放

/// 视频播放 Session ID
//@property (nonatomic, copy) NSString *video_session_id;

/// 视频加载时间戳
@property (nonatomic, assign) NSTimeInterval startLoad_interval;

/// 视频起播时间戳
@property (nonatomic, assign) NSTimeInterval startPlay_interval;

/// 视频播放类型  取值范围1～3，1本地文件播放，2 变播变缓存 3 使用兜底策略直接播放URL
//@property (nonatomic, assign) BUPlayerPlayType video_play_type;

#pragma mark - 视频预加载
/// 视频开始下载时间戳
@property (nonatomic, assign) NSTimeInterval startDownload_interval;

/// 视频预加载大小
@property (nonatomic, assign) NSInteger video_prefetch_size;

/// 视频加载是否是本地文件
@property (nonatomic, assign) BOOL video_local_prefetch;

/// 视频加载失败错误码
@property (nonatomic, assign) NSInteger video_prefetch_error_code;

/// 视频预加载客户端错误信息
@property (nonatomic, copy) NSString *video_prefetch_error_msg;

/// 视频预加载服务端 response 信息
@property (nonatomic, copy) NSString *video_prefetch_server_msg;


/// appstore 页面跳转逻辑，默认0，下发appid，预加载 > 实时加载，!appid && downloadURL,外部跳转; 1,外部跳转；2,预加载 > 外部跳转 > 实时加载
@property (nonatomic, assign) NSInteger appstoreJumpType;

/// int，1为纯playable，0为视频+playable。默认为0。
@property (nonatomic, assign) NSInteger playableType;

/// 实验 : 0保持原逻辑 1当信息流视频是自动播放的视频时，用户点击视频区域，等同用户点击下载按钮处理。v2600
@property (nonatomic, assign) NSInteger feedVideoOpentype;

/// 为物料增加playable_style字段
@property (nonatomic, copy) NSString *playableStyle;

/// video adaption on fullscreen and rewarded video
@property (nonatomic,assign) BUVideoAdaptationType videoAdaptation;

/// playable 的测试数据
@property (nonatomic, assign) BOOL isPlayableTestData;

/// 服务端额外参数,一般需要透传到下次请求中
@property (nonatomic, copy) NSDictionary *session_params;

/// 保存原始json值，鲁班聚合页JSBridge
@property (nonatomic, copy) NSDictionary *materialDictionary;

/// int，1为图片优先 2视频优先 3视频优先且在线播 (这个字段含义混合,产品要先上实验,建议之后分两个字段)
@property (nonatomic, assign) NSInteger cacheSort;


/// 3200 加入落地页预加载逻辑. 有改字段,在 show 时候进行预加载
@property (nonatomic, copy) NSString *geckoId;

/// ext中获取adSlotType
@property (nonatomic, assign) NSInteger adSlotType;

/// ext中获取renderType 1动态布局 2非动态布局
@property (nonatomic, assign) NSInteger renderType;


/// 使用 1自渲染 2动态布局  方式去渲染广告， 目前在开屏、激励、全屏广告有效
@property (nonatomic, assign) BURenderControl renderControl;


// 落地页 Gecko 预加载埋点使用
// 总资源请求次数（落地页打开到关闭这段时间内）
@property (nonatomic, assign) NSInteger all_times;
// 命中本地Gecko缓存次数（落地页打开到关闭这段时间内）
@property (nonatomic, assign) NSInteger hit_times;

// 记录是否用户使用了自定义播放器，不需encode保存
@property (nonatomic, assign) BOOL userDidCustomVideoPlayer;

/// reward ads reward name.
@property (nonatomic, copy) NSString *rewardName;///3300 add

/// reward ads reward anount.
@property (nonatomic, assign) NSInteger rewardAmount;///3300 add

@property (nonatomic, assign) NSInteger landingScrollPercentage; // 落地页锚点条件：landingScrollPercentage=-1(不下发)原始逻辑；landingScrollPercentage=0全场景锚点；landingScrollPercentage>0信息流视频自动播放进度>landingScrollPercentage进行落地页锚点锚点  add in 3300 by chaors

// 3300 落地页双开优化
@property (nonatomic, assign) NSInteger if_both_open;
@property (nonatomic, assign) NSInteger if_double_deeplink;
//弹框提醒打开 adApp 会再次走 handleActionWithModel:context: 方法.
//havePushTargetPage 标记,防止再一次push落地页
@property (nonatomic, assign) BOOL havePushTargetPage;

/// 3400 落地页类型
@property (nonatomic, assign) BULandingPageTypeStyle landingPageStyle;
/// 中间页下载是否完成
@property (nonatomic, assign) BOOL bu_middleTemplateComplete;
/// 中间页模板数据
@property (nonatomic, copy) NSString *bu_middleTemplateData;
///3300插入需求
///0-100，目前只有0、100，100添加点击
@property (nonatomic, assign) NSInteger cover_click_area;
///3500 需求 全场景支持 playable 落地页
@property (nonatomic, strong) CSJPlayableInfo *playableInfo;
@property (nonatomic, strong) CSJCloudGameInfo *cloudGameInfo;
@property (nonatomic, strong) CSJDirectLandingPageInfo *directLandingPageInfo;
/// 3550 全屏/激励广告横竖屏方向,仅对全屏、激励有效
@property (nonatomic, assign) BUOrientation orientation;

/// 35xx 全屏宽高比，对应新插屏广告，下发float类型，端上取小数点后三位
///
/// 1. >0 对插屏尺寸生效， 2. <=0 表示全屏类型，广告大小为屏幕大小
@property (nonatomic, assign) CGFloat fullScreenAspectRatio;
/// 新插屏两边的间距
@property (nonatomic, assign) CGFloat fullScreenAspectMargin;
/// 新插屏原生广告圆角
@property (nonatomic, assign) CGFloat fullScreenCornerRadius;
///3500 模板广告 webView 展示 playable 素材
@property (nonatomic, copy) NSDictionary *extension;
/// 这个一定会有值，如果服务端没有下发的话会使用默认值
@property (nonatomic, strong) CSJRenderModel *render;
/// 这个一定会有值，如果服务端没有下发的话会使用默认值
@property (nonatomic, strong) CSJLandingPageConfModel *landingPageConf;

/// 服务端：将request_id、Adslot_id、ad_id、creative_id信息生成加密字符串，随广告物料下发
@property (nonatomic, copy) NSString *adInfo;

/// 增加字段控制「点击dislike后是否自动关闭广告」
@property (nonatomic, assign) BOOL closeOnDislike;

/// 3800 激励视频 再看一个
@property (nonatomic, strong) CSJRewardAgainModel *rewardAgainModel;
/// 用来标记 模板/普通 激励视频是否已发放奖励
@property (nonatomic, assign) BOOL hasSendReward;
@property (nonatomic, strong) NSMutableDictionary<NSNumber *, NSNumber *> *hasSendRewardDict;
/// 只做原始text判空使用，正常使用请用buttonText
@property (nonatomic, copy) NSString *originButtonText;
/// 代表纯playable倒计时开始时间，单位s，奖励视频、全屏视频默认值20
@property (nonatomic, assign) NSInteger playableDurationTime;

/// 激励视频endcard关闭按钮延时出现 单位毫秒 默认-1 不延迟出现
@property (nonatomic, assign) NSInteger rewardedEndCardCloseTime;

/// 激励视频endcard playable关闭按钮延时出现 单位毫秒 默认-1 不延迟出现
@property (nonatomic, assign) NSInteger rewardedPlayableCloseTime;

/// 3900 控制点击交互操作
@property (nonatomic, strong) CSJClickActionModel *clickActionModel;

/// 是否禁止用户在未有任何操作时deeplink自动跳转行为
@property (nonatomic, assign) BOOL blockAutoOpen;

///endcard_skoverlay endcard是否展示skoverlay
@property (nonatomic, strong) NSNumber *endcard_skoverlay;

/// 进入playable是否展示skoverlay
@property (nonatomic, assign) BOOL playable_skoverlay;

@property (nonatomic, assign) BUAdDynamicJoinType dynamic_join_type;


/// playable可关闭时间
@property (nonatomic, assign) NSInteger playableCloseTime;
/// 激励视频观看到某个程度掉起服务端回调1-100 默认100
@property (nonatomic, assign) NSInteger watchPercent;
/// pure playable ad reward send type
@property (nonatomic, assign) BUPurePlayableRewardSendType playableRewardType;
/// reward_browse_type 激励浏览判断标志 0非激励浏览 1激励浏览-落地页类型（暂不支持） 2激励浏览-聚合页类型（废弃） 3激励浏览-电商聚合页
@property (nonatomic, assign) BURewardBrowseType rewardBrowseType;
/// 前端倒计时字段
@property (nonatomic, assign) NSInteger rewardBrowseWebviewDurationTime;
/// 是否是shake触发
@property (nonatomic, assign) BOOL isShakeAction;
/// 反馈面板输入框的Input Accessory View是否可用
@property (nonatomic, assign) BOOL validDislikeInputAccessoryView;

// 用于海外链路优选类型的真实ID
@property (nonatomic, assign) BUInteractionMethod interactionMethod;
// getads中的优选ID 只用于埋点(get ads中的字段)
@property (nonatomic, assign) BUInteractionMethod interactionMethod_ads;
// getads中的优选ID 只用于埋点(修改get ads字段为产品想要的链路字段)
@property (nonatomic, assign) BUInteractionMethod interactionMethod_real;
// 用于海外链路优选的字段方法 客户端判断走的真实链路字段，不用于埋点用于真实链路判断
@property (nonatomic, strong) CSJInteractionMethodParams *interactionMethodParams;

// 新插屏播放是否自动进入pl落地页
@property (nonatomic, assign) BUPlayableLandingConvertType convertType;
/// 是否支持前置入口playable/云游戏
@property (nonatomic, assign) BOOL hasPrePlayable;

/// 4300 迁移字段 全屏视频点击跳过按钮后跳endcard（2）还是直接退出（1） 默认2 
@property (nonatomic, assign) BUSkipResult skipResult;

/// App下载类 下载总数
@property (nonatomic, assign) NSInteger downloadNum;

/// playable通用配置信息
@property (nonatomic, strong) CSJPlayableCommonInfo *playableCommonInfo;

/// 建站服务提供的小程序跳转相关信息
@property (nonatomic, strong) CSJWCMiniappInfo *wcMiniappInfo;

/// 4700 自渲染信息流支持摇一摇
@property (nonatomic, assign) CSJClickTriggerType clickTriggerType;
/// 电商券信息
@property (nonatomic, strong) CSJEcomCouponModel *ecomCouponModel;

/// 判断是否是视频的imageMode
- (BOOL)isVideoImageMode;

/// 是否是品牌视频
- (BOOL)isBrandVideoAd;

/*
 是否为互动类型广告
 https://feishu.processon.com/feishu/view/link/6145af20e4b04194b5f56eda
 */
- (BOOL)isSupportPlayful;
- (BUPlayfulPageType)playfulPageType;
- (BOOL)isPurePlayable;
- (BOOL)isPlayableLandingPage;
- (BOOL)isVideoPlayable;
// 是否是动态布局playable
- (BOOL)isExpressPlayable;

/// 是否展示本地loading 对应 if_playable_loading_show == 0
- (BOOL)isNativeShowLoading;

// 是否需要上报 dynamic_show_type字段
- (BOOL)needReportDynamicShowType;

// 当为0的时候，产品默认定义为4
- (CGFloat)starCount;

/*
if_both_open = 0 非双开
- landingPageStyle == 0 进入落地页
- landingPageStyle == 1 落地页使用中间页
- landingPageStyle == 2 落地页使用相关推荐页

if_both_open = 1
- landingPageStyle == 0 落地页使用target_url
- landingPageStyle == 1 落地页使用中间页
- landingPageStyle == 2 落地页使用相关推荐页
*/
- (BOOL)isBothOpen;
- (BOOL)isDoubleDeeplink;

/// 沉浸式中间页
- (BOOL)isImmersiveLandingPage;

/// 相关推荐页
- (BOOL)isRelatedRecommendation;

/// 中间页是否准备就绪
- (BOOL)validMiddleTemplate;

/// 是否可以发起相关推荐页请求，非激励广告
- (BOOL)validRelateMaterials;

// 是否使用动态布局来渲染
- (BOOL)needUseTemplateToRender;
// 是否需要中间页进行模板渲染
- (BOOL)needUseMiddleTemplateToRender;
// 是否是模板渲染或者中间页进行模板渲染
- (BOOL)needUseTmeplateOrMiddleTemplateToRender;

@property (nonatomic, assign) NSInteger if_send_click;

// 下发的skAdnetwork的相关信息
@property (nonatomic, strong) CSJSKANStoreProductModel *skan_product_item;
// 下发的skAdnetwork的相关信息
@property (nonatomic, strong) CSJSKANADImpressionObject *skan_Impression_Objct;




///4000激励直播广告
@property (nonatomic, strong) CSJRewardLiveModel *rewardLiveModel;

/// 摇一摇触发阈值
@property (nonatomic, assign) float shakeValue;
/// 0为默认值，即按照原方案执行开屏摇一摇阈值触发方案，1为调整值，按照新的方案执行开屏摇一摇触发方案
@property (nonatomic, assign) NSInteger calculationMethod;
/// 扭一扭触发阈值
@property (nonatomic, assign) NSInteger rotationAngle;

/// 跳过按钮位置控制模型
@property (nonatomic, strong) CSJSkipControlModel *skipControlModel;

/// 开屏 show 轮询的间隔时长
@property (nonatomic, assign) NSTimeInterval showPollTime;
/// 4400 serverbidding 预缓存 物料缓存时间ms
@property (nonatomic, assign) NSInteger cache_time;
/// 4400 serverbidding 预缓存 price
@property (nonatomic, copy) NSString *price;
/// 4400 serverbidding 预缓存 缓存广告其他信息，填入缓存广告请求里
@property (nonatomic, copy) NSString *cache_ext;
/// 4400 serverbidding 新增物料唯一标识key
@property (nonatomic, copy) NSString *material_key;


// 信息流播放结束页样式 1:使用新样式
@property (nonatomic, assign) NSInteger feedVideoFinishType;

- (NSString *)AdSource;

// 动态布局需要原始字段
- (NSString *)nativeExpress_AdTitle;
- (NSString *)nativeExpress_AdDescription;

- (void)reportClickUrls;

- (NSString *)getTrackTag;

// 修正renderControll字段，有可能服务端没有下发相关的字段，导致渲染逻辑失败了
- (void)correctRenderControl:(BURenderControl)renderControl;

- (NSDictionary *)extraDataDictWithExtraDataType:(BUAdExtraDataType)extraDataType;

- (NSString *)ritInExtInfo;
- (CSJURitSettingModel *)ritSettingModelInExtInfo;


// 如果没有找到，会返回nil
- (CSJImage *)imageModeWithURLString:(NSString *)urlString;


- (BOOL)isBandingHtmlBannerStyle;
/// size_ratio_style == 100,全屏比例
- (BOOL)isFullSizeRatioStyle;
/// 新插屏样式
- (BOOL)isInterstitialStyle;
/// 全屏,激励是否是竖屏
- (BOOL)isRewardFullScreenPortrait;
/// 全屏,激励是否是横屏
- (BOOL)isRewardFullScreenLandscape;
/// 插屏比例的是否在点击是dimiss
- (BOOL)shouldInterstitialDismiss;

/// 竖屏 插屏合并全屏广告，插屏比例广告大小计算
/// @param validSafeInsets 是否考虑安全区域
- (CGSize)fullScreenAdSizeValidSafeInsets:(BOOL)validSafeInsets;

// 全屏,激励视频 播放结束后是否展示跳过
- (BOOL)showSkipWhenPlayEnd;

/// 是否是激励电商聚合页 rewardBrowseType == 2 || rewardBrowseType == 3
- (BOOL)isRewardEcommerce;

/// 是否为云游戏
- (BOOL)isCloudGame;

/// 只允许点击实时打开互动页(不允许预加载，目前未前置入口云游戏场景)
- (BOOL)restrictJITEnterPlayful;

/// 是否为激励或者全屏slot类型
- (BOOL)isVideoSlot;

/// BUInteractionMethodADdetail_createClickArea_native是否有效
- (BOOL)validNativeCreateClickArea;
/// BUInteractionMethodADdetail_allClickArea_native是否有效
- (BOOL)validNativeAllClickArea;
/// BUInteractionMethodLandingPage_allClickArea_native是否有效
- (BOOL)validLandingPageNativeAllClickArea;

/// 4300 playable是否可以双开
- (BOOL)validPlayWithDownload;
/// 4300 返回物料里所有图片(icon.url, image, video.cover_url)
- (NSArray<CSJImage *> *)adAllImages;

/// --- 4400 进阶奖励 ---
/// 配置信息
@property (nonatomic, copy) NSDictionary *rewardAdvancedConfig;
/// 指定类型进阶奖励是否有效 (CN功能)
- (BOOL)enableAdvancedReward:(BURewardType)type;
/// 指定类型进阶奖励配置信息 (CN功能)
- (nullable NSDictionary*)advancedRewardConfig:(BURewardType)type;
/// 获取播完进阶奖励视频时长下限
- (NSInteger)getVideoCompleteRewardMinDuration;
/// ------

/// 4700 自渲染是否支持摇一摇
- (BOOL)validShakeTrigger;

// 直播电商
@property (nonatomic, assign) NSInteger liveInteractionType;
@property (nonatomic, copy) NSString *liveRoomId;
@property (nonatomic, copy) NSString *ecomLiveParams;

// 直播广告是否支持直播自定义处理
- (BOOL)liveAdSupportCustomAction;

@end

NS_ASSUME_NONNULL_END
