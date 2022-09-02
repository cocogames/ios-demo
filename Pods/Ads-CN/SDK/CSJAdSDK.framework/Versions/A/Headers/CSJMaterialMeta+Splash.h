//
//  BUMaterialMeta+BUUtil.h
//  CSJAdSDK
//
//  Created by carl on 2017/9/7.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import "CSJMaterialMeta.h"
#import "CSJMaterialMeta+Private.h"
#import "CSJSplashBottomViewInterface.h"
#import "CSJSplashPrecacheVideoModel.h"
#import "CSJSplashControlModel.h"
#import "CSJSplashCardModel.h"
#import "CSJSplashZoomOutModel.h"

// status of meta (新增字段顺延，不要影响埋点)
typedef NS_ENUM(NSUInteger, BUMaterialMetaStatus) {
    BUMaterialMetaStatusNone = 0, // has no cache
    BUMaterialMetaStatusDefault = 1, // default status, can be used
    BUMaterialMetaStatusExpired = 2, // expired, if expireTimestamp < current time
    BUMaterialMetaStatusMissing = 3, // image count = 0 or has none of image url
    BUMaterialMetaStatusInvalidByServer = 4 // is invalid, checked by server
};

typedef NS_ENUM(NSInteger, BUSplashShowType) {
    BUSplashShowType_image           = 0,   //图片类物料，展示了图片
    BUSplashShowType_video           = 1,   //视频类物料，视频缓存成功，展示了视频
    BUSplashShowType_defaultImage    = 2,   //视频类物料，视频没缓存成功展示了图片
    BUSplashShowType_express         = 3,   //动态布局类型
};

typedef NS_ENUM(NSInteger, BUSplashSourceType) {
    BUSplashSourceType_nativeImage  = 0,         // 最终展示自渲染图片
    BUSplashSourceType_nativeVideo  = 1,         // 最终展示自渲染视频
    BUSplashSourceType_dynamicImage = 2,         // 最终展示动态渲染图片
    BUSplashSourceType_dynamicVideo = 3         // 最终展示动态渲染视频
};

typedef NS_ENUM(NSInteger, BUSplashCoverType) {
    BUSplashCoverTypeMiddle_2_4 = 0,
    BUSplashCoverTypeMiddle_3_5 = 1,
    BUSplashCoverTypeFullScreen = 2,
};


@interface CSJMaterialMeta (Splash) <CSJSplashBottomViewInterface>

///3437 合规: 普通开屏控制区域添加
@property (nonatomic, strong) CSJSplashControlModel *splashControlModel;

/// 4500 卡片开屏配置
@property (nonatomic, strong) CSJSplashCardModel *splashCardModel;

/// 点睛配置
@property (nonatomic, strong) CSJSplashZoomOutModel *splash_icon;

/// 4600 品牌视频预缓存
@property (nonatomic, copy) NSArray<CSJSplashPrecacheVideoModel*> *precacheVideoModels;

@property (nonatomic, assign) BUOrientation splashFullScreenOrientation;

/// 开屏广告展示类型（旧的）
@property (nonatomic, assign) BUSplashShowType splashShowType;

// 开屏广告最终展示类型(仅适用于自渲染，动态布局、兜底均不适用)
@property (nonatomic, assign) BUSplashSourceType splashSourceType;

/// 开屏广告是否是本地缓存
@property (atomic, strong) NSNumber *splashIsCache;

// 0:不展示静音按钮， 1: 展示静音按钮 , 默认值1
@property (nonatomic, assign) NSInteger videoMuteType;

// 0: fit  1:视频完全等比拉伸，去除黑边 ,  默认值1
@property (nonatomic, assign) NSInteger videoAdapterType;


// 自渲染的时候，返回imageArray中的第一个
// 模板渲染的时候，如果有coverImage，返回CoverImage，否则返回imageArray中的第一个
- (CSJImage *)splashCoverImage;

- (BUSplashCoverType)splashCoverType;

- (BUMaterialMetaStatus)statusForSplash;

- (BUGifImage *)splashImage;

- (NSNumber *)timeDiff;

@end
