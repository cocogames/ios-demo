//
//  UITableViewCell+CSJATouchTracker.h
//  CSJAdSDK
//
//  Created by yin on 2017/12/21.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITableViewCell (BUATouchTracker)
/// 记录UITouch的状态，用于3D touch反作弊打点
@property (nonatomic, assign) UITouchPhase bu_phase;

/// 反作弊埋点
@property (nonatomic, readonly) NSDictionary *bu_eventDict_sec;

/// 记录埋点事件  参数为1 点击埋点  参数为2 滑动埋点 参数为3 后续增加埋点
@property (nonatomic, assign) BUAdUserBehaviorType user_behavior_move;

@end
