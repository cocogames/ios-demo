//
//  CSJSplashControlModel.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2021/3/7.
//  Copyright © 2021 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJSplashTextConfigureModel.h"

@class CSJSplashControlSlideAreaModel;

typedef NS_ENUM(NSUInteger, BUSplashControlType) {
    BUSplashControlTypeNormal = 1,//默认全屏可点击
    BUSplashControlTypeBottom = 2 //只有底部灰色可以点击
};

/// 开屏合规个性化动画样式
typedef NS_ENUM(NSInteger, BUSplashControlAnimtionStyle) {
    /// 默认动画样式
    BUSplashControlAnimationNone = 0,
    /// 箭头引导动画
    BUSplashControlAnimationArrow = 1,
    /// 手动点击动画
    BUSplashControlAnimationTouch = 2,
    /// 缩放动画
    BUSplashControlAnimationZoom = 3,
    /// 摇一摇
    BUSplashControlAnimationShake = 4,
    /// 上滑
    BUSplashControlAnimationUpSwipe = 5,
    /// 右滑
    BUSplashControlAnimationRightSwipe = 6,
    /// 扭一扭
    BUSplashControlAnimationTwist = 7,
};

/// 非中开屏的布局样式
/// https://bytedance.feishu.cn/docs/doccnvCZ9wTmUI8dlzfQ84FjmMe#
typedef enum : NSUInteger {
    BUSplashLayoutId1           = 1,
    BUSplashLayoutId2           = 2,
    BUSplashLayoutId3           = 3,
    BUSplashLayoutIdUnknownMask = 99,
} BUSplashLayoutId;

NS_ASSUME_NONNULL_BEGIN

@interface CSJSplashControlModel : NSObject <NSCoding>

@property (nonatomic, assign) BUSplashControlType splashClickAreaType;

@property (nonatomic, copy) NSString *splashClickText;
/// 文字样式配置
@property (nonatomic, strong) CSJSplashTextConfigureModel *text_config;

@property (nonatomic, assign) NSInteger area_height;
@property (nonatomic, assign) NSInteger area_width;
@property (nonatomic, assign) NSInteger area_blank_height;
@property (nonatomic, assign) NSInteger half_blank_height;
/// 开屏合规底部动画样式
@property (nonatomic, assign) BUSplashControlAnimtionStyle splash_style_id;
/// 开屏合规底部按钮变化算色
@property (nonatomic, copy) NSString *btn_background_dest_color;
/// 两行文字时第一行文字
@property (nonatomic, copy) NSString *top_splash_clicktext;
/// 两行文字时第一行文字样式配置
@property (nonatomic, strong) CSJSplashTextConfigureModel *top_text_config;
/// 滑动识别区域
@property (nonatomic, strong) CSJSplashControlSlideAreaModel *slideArea;
/// 非中开屏的布局样式
@property (nonatomic, assign) BUSplashLayoutId splashLayoutId;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

/// 双行文字样式是否可用
- (BOOL)validTwoLinesStyle;

- (BOOL)validAnimaitonNone;
- (BOOL)validAnimationShake;
- (BOOL)validAnimationZoom;
- (BOOL)validAnimationArrow;
- (BOOL)validAnimationTouch;
@end

NS_ASSUME_NONNULL_END
