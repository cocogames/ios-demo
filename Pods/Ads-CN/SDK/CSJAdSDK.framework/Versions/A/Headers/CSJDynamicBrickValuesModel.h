//
//  CSJDynamicBrickValuesModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/13.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJDynamicViewDefine.h"
#import "CSJDynamicAnimationModel.h"

NS_ASSUME_NONNULL_BEGIN



typedef struct {
    NSInteger marginWE;
    NSInteger marginNS;
    NSInteger marginBoxWESize;
    NSInteger marginBoxNSSize;
} BUDynamicSDKBoxInfo;

typedef NS_ENUM(NSInteger, BUDynamicTextFlowType) {
    BUDynamicTextFlowType_left_right        =       0,
    BUDynamicTextFlowType_up_down           =       1,
};



// 前端枚举
//export enum INTERACT_TYPE {
//  DEFAULT = '',           '关闭'
//  SLIDE = '0',            '手势滑动'
//  CLICK = '1',            '点击'
//  PRESS = '2',            '长按'
//  CIRCLE = '3',           '画圆'
//  SHAKE = '4',            '摇一摇'
//  SLIDE_2 = '5',          '手势滑动-2'
//  CLICK_2 = '6',          '点击-2'
//  PRESS_2 = '7',          '长按-2'
//  CLICK_BUTTON = '8',     '点击-按钮'
//  SHAKE_2 = '9',          '摇一摇-2'
//  SLIDE_3 = '10',         '手势滑动-3'
//  CLICK_3 = '11',
//  SLIDE_4 = '12',
//  SLIDE_5 = '13',
//  PRESS_3 = '14',
//}

/// 轻互动类型枚举
typedef NS_ENUM(NSInteger, BUDynamicInteractionType) {
    /// 关闭
    BUDynamicInteractionType_Default = -1,
    /// 手势滑动
    BUDynamicInteractionType_Slide = 0,
    /// 点击
    BUDynamicInteractionType_Click = 1,
    /// 长按
    BUDynamicInteractionType_Press = 2,
    /// 画圆
    BUDynamicInteractionType_Circle = 3,
    /// 摇一摇
    BUDynamicInteractionType_Shake = 4,
    /// 手势滑动-2
    BUDynamicInteractionType_Slide_2 = 5,
    /// 点击-2
    BUDynamicInteractionType_Click_2 = 6,
    /// 长按-2
    BUDynamicInteractionType_Press_2 = 7,
    /// 点击-按钮
    BUDynamicInteractionType_Click_Button = 8,
    /// 摇一摇-2
    BUDynamicInteractionType_Shake_2 = 9,
    /// 手势滑动-3
    BUDynamicInteractionType_Slide_3 = 10,
    /// 点击-3
    BUDynamicInteractionType_Click_3 = 11,
    /// 手势滑动-4
    BUDynamicInteractionType_Slide_4 = 12,
    /// 手势滑动-5(上滑)
    BUDynamicInteractionType_Slide_5 = 13,
    /// 长按-3
    BUDynamicInteractionType_Press_3 = 14,
    /// 摇一摇-3
    BUDynamicInteractionType_Shake_3 = 16,
    /// 扭一扭-1
    BUDynamicInteractionType_Twist_1 = 17,
    /// 扭一扭-2
    BUDynamicInteractionType_Twist_2 = 18,
    
    /// 擦亮蒙层
    BUDynamicInteractionType_Swipe = 20,
    /// 滑动解锁
    BUDynamicInteractionType_Unlock = 22,
};

// 前端广告类型枚举
//declare const enum AD_TYPE {
//  EMBEDED = 'embeded', // 信息流广告
//  BANNER = 'banner', // Banner
//  TABLE_SCREEN = 'table_screen', // 插屏
//  DRAW = 'draw',
//  FULLSCREEN = 'full_screen', // 全屏视频
//  REWARD = 'reward', // 激励视频
//  SPLASH = 'splash', // 开屏
//}
/// 动态化广告类型
typedef NS_ENUM(NSInteger, BUDynamicAdType) {
    /// 未知
    BUDynamicAdType_Unknown = 0,
    /// Banner
    BUDynamicAdType_Banner = 1,
    /// 插屏
    BUDynamicAdType_Interstitial = 2,
    /// 开屏
    BUDynamicAdType_Splash = 3,
    /// 信息流广告
    BUDynamicAdType_Feed = 5,
    /// 激励视频
    BUDynamicAdType_Reward = 7,
    /// 全屏视频
    BUDynamicAdType_Full_Screen = 8,
    /// Draw
    BUDynamicAdType_Draw = 9,
};

@interface CSJDynamicSDKFontWidthStyleModel : NSObject

@property (nonatomic, copy) NSString *fontFamily;
@property (nonatomic, assign) NSInteger fontSize;
@property (nonatomic, assign) NSInteger fontWeight;

@property (nonatomic, assign) NSInteger letterSpacing;
@property (nonatomic, assign) NSInteger lineHeight;
@property (nonatomic, assign) CGFloat maxWidth;

- (NSDictionary *)dictionaryValue;
@end



@interface CSJDynamicBrickValuesModel : NSObject

// 记录一下，方便开发用
@property (nonatomic, copy) NSDictionary *originDictionary;

