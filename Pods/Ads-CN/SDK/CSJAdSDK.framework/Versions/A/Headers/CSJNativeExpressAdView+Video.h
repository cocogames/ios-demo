//
//  CSJNativeExpressAdView+Video.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/8/1.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJNativeExpressAdView.h"
#import "CSJUSettingService.h"
#import "CSJASlotContext.h"
#import "CSJMaterialMeta+Private.h"
#import "CSJNativeExpressVideoAdContext.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUVideoStateType) {
    BUVideoStateTypePlay       = 1,  //开始播放
    BUVideoStateTypePause      = 2,  //暂停播放
    BUVideoStateTypeContinue   = 3,  //继续播放
    BUVideoStateTypeStop       = 4,  //停止播放
    BUVideoStateTypeReplay     = 5,  //重新播放
};

@interface CSJNativeExpressAdView (Video) <BUVideoPlayerDelegate>
@property (nonatomic, strong) BUPlayer * _Nullable player;
@property (nonatomic, assign) BOOL hasPlayedFinish;
@property (nonatomic, assign) BOOL hasPlayed;
@property (nonatomic, assign) BOOL playingOnline;
@property (nonatomic, assign) BOOL isDefaltState;//初始播放状态，播放器初始播放状态有问题，怕改动造成其他地方异常，暂时做一个兼容

/// video duration.
@property (nonatomic, readonly) NSInteger realVideoDuration;

/// Get the already played time.
@property (nonatomic, readonly) CGFloat realCurrentPlayedTime;

@property (nonatomic, copy) NSDictionary *js2NativeParam;

- (void)close;

- (void)registregistReachability;// 网络状态变化的通知
- (void)receiveWillEnterForegroundNotification;
- (void)receiveEnterBackgroundNotification;
- (void)receiveWillTerminateNotification;
- (BOOL)_shouldInitPlayer;

- (void)_initPlayer;
- (void)startPlayVideo;
- (void)handleClickEventInvideo:(CSJASlotContext *)context;
- (void)handleSkipVideo;
- (void)handleSkipVideo:(CSJNativeExpressVideoAdContext * _Nullable)context;
- (void)handleInvalidVideoUrl;
- (void)showDislikeHUD;
- (void)handleChangeVideoStateWithParams:(NSDictionary *)result;

- (void)play;
- (void)pause;
- (void)continuePlay;
- (void)replay;
- (void)stop;
- (CGFloat)currentPlayTime;
- (CGFloat)innerTotalPlayTime;
- (void)setMute:(BOOL)isMUte;
- (void)audioSessionHandleWithMute:(BOOL)mute;

/// 轮播隐藏banner事件处理，停止播放
- (void)bannerCarouselAction;

- (void)reportLabel:(NSString *)label adExtraDataType:(BUAdExtraDataType)adExtraType;

- (void)reportLabel:(NSString *)label adExtraDataType:(BUAdExtraDataType)adExtraType skipType:(BUEncardSkipType) skipType;




- (NSDictionary *)jsCallNative_getCurrentVideoState;
- (void)jsCallNative_muteVideoWithParams:(NSDictionary *)params;
- (void)jsCallNative_skipVideo;
- (void)jsCallNative_changeVideoStateWithParams:(NSDictionary *)result;
- (void)jsCallNative_startVideoTransformWithParams:(NSDictionary *)result;
/// 精准暂停请求
/// @param param 参数
- (NSDictionary *)handleRequestVideoPause:(NSDictionary *)param;
@end

NS_ASSUME_NONNULL_END
