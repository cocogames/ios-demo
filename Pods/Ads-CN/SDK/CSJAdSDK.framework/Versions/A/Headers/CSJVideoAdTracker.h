//
//  BUVideoAdReportorTracker.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/1/27.
//

#import <Foundation/Foundation.h>
#import "CSJVideoAdReportor.h"
#import "CSJAdSlot.h"
#import "CSJMaterialMeta+Private.h"

NS_ASSUME_NONNULL_BEGIN

// 从外部获取 tag 值
typedef NSString * _Nullable (^VideoTagBlock)(void);

// 从外部获取当前播放时间
typedef NSUInteger (^VideoPlayTimeBlock) (void);

typedef CSJMaterialMeta * _Nullable (^VideoAdMetaBlock) (void);

@class CSJMaterialMeta;

/// 视频性能追踪，兼容旧版本
@interface CSJVideoAdTracker : NSObject

/// 视频播放类型
@property(nonatomic, assign, readonly) BUPlayerPlayType video_play_type;

/// 视频播放 URL
@property(nonatomic, copy, readonly) NSString *video_play_url;

/// 视频分辨率
@property(nonatomic, copy, readonly) NSString *video_resolution;

/// 视频大小，单位
@property(nonatomic, assign, readonly) NSUInteger video_size;

/// 视频总时长，单位 ms
@property(nonatomic, assign, readonly) NSUInteger video_duration;

@property (nonatomic, assign) NSUInteger holdPlayerCount;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithVideoTagBlock:(VideoTagBlock)tagBlock playTimeBlock:(VideoPlayTimeBlock)timeBlock metaBlock:(VideoAdMetaBlock)metaBlock;

/// 配置上报数据，当播放器初始化之后 & 播放器触发降级之后，视频上报工具内部数据，默认为内部播放器
/// @param decodeMode 当前解码模式
/// @param h265VideoInfo H265 视频数据
/// @param h264VideoInfo H264 视频数据
- (void)configVideoInfoWithDecodeMode:(BUVideoPlayerDecoeMode)decodeMode
                        h265VideoInfo:(nullable CSJVideoInfo *)h265VideoInfo
                        h264VideoInfo:(nullable CSJVideoInfo *)h264VideoInfo;

/// 配置上报数据，当播放器初始化之后 & 播放器触发降级之后，视频上报工具内部数据。
/// @param decodeMode 当前解码模式
/// @param h265VideoInfo H265 视频数据
/// @param h264VideoInfo H264 视频数据
/// @param customPlayer 是否是自定义播放器
- (void)configVideoInfoWithDecodeMode:(BUVideoPlayerDecoeMode)decodeMode
                        h265VideoInfo:(nullable CSJVideoInfo *)h265VideoInfo
                        h264VideoInfo:(nullable CSJVideoInfo *)h264VideoInfo
                         customPlayer:(BOOL)customPlayer;

/// 滑动重置
- (void)reportVideoReset;

#pragma mark - 播放打点

/// 播放
- (void)reportVideoStartPlay;

/// 首帧
- (void)reportVideoFirstRender:(BOOL)autoPlay;

/// 暂停
- (void)reportVideoPause;

/// 继续播放
- (void)reportVideoResume;

/// 重新播放
- (void)reportVideoReplay;

- (void)reportVideoAutoReplay;

/// 播放错误
/// @param error 播放错误
- (void)reportVideoError:(NSError *)error;

#pragma mark - End Card


/// 非正常调用 EndCard
/// @param reason EndCard 原因
/// @param hasPlayed  是有有过播放行为
- (void)reportVideoEndCard:(BUEncardSkipType)reason hasPlayed:(BOOL)hasPlayed;


#pragma mark - 播放结束打点

/// 非正常播放结束上报
/// @param playerBreakType 非正常结束原因
- (void)reportVideoWithPlayerBreakType:(BUPlayerBreakType)playerBreakType;

/// 播放完成
- (void)reportVideoPlayOver;

/// 开始缓冲
- (void)recordBeginBuffer;

/// 结束缓冲
- (void)recordEndBuffer;

@end

NS_ASSUME_NONNULL_END