@property (nonatomic, assign) CGFloat borderRadius;
@property (nonatomic, assign) CGFloat borderSize;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGFloat interactValidate;
@property (nonatomic, assign) CGFloat paddingBottom;
@property (nonatomic, assign) CGFloat paddingLeft;
@property (nonatomic, assign) CGFloat paddingRight;
@property (nonatomic, assign) CGFloat paddingTop;
@property (nonatomic, assign) CGFloat width;


@property (nonatomic, assign) CGFloat fontSize;
@property (nonatomic, assign) CGFloat fontWeight;
@property (nonatomic, copy) NSString *fontFamily;



@property (nonatomic, copy) NSString *widthMode;
@property (nonatomic, copy) NSString *heightMode;

@property (nonatomic, assign) NSInteger zIndex;

@property (nonatomic, assign) NSInteger timingStart;
@property (nonatomic, assign) NSInteger timingEnd;


@property (nonatomic, assign) NSInteger bgColorCg;
@property (nonatomic, assign) NSInteger borderColorCg;
@property (nonatomic, assign) NSInteger colorCg;

// 这三个值都是 optional 的，分别代表是否要换行、换行的话是否要限制行数、以及要限制多少行，
@property (nonatomic, assign) NSInteger lineFeed;
@property (nonatomic, assign) NSInteger lineLimit;
@property (nonatomic, assign) NSInteger lineCount;

@property (nonatomic, copy) NSString *adType;
@property (nonatomic, copy) NSString *bgColor;
@property (nonatomic, copy) NSString *bgGradient;
@property (nonatomic, copy) NSString *borderStyle;
@property (nonatomic, copy) NSString *interactText;
@property (nonatomic, assign) BUDynamicInteractionType interactType;
@property (nonatomic, copy) NSString *justifyHorizontal;
@property (nonatomic, copy) NSString *justifyVertical;
@property (nonatomic, copy) NSString *alignItems;

@property (nonatomic, copy) NSString *color;
@property (nonatomic, copy) NSString *borderColor;
@property (nonatomic, copy) NSString *textAlign;


@property (nonatomic, copy) NSString *clickArea;
@property (nonatomic, copy) NSString *clickTigger;
@property (nonatomic, copy) NSString *clickType;
@property (nonatomic, assign) NSInteger areaType;
@property (nonatomic, assign) NSInteger openPlayableLandingPage;
@property (nonatomic, assign) NSInteger removeOpenPlayableLandingPage;



@property (nonatomic, assign) CGFloat left;
@property (nonatomic, assign) CGFloat top;
@property (nonatomic, assign) CGFloat right;
@property (nonatomic, assign) CGFloat bottom;
@property (nonatomic, assign) CGFloat useLeft;
@property (nonatomic, assign) CGFloat useRight;
@property (nonatomic, assign) CGFloat useTop;
@property (nonatomic, assign) CGFloat useBottom;
@property (nonatomic, assign) NSInteger align;

@property (nonatomic, assign) CGFloat interactVisibleTime;
@property (nonatomic, assign) CGFloat interactHiddenTime;

@property (nonatomic, assign) BOOL allowTextFlow;
@property (nonatomic, assign) BUDynamicTextFlowType textFlowType;
// 单位是秒
@property (nonatomic, assign) NSInteger textFlowDuration;

// 动画相关
@property (nonatomic, copy) NSArray <CSJDynamicAnimationModel *> *animations;
@property (nonatomic, assign) CGFloat interactSlideThreshold;
@property (nonatomic, assign) CGFloat interactBottomDistance;

@property (nonatomic, assign) BOOL useSkOverlay;
@property (nonatomic, assign) NSTimeInterval skOverlayDelay;
@property (nonatomic, assign) BOOL bgGauseBlur;
@property (nonatomic, assign) NSInteger bgGauseBlurRadius;

// video 组件独有的， banner， feed独有的
@property (nonatomic, assign) NSInteger showTimeProgress;

- (id)initWithDictionary:(NSDictionary *)dictionary type:(NSString *)type;


#pragma mark - SDK Analysis

// isDataFixed=1的时候，表明data是有效值，等于0的时候，表明是从物料里面去取数据。 data真正的结果数据是在brick中的data
@property (nonatomic, assign) NSInteger isDataFixed;
@property (nonatomic, copy) NSString *data;


@property (nonatomic, assign) CGFloat marginBottom;
@property (nonatomic, assign) CGFloat marginLeft;
@property (nonatomic, assign) CGFloat marginRight;
@property (nonatomic, assign) CGFloat marginTop;


@property (nonatomic, assign) CGFloat letterSpacing;
@property (nonatomic, assign) CGFloat lineHeight;
@property (nonatomic, assign) NSInteger position;



@property (nonatomic, assign) NSInteger tagMaxCount;
@property (nonatomic, copy) NSString *tagStyleType;

#pragma mark - SDK Analysis
- (id)realDataWithCreativeDictionary:(NSDictionary *)creativeDictionary;
- (id)realDataExtraInfoWithCreativeDictionary:(NSDictionary *)creativeDictionary;
- (CGSize)maxAvailableSize;
- (BUDynamicSDKBoxInfo)getBoxSizeInfo;
- (CSJDynamicSDKFontWidthStyleModel *)fontWidthStyleModel;

- (NSDictionary *)dictionaryValue;

/// 原生动态化广告类型
- (BUDynamicAdType)dynamicAdType;


@end

NS_ASSUME_NONNULL_END
