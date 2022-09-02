//
//  CSJPlayableLandingViewController.h
//  Pods
//
//  Created by wangyanlin on 2021/1/4.
//

#import <UIKit/UIKit.h>
#import "CSJAdSlot.h"
#import "CSJAdSDKDefines+Private.h"
#import "CSJMaterialMeta+Private.h"
#import "CSJRewardedVideoWebViewController.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CSJPlayableLandingViewControllerDelegate <NSObject>

- (NSInteger)currentVideoProgress;
- (void)sendPlayableReward;
- (void)setCurrentVideoProgress:(NSInteger)progress;

@end

@interface CSJPlayableLandingViewController : UIViewController

@property (nonatomic, strong) CSJAdSlot *adSlot;
/// closeType: 0. 关闭广告 1. 跳 endcard
@property (nonatomic, copy) void(^CloseBlock)(NSInteger closeType);
@property (nonatomic, copy) void(^DisappearedBlock)(void);
@property (nonatomic, copy) void(^ShowConfirmBlock)(void);
@property (nonatomic, strong) CSJRewardedVideoWebViewController *playableWebVC;
@property (nonatomic, assign) BOOL hadSwitchToWebviewVC;//激励/全屏前置 playable 需求, 会存在 loading VC 超时时间内 点击 视频跳过 进入 playable. 此时需要提前设置状态 https://bits.bytedance.net/meego/ad/issue/detail/W-1501418?parentUrl=%2Fad%2FissueView%2FyMBE_ytw4s#detail
@property (nonatomic, weak) id<CSJPlayableLandingViewControllerDelegate> delegate;
/// 当前播放进度，用于透传进度给pl
@property (nonatomic, strong) NSNumber *currentPlayProgress;
/// 是否已经完成转换（进落地页或者打开App store）
@property (nonatomic, assign) BOOL isConverted;
- (instancetype)initViewControllerWithAd:(CSJMaterialMeta *)materialMeta slot:(CSJAdSlot *)slot pageType:(BUVideoWebPageType)pageType;
- (void)updateSlientBtnState:(BOOL)isMute;

@end

NS_ASSUME_NONNULL_END
