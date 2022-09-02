//
//  CSJCoverView+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/9/20.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJCoverView.h"

// 在此文件中添加了共用的头文件，这样其子类就不需要重复添加了
#import "CSJUnionMacros.h"

#import "CSJNativeAd+Private.h"
#import "CSJAdSlot+Private.h"
#import "CSJDislikeButton.h"
#import "CSJAdInfoViewModel.h"
#import "CSJStarView.h"
#import "CSJRenderClickEventModel.h"
#import "CSJMaterialMeta+Splash.h"

NS_ASSUME_NONNULL_BEGIN

#define BU_EdgeInset 12

@interface CSJCoverView ()

@property (nonatomic, strong) CSJNativeAd *nativeAd;
//@property (nonatomic, strong) CSJAdInfoViewModel *infoViewModel;


@property (nonatomic, strong) UIView *backView; // 容器ui
@property (nonatomic, strong) UILabel *titleLabel; // 长标题
@property (nonatomic, strong) UILabel *descriptionLabel; // 短标题
@property (nonatomic, strong) CSJDislikeButton *dislikeButton;
@property (nonatomic, strong) UIImageView *logoImageView; // 穿山甲logo
@property (nonatomic, strong) UILabel *ADXLabel; // ADX 标题
@property (nonatomic, strong) UIButton *downloadButton; // 下载按钮

@property (nonatomic, strong) UIImageView *iconImageView; // 头像icon
@property (nonatomic, strong) UILabel *scoreLabel; // 评分
@property (nonatomic, strong) CSJStarView *starView; // 星级

@property (nonatomic, strong) UIVisualEffectView *effectView; // 高斯模糊 v3300 add

@property (nonatomic, strong) UIImageView *barBackgroundImgView; // 下载bar渐变背景

- (instancetype)initWithFrame:(CGRect)frame nativeAd:(CSJNativeAd *)nativeAd;

#pragma mark - Override
- (void)pbu_override_buildView;
- (void)pbu_override_buildViewData;


#pragma mark - fill sub view data
- (void)pbu_fillDataWithImageView:(UIImageView *)imageView imageURLString:(NSString *)imageURLString;
- (void)pbu_fillData_mainImageView;
- (void)pbu_fillData_titleLabel;
- (void)pbu_fillData_descriptionLabel;
- (void)pbu_fillData_downloadButton;
- (void)pbu_fillData_iconImageView;
- (void)pbu_fillData_scoreLabel;
- (void)pbu_fillData_starView;
- (void)pbu_fillData_ADXLabel;

#pragma mark - safeDelegate
/// 点击了coverView事件
/// @param coverView 兜底视图
/// @param areaCategory 点击区域是否在视频范围内(4300 链路优选)
/// @param clickinfoDic 点击信息
- (void)safeDelegate_coverViewClick:(CSJCoverView *)coverView areaCategory:(BUExpressClickAreaCategory)areaCategory clickExtraInfo:(nullable NSDictionary *)clickinfoDic;
- (void)safeDelegate_coverViewClickVideo:(CSJCoverView *)coverView;
- (void)safeDelegate_coverViewClickAdLogo:(CSJCoverView *)coverView;
- (void)safeDelegate_coverViewClickDownload:(CSJCoverView *)coverView clickExtraInfo:(nullable NSDictionary *)clickinfoDic;


@end

NS_ASSUME_NONNULL_END
