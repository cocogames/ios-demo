//
//  CSJDynamicClickInfo.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/24.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJDynamicViewDefine.h"

typedef NS_ENUM(NSInteger, BUDynamicClickViewSource) {
    BUDynamicClickViewSourceButton,
};

NS_ASSUME_NONNULL_BEGIN
/**
{
    areaType = 2;
    clickInfo =     {
        "button_height" = 16;
        "button_width" = "20.046875";
        "button_x" = 378;
        "button_y" = 15;
        "down_time" = 1598239494734;
        "down_x" = 376;
        "down_y" = 306;
        "up_time" = 1598239494837;
        "up_x" = 376;
        "up_y" = 306;
    };
}
*/

// xzj_todo 这个类也许可以共用到很多其他的地方去
@interface CSJDynamicClickInfo : NSObject

@property (nonatomic, weak) UIView *responseView;
@property (nonatomic, assign) CGPoint downPoint;
@property (nonatomic, assign) CGPoint upPoint;
@property (nonatomic, assign) BUDynamicClickViewSource clickViewSource;

// 会尽快优化  xzj_todo
@property (nonatomic, assign) BOOL openPlayableLandingPage;
@property (nonatomic, assign) BOOL removeOpenPlayableLandingPage;
/// 4300链路优选当前点击区域, 默认-1
@property (nonatomic, assign) BUDynamicClickAreaCategory clickAreaCategory;

- (void)mapToView:(UIView *)view;

- (NSDictionary *)dictionaryValue;
@end

NS_ASSUME_NONNULL_END
