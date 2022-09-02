//
//  CSJMaterialMeta+RewardedVideo.h
//  CSJAdSDK
//
//  Created by 崔亚楠 on 2018/9/16.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import "CSJMaterialMeta.h"

#define kBURewardedLiveExtraPangleScheme    @"extra_pangle_scheme_params"
#define kBURewardedLiveShortTouch           @"live_short_touch_params"

@interface CSJMaterialMeta (RewardedVideo)
- (BOOL)vaildForRewardedVideo;
- (BOOL)vaildForPurePlayable;

/// 全屏样式的view大小
- (CGSize)fullScreenRewardedStyleViewSize;

/// 当前全屏激励支持的方向
- (UIInterfaceOrientationMask)fullScreenRewardedSupportOrientationMask;

/// 全屏激励期望的方向
- (UIInterfaceOrientation)fullScreenRewardedPreferredOrientation;

/// 全屏激励中的反馈按钮输入面板是否使用inputAccessoryView
- (void)fullScreenRewardedDislikeIfValidInputAccessoryView;

/**获取激励全屏的缓存有效时间戳, 默认返回0*/
- (NSTimeInterval)getRewardExpireTimestamp;

// 是否为激励直播
- (BOOL)validForRewardedLive;

// 满足奖励的播放时间
- (long)rewardedPlayTime:(NSTimeInterval)totalDuration;

// 激励直播跳转scheme解析
- (NSDictionary *)getRewardLiveLinkParams:(NSString*)key;

- (void)updateRewardLiveLinkParams:(long)countDown;

@end
