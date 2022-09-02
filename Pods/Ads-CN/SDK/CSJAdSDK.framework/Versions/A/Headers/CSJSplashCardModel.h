//
//  CSJSplashCardModel.h
//  CSJAdSDK
//
//  Created by ByteDance on 2022/3/21.
//

#import <Foundation/Foundation.h>
#import "CSJBasicModel.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const SplashCardShowCount;
extern NSString *const SplashCardTimeInterval;

typedef NS_ENUM(NSInteger, CSJSplashCardCloseTrackType) {
    CSJSplashCardCloseTrackType_Auto = 0,     // 倒计时结束
    CSJSplashCardCloseTrackType_Close = 1,     // 点击关闭
    CSJSplashCardCloseTrackType_Click = 2      // 转化后关闭
};

typedef NS_ENUM(NSInteger, CSJSplashCardClickTrackType) {
    CSJSplashCardClickTrackType_Button = 0,       // 点击按钮
    CSJSplashCardClickTrackType_Image = 1,        // 点击图片
    CSJSplashCardClickTrackType_Logo = 2,         // 点击应用图标
    CSJSplashCardClickTrackType_Source = 3,       // 点击广告来源
    CSJSplashCardClickTrackType_Title = 4,        // 点击标题
    CSJSplashCardClickTrackType_WhiteOver = 5     // 点击空白区域
};

@interface CSJSplashCardModel : CSJBasicModel

// 若未下发，取默认值false
@property (nonatomic, assign) BOOL click_on_close;

// 若未下发，取默认值5
@property (nonatomic, assign) NSInteger card_stay_count_down;

// 按钮第一行文字 “点击跳转”
@property (nonatomic, copy) NSString *card_top_text;

// 按钮第二行文字 ”详情页或第三方应用”
@property (nonatomic, copy) NSString *card_text;

/*
  1:卡片整体可点, 默认值2
  2:仅卡片中按钮可点
 */
@property (nonatomic, assign) NSInteger card_click_area;


@end

NS_ASSUME_NONNULL_END
