//
//  CSJTwistMotionManager.h
//  CSJAdSDK
//
//  Created by Willie on 2021/9/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^BUTwistMotionHandler)(BOOL didTwist, NSError * __nullable error);

/// 监听摇一摇动作的类
@interface CSJTwistMotionManager : NSObject

/// 当前设备是否可以监听摇一摇动作
- (BOOL)twistAvailable;

/// 开始监听摇一摇动作
/// @param threshold 单方向超过多少度触发摇一摇事件
/// @param repeat 是否允许重复触发
/// @param handler 触发摇一摇事件后执行的 block
- (BOOL)startTwistWithThreshold:(NSInteger)threshold
                         repeat:(BOOL)repeat
             updatesWithHandler:(BUTwistMotionHandler)handler;

/// 停止监听摇一摇动作
- (void)stopTwistUpdates;

@end

NS_ASSUME_NONNULL_END
