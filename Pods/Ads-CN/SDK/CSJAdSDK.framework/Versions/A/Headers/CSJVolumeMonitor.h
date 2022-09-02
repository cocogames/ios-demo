//
//  CSJVolumeMonitor.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/3/24.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 用于监听音量变化的block
 @param newVolume 新的音量值
 */
typedef void(^VolumeChangeBlock)(CGFloat newVolume);


@interface CSJVolumeMonitor : NSObject

/**
 监听音量变化（不考虑静音按钮处于静音状态的情况，该情况下仍正常返回实际的音量值，而不是0）
 */
@property (nonatomic, copy) VolumeChangeBlock volumeChangeBlock;


+(instancetype)defaultMonitor;

//开启和关闭i音量监听
- (void)startVolumeMonitor;

- (void)endVolumeMonitor;

//获取系统音量条
+ (UISlider *)getSystemVolumeSlider;

@end
