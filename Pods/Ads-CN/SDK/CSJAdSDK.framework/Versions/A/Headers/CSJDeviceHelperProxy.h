//
//  CSJDeviceHelperProxy.h
//  CSJAdSDK
//
//  Created by Willie on 2020/8/27.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJFoundationProxy.h"

NS_ASSUME_NONNULL_BEGIN

@interfaceProxy(CSJDeviceHelper)

/// 判断设备是否越狱
+ (BOOL)bu_isJailBroken;

/// 获取idfv
+ (nullable NSString *)bu_idfvString;

/// 获取uuid
+ (NSString *)bu_uuid;

/// 返回设备Model
+ (NSString *)model;

/// 获取系统版本号
+ (float)bu_OSVersionNumber;

 /// 获取当前语言种类
+ (nullable NSString *)currentLanguage;

/// 返回设备平台信息
+ (NSString *)platform;

/// 返回设备type：iphone／ipad／ipod／apple tv等
+ (NSString *)bu_platformTypeString;

/// 具体到型号，如iPhone1,1
+ (NSString *)bu_platformString;

/// 返回硬盘空闲空间
+ (NSNumber *)freeDiskSpace;

/// 设备的总内存 单位MB
+ (NSInteger)totolDeviceMemory;

/// APP已使用的内存 单位MB
+ (NSInteger)usedAPPMemory;

// 是否是低端机型
// 1. 非iPhone机型不是低端机型
// 2. iPhone5s及以下是低端机型
+ (BOOL)lowEndMode;

/// 获取当前设备的进程，仅适用于（iOS9以下）
+ (NSArray *)runningProcesses;

///是否锁屏
+ (BOOL)is_screen_off;

///电池状态
+ (UIDeviceBatteryState)batteryState;

///电池电量
+ (float)battery_remaining_pct;

///ATT状态
+ (NSUInteger)trackingAuthorizationStatus;

/// 获取系统编译版本号
+ (NSString *)bu_buildVersionNumber;

/// iOS 系统版本
+ (NSString *)systemVersion;

@end

NS_ASSUME_NONNULL_END
