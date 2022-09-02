//
//  CSJDislikeContext.h
//  CSJAdSDK
//
//  Created by xzj on 2020/4/22.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUCloseButtonStyle) {
    BUCloseButtonStyle_Origin,
    BUCloseButtonStyle_Skip,
    BUCloseButtonStyle_Countdown,
    BUCloseButtonStyle_CountdownAndSkip,
    BUCloseButtonStyle_CountdownAndCanbeTurnedOffAfter,
    BUCloseButtonStyle_CanbeTurnedOffAfter,
    BUCloseButtonStyle_Close,
};

//1. 激励&全屏视频播放界面：video_player；
//2. endcard：endcard;
//3. playable：playable；
//4. 落地页：landing_page
// https://bytedance.feishu.cn/docs/doccnrbAO60C71LkPzjyEpDDSth#
typedef NS_ENUM(NSUInteger, BUDislikeSource) {
    BUDislikeSource_unknown             = 0, // unknown
    BUDislikeSource_video_player        = 1, // video_player
    BUDislikeSource_endcard             = 2, // endcard
    BUDislikeSource_playable            = 3, // playable
    BUDislikeSource_landing_page        = 4, // landing_page
    BUDislikeSource_other               = 99,// feed，banner
};



@class CSJMaterialMeta;
@class CSJDislikeWords;

@interface CSJDislikeContext : NSObject

@property (nonatomic, strong, nullable) CSJMaterialMeta *materialMeta;
@property (nonatomic, assign) BUDislikeSource source; // require
@property (nonatomic, assign) CGRect startFrame; // option

@property (nonatomic, copy, nullable) void (^dislikeResultBlock)(NSArray<CSJDislikeWords *> * _Nonnull filterwords, NSString *comment);
@property (nonatomic, copy, nullable) void (^cancelBlock)(void);
@property (nonatomic, copy, nullable) void (^dislikeViewControllerPresentCompletionBlock)(void);
@property (nonatomic, copy, nullable) void (^duplicateTapedDislike)(void);

/// 这个需要判断重复上报dislike
- (void)showFromViewController:(UIViewController *)viewController inView:(UIView *)view;

// 这个不需要判断重复上报dislike
- (void)showFromViewController:(UIViewController *)viewController;
- (void)remove;

@end

NS_ASSUME_NONNULL_END
