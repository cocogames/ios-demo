//
//  CSJPlayableWebVM.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/10/29.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJRewardedVideoWebViewControllerVM.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJPlayableWebVM : CSJRewardedVideoWebViewControllerVM

/// 是否隐藏endCard关闭按钮 (纯playable隐藏 因为用了父容器的close  hideTopButtons = isPureplayable)
@property (nonatomic, assign) BOOL hideTopButtons;
/// 纯playable的关闭按钮是由父VC来添加的, 在点击关闭的时候需要埋点上报
@property (nonatomic, weak) UIButton *superVCCloseBtn;
/// 是否支持H5渲染titleBar
@property (nonatomic, assign) BOOL supportH5TitleRender;
/// 当前是否已经发放了奖励
@property (nonatomic, assign) BOOL hasSendReward;
/// 是否为从前置入口打开的playable/云游戏
@property (nonatomic, assign) BOOL isPrePlayable;

- (void)setIsPrerender:(BOOL)prerender;
- (void)renderH5TitleBar:(NSDictionary*)info;

@end

NS_ASSUME_NONNULL_END
