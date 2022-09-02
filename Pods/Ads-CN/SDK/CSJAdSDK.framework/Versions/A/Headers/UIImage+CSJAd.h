//
//  UIImage+CSJAd.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/12/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kCSJ_endCardClose;
extern NSString *const kCSJ_fullClose;
extern NSString *const kCSJ_clearClose;
extern NSString *const kCSJ_close;
extern NSString *const kCSJ_dislike;
extern NSString *const kCSJ_leftback;
extern NSString *const kCSJ_nextCell;
extern NSString *const kCSJ_play;
extern NSString *const kCSJ_pause;
extern NSString *const kCSJ_sliderDot;
extern NSString *const kCSJ_fullScreen;
extern NSString *const kCSJ_bottomPlay;
extern NSString *const kCSJ_bottomPause;
extern NSString *const kCSJ_bottomShadow;
extern NSString *const kCSJ_topShadow;
extern NSString *const kCSJ_shrinkScreen;
extern NSString *const kCSJ_fastForward;
extern NSString *const kCSJ_fastBackward;
extern NSString *const kCSJ_replay;
extern NSString *const kCSJ_voice;
extern NSString *const kCSJ_voice_silent;
extern NSString *const kCSJ_logo;
extern NSString *const kCSJ_logoAd;
extern NSString *const kCSJ_logoAd_oversea;
extern NSString *const kCSJ_GDPRBack;
extern NSString *const kCSJ_playableLoading;
extern NSString *const kCSJ_splashZoomOutClose;
extern NSString *const kCSJ_playableLoading_oversea;
extern NSString *const kCSJ_rewardAgian;
extern NSString *const kCSJ_rewardBox;
extern NSString *const kCSJ_webViewClose;
extern NSString *const kCSJ_webViewFeedback;
extern NSString *const kCSJ_webViewGoBack;
extern NSString *const kCSJ_webViewGoForward;
extern NSString *const kCSJ_webViewReload;
extern NSString *const kCSJ_webViewSafari;

@interface UIImage (CSJAd)
// 异步获取image 不阻塞主线程
+ (void)csj_compatImageNamed:(NSString *)imageName block:(void(^)(UIImage *image))block;
// 同步方式
+ (UIImage *)csj_compatImageNamed:(NSString *)imageName;

- (UIImage *)csj_imageWithTintColor:(UIColor *)tintColor;

/// 通过颜色生成图片
/// @param color color
+ (UIImage *)csj_createImageWithColor:(UIColor *)color;

@end

NS_ASSUME_NONNULL_END
