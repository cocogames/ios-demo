//
//  CSJSplashMotionManager.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/7/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// 4700 CSJAccelerometerMotionManager重命名
// @xuzhijun 收敛原生动态化海外和国内的差异
typedef void(^CSJAccelerometerMotionAction)(void);
@interface CSJAccelerometerMotionManager : NSObject
@property (nonatomic, copy) CSJAccelerometerMotionAction acceleroMotionAction;
@property (nonatomic, assign, readonly) BOOL triggerFromWeb; // webview触发的
@property (nonatomic, assign) NSInteger calculationMethod;
/// 摇一摇监听是否已开启
@property (nonatomic, assign, readonly) BOOL accelerometerActive;
/// 当前监听的阈值
@property (nonatomic, assign, readonly) CGFloat amplitude;
+ (instancetype)sharedInstance;

- (void)startAccelerometerWithAmplitude:(CGFloat)amplitude triggerFromWeb:(BOOL)fromWeb;

- (void)stopAccelerometer;
@end

NS_ASSUME_NONNULL_END
