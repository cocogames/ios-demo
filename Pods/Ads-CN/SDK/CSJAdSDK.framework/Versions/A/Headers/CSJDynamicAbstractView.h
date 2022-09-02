//
//  CSJDynamicAbstractView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/7/30.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJDynamicViewDefine.h"
#import "CSJDynamicBrickModel.h"
#import "CSJDynamicViewProtocol.h"
#import "CSJDynamicClickInfo.h"
#import "CSJDynamicJSViewModel.h"
#import "CSJDynamicAbstractDecorator.h"
#import "CSJDynamicBaseFunction.h"
#import "CSJDynamicAbstractViewProtocol.h"
#import "CSJDynamicViewGlobalModel.h"

// xzj_todo  可优化点， 节点和view分离， 目前是view中包含了节点
NS_ASSUME_NONNULL_BEGIN

@class CSJDynamicAbstractView;
@class CSJDynamicView;



@protocol CSJDynamicAbstractViewDelegate <NSObject>

// 设置是否静音
- (void)dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView videoMuted:(BOOL)muted;

- (void)dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView changeVideoStateToStateType:(NSInteger)stateType;
// 跳过事件
- (void)skipInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;
// 打开隐私
- (void)openPrivacyAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;
- (void)interstitialWebviewInCloseAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;
// 点击事件
- (void)dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView clickAreaType:(BUDynamicClickAreaType)clickAreaType  userBehaviorType:(BUAdUserBehaviorType)userBehaviorType clickInfo:(CSJDynamicClickInfo *)clickInfo;
- (void)dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView adAnalysisDataWithParams:(NSDictionary *)params;
// 获取videoInfo
- (void)dynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView videoInfoFrame:(CGRect)videoInfoFrame;
// 展示 SDKOverlay
- (void)showSKOverlayInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;

// 注册定时器事件
- (void)registerVideoStateTimerInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;
- (void)removeVideoStateTimerInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView;


- (void)registerTimingInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView timingProtocol:(id<CSJDynamicAbstractViewTimingProtocol>)timingProtocol;
- (void)removeTimingInDynamicAbstractView:(CSJDynamicAbstractView *)dynamicAbstractView timingProtocol:(id<CSJDynamicAbstractViewTimingProtocol>)timingProtocol;

@end




@interface CSJDynamicAbstractView : UIView

@property (nonatomic, weak) CSJDynamicView *dynamicView;
@property (nonatomic, weak) CSJDynamicAbstractView *parentView;
@property (nonatomic, weak) id<CSJDynamicAbstractViewDelegate> delegate;
@property (nonatomic, strong) CSJDynamicJSViewModel *jsViewModel;
@property (nonatomic, copy) NSArray<NSArray <CSJDynamicAbstractView *> *> *buDynamic_children;

@property (nonatomic, strong) CSJDynamicViewGlobalModel *globalModel;


- (instancetype)initWithGlobalModel:(CSJDynamicViewGlobalModel *)globalModel layoutDictionary:(NSDictionary *)dic parentView:(CSJDynamicAbstractView * _Nullable)parentView error:(NSError **)error;
- (void)associateWithChildViewsWithDynamicView:(CSJDynamicView *)dynamicView delegate:(id<CSJDynamicAbstractViewDelegate>)delegate;
- (void)render;


// 夜间模式，目前只支持背景色和文字颜色的更改
- (void)updateWithDarkMode:(BOOL)darkMode;

- (NSString *)currentBrickType;

- (BOOL)isBackgroundColorIsTransparent;


@end

NS_ASSUME_NONNULL_END
