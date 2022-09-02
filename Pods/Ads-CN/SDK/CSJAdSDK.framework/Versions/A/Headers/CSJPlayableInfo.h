//
//  CSJPlayableInfo.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/12/29.
//

#import <Foundation/Foundation.h>
#import "CSJVideoInfo.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BUPlayableLandingOrientation) {//物料配置方向
    BUPlayableLandingOrientationAll          = 0,         //横竖都可
    BUPlayableLandingOrientationPortrait     = 1,         //竖屏
    BUPlayableLandingOrientationLandscape    = 2,         //横屏
};


@interface CSJPlayableInfo : NSObject <NSCoding>

@property (nonatomic, copy) NSString *playable_url;

// playable zip下载地址
@property (nonatomic, copy) NSString *playableZipUrl;


@property (nonatomic, assign) BUPlayableLandingOrientation playableOrientation;
/// playable落地页关闭时是否自动跳转落地页 0 ： 关闭时不自动转化 1  ：若未转化过，关闭时自动转化
@property (nonatomic, assign) NSInteger playable_auto_convert;

/// 是否启用playable兜底页策略 0不起用  1启用
@property (nonatomic, assign) NSInteger playable_backup_enable;

/// webview加载超时时间 默认10 单位s
@property (nonatomic, assign) NSInteger playable_webview_timeout;

/// jssdk加载超时时间 默认10 单位s
@property (nonatomic, assign) NSInteger playable_js_timeout;

/// 原始url的备份
@property (nonatomic, copy) NSString *originalPlayableUrl;

/// 默认为false，不生效前端控制逻辑，点击直接进pl落地页，true->根据前端下发的openPlayableLandingPage是否为true来判断
@property (nonatomic, assign) BOOL allowOpenPlayableLandingPage;

/// 4300 playable是否要双开
/// 4300 is_play_with_download：0-只打开pl不下载；1-下载&打开pl；
/// 默认0，异常值走默认
@property (nonatomic, assign) NSInteger isPlayWithDownload;

/// 启用预渲染
@property (nonatomic, assign) BOOL enablePreRender;

// 是否边看边玩
@property (nonatomic, assign) BOOL is_play_with_watching;

// playable_vid 视频id
@property (nonatomic, copy) NSString *playable_vid;

@property (nonatomic, strong) CSJVideoInfo *videoInfo;

- (instancetype)initWithDictionary:(NSDictionary *)dict
                             error:(NSError *__autoreleasing *)error;

- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
