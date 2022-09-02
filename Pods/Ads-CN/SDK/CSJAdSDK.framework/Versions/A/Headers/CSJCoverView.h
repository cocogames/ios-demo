//
//  CSJCoverView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/9/20.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJAdSDKManager+Private.h"
#import "CSJAdInfoViewModel.h"
#import "CSJRenderClickEventModel.h"

NS_ASSUME_NONNULL_BEGIN

//@class CSJAdInfoViewModel;
@class CSJNativeAd;
@class CSJCoverView;

@protocol CSJCoverViewDelegate <NSObject>

- (void)coverViewClick:(CSJCoverView *)coverView areaCategory:(BUExpressClickAreaCategory)areaCategory clickExtraInfo:(NSDictionary *)clickExtraInfoDic;
- (void)coverViewClickVideo:(CSJCoverView *)coverView;
- (void)coverViewClickClose:(CSJCoverView *)coverView;
- (void)coverViewClickAdLogo:(CSJCoverView *)coverView;
- (void)coverViewClickDownload:(CSJCoverView *)coverView clickExtraInfo:(NSDictionary *)clickExtraInfoDic;

@end


// 动态布局的兜底View
// 因为一些历史原因，当前此View，大致分为如下的几种组成样式
// 1. 图片和相关文案控件
// 2. 视频播放器和相关文案控件，此视频播放器是兜底View负责管理
// 3. 视频播放器和相关文案控件，此视频播放器是动态布局View负责管理

@interface CSJCoverView : UIView

@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, weak) id<CSJCoverViewDelegate> delegate;

// 这两个属性需要相关的子类重写
/// 使用BUVideoView兜底时的视频播放时间
@property (nonatomic, assign, readonly) CGFloat playerCurrentTime;
/// 使用BUVideoView兜底时的视频总时间，不精确
@property (nonatomic, assign, readonly) CGFloat playerTotalTime;

@property (nonatomic, strong, readonly) CSJAdInfoViewModel *infoViewModel;


/// 类方法  由于历史遗留问题  needRemovePlayerView  和  isVideoBackup
/// @param recommendViewSize 建议的view大小
/// @param nativeAd 广告数据
/// @param needRemovePlayerView 是否需要移除动态布局的视频播放器
/// @param isVideoBackup 是否是视频兜底，是否使用动态布局的视频播放器
+ (instancetype)coverViewWithRecommendViewSize:(CGSize)recommendViewSize nativeAd:(CSJNativeAd *)nativeAd needRemovePlayerView:(BOOL *)needRemovePlayerView isVideoBackup:(BOOL *)isVideoBackup;
//+ (instancetype)coverViewWithRecommendViewSize:(CGSize)recommendViewSize infoViewModel:(CSJAdInfoViewModel *)infoViewModel needRemovePlayerView:(BOOL *)needRemovePlayerView isVideoBackup:(BOOL *)isVideoBackup;


- (void)updateWithDarkMode:(BOOL)darkMode;
- (void)backViewAction:(nullable UIView *)clickView;

@end

NS_ASSUME_NONNULL_END
