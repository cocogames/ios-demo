//
//  CSJRewardedVideoTopBarView.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/10/15.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
@class CSJURitSettingModel;

typedef NS_ENUM(NSInteger, BUTopBarStyle) {
    BUTopBarStyle_rewardNormal      = 1,// 普通激励视频样式
    BUTopBarStyle_fullScreenNormal  = 2,// 普通全屏视频样式
    BUTopBarStyle_dislike           = 3,// 含有dislike的样式
    BUTopBarStyle_fullScreenImage   = 4,// 全屏图片，只有倒计时关闭
    BUTopBarStyle_fullScreenImage_dislike   = 5,// 全屏图片，dislike和倒计时关闭
    BUTopBarStyle_intersititalImage = 6,// 插屏图片，只有关闭
    BUTopBarStyle_intersititalImage_dislke   = 7,// 插屏图片，只有dislike和关闭
};

typedef NS_ENUM(NSInteger, BUTopBarSilentStatus) {
    BUTopBarSilentStatus_slient      = 1,// 静音按钮静音
    BUTopBarSilentStatus_unslient    = 2,// 静音按钮有声音
};

NS_ASSUME_NONNULL_BEGIN

@protocol CSJRewardedVideoTopBarDelegate <NSObject>
// 点击视频区域
- (void)videoTopBarTapped:(id)sender extraDic:(NSDictionary *)extraDic;
// 点击静音按钮
- (void)videoTopBarSilentButtonTapped:(id)sender;
// 点击关闭按钮
- (void)videoTopBarCloseButtonTapped:(id)sender;
// 点击负反馈按钮
- (void)videoTopBarDislikeButtonTapped:(id)sender;
// 根据具体业务解决是否展示X
- (BOOL)videoTopBarCloseButtonShowCloseIcon;
@end


@interface CSJRewardedVideoTopBarView : UIView
@property (nonatomic, weak) id <CSJRewardedVideoTopBarDelegate> delegate;
@property (nonatomic, assign, readonly) long currentSecond;//当前倒计时剩余秒数
// 负反馈按钮
@property (nonatomic, strong, readonly) UIButton *dislikeButton;
@property (nonatomic, assign) BOOL forceShowSkip; //强制展示跳过

- (instancetype)initWithFrame:(CGRect)frame isRewardedVideo:(BOOL)isRewardedVideo style:(BUTopBarStyle)style  ritModel:(CSJURitSettingModel *)ritModel materialMeta:(CSJMaterialMeta *)materialMeta;

// 更新倒计时
- (void)updateCountButtonWithSecond:(long)second totalDuration:(long)duration;
// 更新静音按钮状态
- (void)updateSilentButtonStatus:(BUTopBarSilentStatus)status;
@end

NS_ASSUME_NONNULL_END
