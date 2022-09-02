//
//  CSJNativeAd+Private.h
//  CSJAdSDK
//
//  Created by 李盛 on 2018/8/29.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import "CSJNativeAd.h"
#import "CSJDislikeButton.h"
#import "CSJAdInfoViewModel.h"
#import "CSJAdClientBiddingHandle.h"
#import "CSJADViewTrackInfo.h"

@class CSJASlotContext;
@class CSJNativeAd;

NS_ASSUME_NONNULL_BEGIN

static NSString * const kCSJAdViewdidClickNotification = @"kCSJAdViewdidClickNotification";

typedef NS_ENUM(NSInteger, BUDrawVideoShowType) {
    BUDrawVideoShowType_unKnow           = 0,       // 非Draw类型
    BUDrawVideoShowType_horizontal       = 1,       // 横版视频
    BUDrawVideoShowType_vertical         = 2,       // 竖版视频
};


@protocol CSJNativeAdShakeTriggerDelegate <NSObject>
/// 触发摇一摇代理回调
/// @param nativeAd 广告对象
- (void)shakeTriggerWithNativieAd:(CSJNativeAd *)nativeAd;
@end

@interface CSJNativeAd ()
///
/// @Warning 请注意,该属性名称的修改时, 请周知到-zth 需在接口层BUNativeAd.m 内部做同步修改. 有限期" 老接口下掉前
@property (atomic, strong, readwrite, nullable) CSJMaterialMeta *data;
@property (nonatomic, strong) CSJDislikeButton *dislikeButton;
@property (nonatomic, strong, readwrite, nullable) CSJVideoAdView *videoAdView;
@property (nonatomic, strong) NSMapTable<UIView *, CSJADViewTrackInfo *> *weakCache;
@property (nonatomic, assign) BUDrawVideoShowType drawVideoType;
@property (nonatomic, assign) BOOL isNativeExpress;//是否为动态布局
@property (nonatomic, strong) CSJAdInfoViewModel *infoViewModel;
@property (nonatomic, strong) CSJAdClientBiddingHandle *clientBiddingHandle;
/// 4700 自渲染支持摇一摇，触发摇一摇回调代理
@property (nonatomic, weak) id<CSJNativeAdShakeTriggerDelegate> shakeTriggerDelegate;

- (void)adaptContext:(CSJASlotContext*)context;
- (void)trackWithLabel:(NSString *)label extraDic:(NSDictionary *_Nullable)dict adExtraDataDic:(NSDictionary *_Nullable)adExtraDataDic ignoreLandscape:(BOOL)ignoreLandscape;
- (void)dislikeAction:(UIButton *_Nullable)sender;
- (void)middlePageDislikeAction:(UIButton *_Nullable)sender; // 中间页dislikeAction
- (void)registerShowContainer:(__kindof UIView *)containerView withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews needRepeat:(BOOL)needRepeat;
- (void)registerContainer:(__kindof UIView *_Nonnull)containerView
           clickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews
               videoViews:(NSArray<__kindof UIView *> *_Nullable)videoViews;

+ (void)splitNativeAdArray:(NSArray *)nativeAdArray inNormalRenderArray:(NSMutableArray *)normalRenderArray inDynamicRenderArray:(NSMutableArray *)dynamicRenderArray;

- (void)checkIfViewInScreen;
@end
NS_ASSUME_NONNULL_END
