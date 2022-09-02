//
//  CSJRenderStrategy+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/5.
//

#import "CSJRenderStrategy.h"
#import "CSJRenderResultModel.h"
#import "CSJDynamicRenderTimeOutControlServer.h"

NS_ASSUME_NONNULL_BEGIN


@class CSJNativeAd;
@class CSJRenderStrategy;
@protocol CSJRenderStrategyDelegate <NSObject>

@required

/// 需要renderEngine做一些额外的处理，然后再透传给容器View
- (void)renderStrategy:(CSJRenderStrategy *)renderStrategy successView:(UIView * _Nullable)successView error:(NSError * _Nullable)error;
- (void)renderStrategy:(CSJRenderStrategy *)renderStrategy report_webview_time_trackWithParams:(NSDictionary * _Nullable)params;

/// 要renderEngine做一些额外的处理，然后没有然后了
- (void)renderStrategy:(CSJRenderStrategy *)renderStrategy logWithMsg:(NSString *)msg isInternal:(BOOL)isInternal;
- (void)renderStrategy:(CSJRenderStrategy *)renderStrategy interceptArray:(NSArray * _Nullable)interceptArray;

/// renderEngine透传给容器View，带上手势
- (NSDictionary *)renderStrategy:(CSJRenderStrategy *)renderStrategy renderInteractionModel:(CSJRenderInteractionModel *)renderInteractionModel clickExtraInfo:(nullable NSDictionary *)clickExtraInfoDic;
// xzj_todo:BUNativeAd问题， 先临时这么去解决
- (CSJNativeAd *)nativeAdInRenderStrategy:(CSJRenderStrategy *)renderStrategy;

@end



@interface CSJRenderStrategy ()


@property (nonatomic, strong) CSJDynamicRenderTimeOutControlServer *timeOutControlServer;

//
@property (nonatomic, strong, readwrite) CSJRenderResultModel *renderResultModel;

// 这里的delegate故意没有指定具体的名称
@property (nonatomic, weak) id delegate;


#pragma mark - safeDelegate
- (void)safeDelegate_renderStrategy:(CSJRenderStrategy *)renderStrategy successView:(UIView * _Nullable)successView error:(NSError * _Nullable)error;
- (void)safeDelegate_renderStrategy:(CSJRenderStrategy *)renderStrategy report_webview_time_trackWithParams:(NSDictionary * _Nullable)params;

- (void)safeDelegate_renderStrategy:(CSJRenderStrategy *)renderStrategy logWithMsg:(NSString *)msg isInternal:(BOOL)isInternal;
- (void)safeDelegate_renderStrategy:(CSJRenderStrategy *)renderStrategy interceptArray:(NSArray *)interceptArray;


- (CSJNativeAd *)safeDelegate_nativeAdInRenderStrategy:(CSJRenderStrategy *)renderStrategy;
- (NSDictionary *)safeDelegate_renderStrategy:(CSJRenderStrategy *)renderStrategy renderInteractionModel:(CSJRenderInteractionModel *)renderInteractionModel clickExtraInfo:(nullable NSDictionary *)clickExtraInfoDic;

#pragma mark - Report

/// 给全链路埋点追加 "render_success" 节点
/// @param info 追加参数
- (void)reportRenderSuccessWithInfo:(NSDictionary * _Nullable)info;

#pragma mark - Debug Info
- (NSString *)logKeyName;
@end

NS_ASSUME_NONNULL_END
