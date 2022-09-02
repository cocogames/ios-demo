//
//  CSJRenderEngine.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/9.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"
#import "CSJRenderInteractionModel.h"
#import "CSJRenderResultModel.h"
#import "CSJFullLinkTrackInfo.h"
#import "CSJRenderEngineDefine.h"
#import "CSJRenderStrategy.h"
#import "CSJRenderEngineViewModel.h"
@class CSJNativeAd;
NS_ASSUME_NONNULL_BEGIN



@class CSJRenderEngine;
@protocol CSJRenderEngineDelegate <NSObject>
/// 从renderStrategy拿数据，先自己处理一下，然后进行透传
- (void)renderEngine:(CSJRenderEngine *)renderEngine successView:(UIView *)successView error:(NSError *)error;
- (void)renderEngine:(CSJRenderEngine *)renderEngine report_webview_time_trackWithParams:(NSDictionary *)params;

/// 直接拿renderStrategy进行透传
- (NSTimeInterval)renderTimeoutInRenderEngine:(CSJRenderEngine *)renderEngine;
- (NSInteger)playPercentInRenderEngine:(CSJRenderEngine *)renderEngine;
- (NSDictionary *)renderEngine:(CSJRenderEngine *)renderEngine renderInteractionModel:(CSJRenderInteractionModel *)renderInteractionModel clickExtraInfo:(nullable NSDictionary *)clickExtraInfoDic;
- (void)renderEngine:(CSJRenderEngine *)renderEngine reportError:(NSError *)error;
- (void)renderEngine:(CSJRenderEngine *)renderEngine reportLabel:(NSString *)label;
// xzj_todo:BUNativeAd问题
- (CSJNativeAd *)nativeAdInRenderEngine:(CSJRenderEngine *)renderEngine;

@end


@interface CSJRenderEngine : NSObject

@property (nonatomic, strong) CSJRenderEngineViewModel *renderEngineViewModel;

@property (nonatomic, weak) id<CSJRenderEngineDelegate> delegate;
+ (instancetype)renderEngineWithInfoViewModel:(CSJAdInfoViewModel *)infoViewModel containerView:(UIView *)containerView renderIndex:(NSInteger)renderIndex;

@property (nonatomic, strong, readonly) CSJRenderResultModel *renderResultModel;
// 最后触发成功/失败回调的渲染策略，一定会有值的。因为无兜底渲染策略也是一种策略
@property (nonatomic, strong, readonly) CSJRenderStrategy *resultRenderStrategy;


- (BOOL)isRenderNative;

- (void)render;



@end

NS_ASSUME_NONNULL_END
