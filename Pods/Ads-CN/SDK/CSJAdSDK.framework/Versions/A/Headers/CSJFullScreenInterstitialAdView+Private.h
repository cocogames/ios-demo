//
//  CSJFullScreenInterstitialAdView+Private.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/1/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJFullScreenInterstitialAdView.h"
#import "CSJStarView.h"

#ifndef BUFullScreenImageAdView_Private_h
#define BUFullScreenImageAdView_Private_h

/// 全屏激励图片广告样式
typedef enum : NSUInteger {
    BUFullScreenImageStyleUnkown,
    /// image_model = 3, 1.91 : 1 竖屏
    BUFullScreenImageStyleNormalPortrait,
    /// image_model = 3, 1.91 : 1 横屏
    BUFullScreenImageStyleNormalLandscape,
    /// image_model = 33, 方图 竖屏
    BUFullScreenImageStyleSquarePortrait,
    /// image_model = 33, 方图 横屏
    BUFullScreenImageStyleSquareLandscape,
    /// image_model = 173, 竖图 竖屏
    BUFullScreenImageStyleVerticalPortrait,
    /// image_model = 173, 竖图 横屏
    BUFullScreenImageStyleVerticalLandscape,
    /// 插屏样式
    BUFullScreenImageStyleInterstitial,
} BUFullScreenImageStyle;

@class CSJRewardedVideoDownloadBarView;
@class CSJMaterialMeta;
@class CSJAdSlot;
@class CSJInterstitialCoverView;

@interface CSJFullScreenInterstitialAdView ()
/// 图片
@property (nonatomic, strong) UIImageView *adImageView;

///// 关闭按钮
//@property (nonatomic, strong) UIButton *closeButton;
//
///// 反馈按钮
//@property (nonatomic, strong) UIButton *dislikeButton;

/// app icon
@property (nonatomic, strong) UIImageView *adAppIconImageView;

/// 标题
@property (nonatomic, strong) UILabel *adTitleLabel;

/// 描述
@property (nonatomic, strong) UILabel *adDescriptionLabel;

/// 评分
@property (nonatomic, strong) UILabel *scoreLabel;

/// 星级
@property (nonatomic, strong) CSJStarView *starView;

/// 下载按钮
@property (nonatomic, strong) UIButton *adDownloadButton;

/// logo
@property (nonatomic, strong) UIImageView *logoImageView;
@property (nonatomic, strong) UILabel *ADXLabel;

/// 下载bar, 在image_mode = 173 && 竖屏时显示bar
@property (nonatomic, strong) CSJRewardedVideoDownloadBarView *adDownloadBarView;

/// 全屏1:1,2:3,3:2尺寸复用插屏的兜底
@property (nonatomic, strong) CSJInterstitialCoverView *interstitialCoverView;

/// 图片广告类型
@property (nonatomic, assign) BUFullScreenImageStyle imageStyle;

/// 广告物料
@property (nonatomic, strong) CSJMaterialMeta *materialMeta;

/// 广告rit，type等
@property (nonatomic, strong) CSJAdSlot *slot;

/// 点击手势
@property (nonatomic, strong) UITapGestureRecognizer *adTapGesture;

- (NSDictionary *)c_xyDict;

- (CGSize)textString:(NSString *)origin size:(CGSize)contentSize font:(UIFont *)textFont;

- (instancetype)initWithMaterial:(CSJMaterialMeta *)materialMeta adSlot:(CSJAdSlot *)adSlot imageStyle:(BUFullScreenImageStyle)imageStyle;
@end

#endif /* BUFullScreenImageAdView_Private_h */
