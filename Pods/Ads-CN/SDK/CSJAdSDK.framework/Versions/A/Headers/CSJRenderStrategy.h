//
//  CSJRenderStrategy.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/3.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"
#import "CSJRenderResultModel.h"
#import "CSJRenderEngineDefine.h"
#import "CSJRenderInteractionModel.h"
#import "CSJAdSDKManager+Private.h"
#import "CSJRenderEngineViewModel.h"


NS_ASSUME_NONNULL_BEGIN




@interface CSJRenderStrategy : NSObject

@property (nonatomic, strong) CSJRenderEngineViewModel *renderEngineViewModel;


// 动态布局View，当前是NativeExpressAdView及其子类
// 这里一定是要weak
@property (nonatomic, weak, readonly) UIView *containerView;
@property (nonatomic, strong, readonly) CSJRenderResultModel *renderResultModel;
// 因为前端的renderDidFinish会在超时的时候也可能会超时，所以需要添加这个字段来表明是否有渲染结果了。
@property (nonatomic, assign, readonly) BOOL haveRenderResult;

// 这里的containerView一定不能为nil
- (id)initWithRenderEngineViewModel:(CSJRenderEngineViewModel *)renderEngineViewModel containerView:(UIView * _Nonnull)containerView;

- (void)render;

- (BURenderEngineRenderType)renderType;


- (void)updateWithThemeStatus:(BUAdSDKThemeStatus)themeStatus;




// 一些细碎的逻辑
// xzj_todo 目前没有想好是否放在这里， 先临时这么解决
// 检测白屏
- (void)detectBlankIfNeed;
// 上报show事件
- (void)reportShowEventIfNeed;
// 中间页 上报数据
- (void)reportMaterialMetaIfNeedWithRelatedMaterialMetaJson:(NSDictionary *)dataDic;
// 刷新WKwebview
- (void)refreshWKWebViewIfNeed;

// 原生兜底相关
- (CGFloat)playerCurrentTime;
- (NSInteger)playerTotalTime;

- (void)sendPlayableStateChange:(BOOL)isShow reduceDuration:(NSInteger)reduceDuration;

- (void)sendShowSkipInLiveScene:(BOOL)isShow;

- (void)sendShowToast:(NSString*)toast;

/// 调用webview JSB
/// @param event jsb名称
/// @param data 参数
- (void)invokeWebEvent:(NSString *)event data:(NSDictionary * _Nullable)data;

@end

NS_ASSUME_NONNULL_END
