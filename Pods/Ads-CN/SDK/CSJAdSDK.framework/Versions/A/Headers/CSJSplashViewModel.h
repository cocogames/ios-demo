//
//  CSJSplashViewModel.h
//  CSJAdSDK
//
//  Created by ByteDance on 2022/6/6.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"
#import "CSJSkipControlModel.h"
#import "CSJViewTracker.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CSJSplashViewModelDelegate <NSObject>

- (void)splashResourceLoadSuccess;

- (void)splashResourceLoadFailWithError:(NSError *)error;

@end

@interface CSJSplashViewModel : NSObject

@property (nonatomic, weak) id<CSJSplashViewModelDelegate> delegate;

// 以下这三个model属性不应该暴漏出来，但目前UI上一些封装好的控件依赖了，改动较大，先暂时保留
@property (nonatomic, strong, readonly, nullable) CSJMaterialMeta *materialMetaModel;
@property (nonatomic, strong, readonly, nullable) CSJAdSlot *adSlot;
@property (nonatomic, strong, readonly) CSJNativeAd *nativeAd;
//
@property (nonatomic, assign, readonly) CGSize adSize;

@property (nonatomic, assign, readonly) NSTimeInterval tolerateTimeout; // 开发者设置的超时时间
@property (nonatomic, assign, readonly) NSTimeInterval renderTimeoutLeft; // 留给渲染的时间

@property (nonatomic, strong, readonly) CSJImage *splashImage;
@property (nonatomic, strong, readonly) CSJImage *logoImage;
@property (nonatomic, assign, readonly) BOOL showDislike;

@property (nonatomic, assign, readonly) BOOL canShowZoomOutView; // 展示点睛
@property (nonatomic, assign, readonly) BOOL canShowCardView; // 展示卡片

@property (nonatomic, assign, readonly) BOOL hideSkipButton;
@property (nonatomic, assign, readonly) CGFloat countDown;
@property (nonatomic, assign, readonly) BOOL showAdLogoIcon; //

@property (nonatomic, assign, readonly) BOOL showAdxLabel; //
@property (nonatomic, copy, readonly) NSString *adxLabelText;

@property (nonatomic, assign, readonly) BOOL showMute; // 展示静音按钮
/// 跳过按钮位置，默认 `BUSkipControlPositionTR`
@property (nonatomic, assign, readonly) BUSkipControlPosition skipBtnPosition;
@property (nonatomic, assign, readonly) NSInteger skipLeftOrRightMargin;
@property (nonatomic, assign, readonly) NSInteger skipTopOrBottomMargin;

- (instancetype)initWithSlot:(CSJAdSlot *)slot adSize:(CGSize)adSize;

- (void)loadAdData;

- (void)setTolerateTimeout:(NSTimeInterval)tolerateTimeout;
- (void)setHideSkipButton:(BOOL)hideSkipButton;

/**
 Ad slot material id
 */
- (NSString *)getAdCreativeToken;

- (NSDictionary *)mediaExt;

// 预加载模版信息
- (void)preLoadMiddlePageWithAd:(CSJNativeAd *)nativeAd;

 
- (CSJViewTracker *)trackView:(UIView *)view isCache:(NSNumber *)isCache;

#pragma mark - event tracker
- (void)splashAdClickTrackWithExtra:(NSDictionary *)extraDic;

- (void)splashAdSkipTrackWithExtra:(NSDictionary *)extraDic;

- (void)splashEnterBackgroundTrackWithExtra:(NSDictionary *)extraDic;

- (void)splashEnterForegroundTrackWithExtra:(NSDictionary *)extraDic;

- (void)splashCardShowTrack;

- (void)splashCardClickTrackWithAdExtra:(NSDictionary *)adExtraDataDic;

- (void)splashCardCloseTrackWithAdExtra:(NSDictionary *)adExtraDataDic;

- (void)splashZoomOutShowTrackWithAdExtra:(NSDictionary *)adExtraDataDic;

- (void)splashZoomOutCloseTrackWithExtra:(NSDictionary *)extraDic;

- (void)splashZoomOutVideoShowTimeTrackWithAdExtra:(NSDictionary *)adExtraDataDic;

#pragma mark - outer call

// 给媒体开屏加载完成回调
- (void)outerCallSend;

// 给媒体回调开屏加载失败回调
- (void)outerCallNoRspWithError:(NSError *)error;

// 给媒体onTimeout回调
- (void)outerCallLoadTimeoutWithError:(NSError *)error;


#pragma mark - duration tracker
- (void)splashAdRenderTrackBegin;

- (void)splashAdRenderTrackEnd;

- (void)splashTotalLoadTimeTrack;

@end

NS_ASSUME_NONNULL_END
