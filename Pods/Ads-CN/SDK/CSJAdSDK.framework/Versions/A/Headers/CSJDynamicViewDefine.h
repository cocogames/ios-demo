//
//  CSJDynamicViewDefine.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/7/30.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//typedef NSString * BUDynamicViewTypeString;
//FOUNDATION_EXPORT BUDynamicViewTypeString const BUDynamicViewTypeStringRoot;
//FOUNDATION_EXPORT BUDynamicViewTypeString const BUDynamicViewTypeStringLabel;

// 播放器状态
typedef NS_ENUM(NSInteger, BUDynamicViewPlayerState) {
    BUDynamicViewPlayerStateDefault        =               1,
    BUDynamicViewPlayerStatePlaying        =               2,
    BUDynamicViewPlayerStatePause          =               3,
    BUDynamicViewPlayerStateFailed         =               4,
    BUDynamicViewPlayerStateStop           =               5,
};

// 跳过按钮显示策略
typedef NS_ENUM(NSInteger, BUDynamicViewSkipShowPolicy) {
    BUDynamicViewSkipShowPolicyNotShow,
    BUDynamicViewSkipShowPolicyShowImmediately,             //
    BUDynamicViewSkipShowPolicyShowDelay,
};

typedef NS_ENUM(NSInteger, BUDynamicBrickLogoType) {
    BUDynamicBrickLogoTypeInvalid,
    BUDynamicBrickLogoTypeImage,
    BUDynamicBrickLogoTypeText,
};

typedef NS_ENUM(NSInteger, BUDynamicClickAreaType) {
    BUDynamicClickAreaTypeUnknown        = 0,
    BUDynamicClickAreaTypeLandscape      = 1,
    BUDynamicClickAreaTypeCreative       = 2,             // areaType = creative
    BUDynamicClickAreaTypeDislike        = 3,
    BUDynamicClickAreaTypeVideoDetail    = 4
};

typedef NS_ENUM(NSInteger, BUDynamicTimingPolicy) {
    BUDynamicTimingPolicyAlwaysShow,
    BUDynamicTimingPolicyHideBeginAndThenShow, // 1. 如果 timingStart 大于 0，则初始化的时候隐藏这个组件  2. 不停轮询播放状态，对应逻辑如刚刚截图所示
};

/// 4300链路优选需要知道当前点击区域是否是视频组件
typedef NS_ENUM(NSInteger, BUDynamicClickAreaCategory) {
    BUDynamicClickAreaCategoryUnknow,
    /// 点击区域是Video组件
    BUDynamicClickAreaCategoryVideo,
    /// 点击区域是Image组件
    BUDynamicClickAreaCategoryImage,
};














NS_ASSUME_NONNULL_END
