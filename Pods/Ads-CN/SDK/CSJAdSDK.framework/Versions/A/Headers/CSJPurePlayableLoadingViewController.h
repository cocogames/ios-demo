//
//  CSJPurePlayableLoadingViewController.h
//  CSJAdSDK
//
//  Created by 李盛 on 2019/8/7.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJRewardedVideoWebViewController.h"

NS_ASSUME_NONNULL_BEGIN

@class CSJPurePlayableLoadingViewController;

@protocol CSJPurePlayableLoadingViewControllerDelegate <NSObject>

- (void)clickButtonTapFromPlayableLoading;

- (void)purePlayableRemoveLoadingByTimeout;

- (void)purePlayableVolumeChange:(CSJPurePlayableLoadingViewController *)vc isMute:(BOOL )isMute;

- (BOOL)isPlayableRenderFailed;
@end

typedef NS_ENUM(NSInteger,BULoadingTrackingStatus) {
    BULoadingTrackingStatus_LoadingSuccess = 0,
    BULoadingTrackingStatus_H5Remove = 1,
    BULoadingTrackingStatus_H5TimeOut = 2,
    BULoadingTrackingStatus_RenderFailed = 3
};
@interface CSJPurePlayableLoadingViewController : UIViewController
@property (nonatomic, weak) id<CSJPurePlayableLoadingViewControllerDelegate> delegate;
@property (nonatomic, copy) NSString *ritScene;
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, assign) BOOL isTransform;    //自己是否旋转
@property (nonatomic, assign) BUChildTransformDirection transformDirection;
@property (nonatomic, assign) BOOL isRewardedVideo; // YES: 激励视频 NO:全屏视频
@property (nonatomic, assign) BOOL hideTopButtons;//是否隐藏endCard关闭按钮 (纯playable隐藏 因为用了自己的close)
@property (nonatomic, assign) BOOL isLandscape;//给当前以及子类判断是否横屏情况
@property (nonatomic, assign) BOOL isRenderFailed; // 渲染失败
/// 关闭按钮

@property (nonatomic, assign) BUVideoWebPageType pageType;

@property (nonatomic, assign) BOOL isInitMute;

/// 关闭loading页原因 0 加载完成  1前端jsb回调隐藏  2超时  3渲染失败
@property (nonatomic, assign) BULoadingTrackingStatus trackStatus;

- (instancetype)initViewControllerWithAd:(CSJMaterialMeta *)materialMeta;
@end



NS_ASSUME_NONNULL_END
