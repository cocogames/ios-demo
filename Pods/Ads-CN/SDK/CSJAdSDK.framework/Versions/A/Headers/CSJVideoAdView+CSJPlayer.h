//
//  BUVideoAdView+Private.h
//  CSJAdSDK
//
//  Created by gdp on 2017/12/26.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import "CSJVideoAdView.h"
#import "CSJNativeAd+Private.h"
#import "CSJMaterialMeta+Private.h"
#import "CSJVideoFinishView.h"

@interface CSJVideoAdView()
/**
 是否是自定义video,默认YES
 */
@property (nonatomic, assign) BOOL isCustomVideo;
/**
 draw视频展现形式
 */
@property (nonatomic, assign)BUDrawVideoShowType drawVideoType;
// 是否自动播放
@property (nonatomic, assign) BUVideoAutoPlayType videoAutoPlayType;
// 结束时处于的场景
@property (nonatomic, assign) BUVideoFinshMode videoFinishMode;

/// 由于新插屏兜底，暂停播放后避免tick执行后继续播放
@property (nonatomic, assign) BOOL shouldPause;

// 启用播放器控制层和手势
- (void)enableControlAndGesture;

// 视频详情页播放方法，区别与对外的 play，埋点不同
- (void)innerPlay;

// 视频详情页暂停没有log的方式
- (void)innerPause;

/// 视频资源总时长
- (CGFloat)innerTotalPlayTime;

/**
 获取当前播放器是否播放过的状态
 */
- (BOOL)videoPlayerPlaying;

/**
 获取当前播放器
 */
- (BUPlayer *)innerPlayer;

/**
设置是否静音
*/
- (void)setMute:(BOOL)isMute;
/**
 视频详情页的打点方法
 */
- (void)videoDetailPageReportLabel:(NSString *)label adExtraDataType:(BUAdExtraDataType)adExtraType;
/**
 当前视频是否为自动播放状态
*/
- (BOOL)getAutoPlayVideoSwitch;
/**
 Resume to the corresponding time.
 */
- (void)playerSeekToTime:(CGFloat)time;

@end
