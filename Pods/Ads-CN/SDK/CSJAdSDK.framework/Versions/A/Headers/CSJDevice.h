//
//  CSJDevice.h
//  CSJAdSDK
//
//  Created by chenren on 10/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, BUDeviceSupportOrientationMask) {
    BUDeviceSupportOrientationMaskUnknow = 0,
    BUDeviceSupportOrientationMaskPortrait = (1 << BUDeviceSupportOrientationMaskUnknow),
    BUDeviceSupportOrientationMaskLandscape = (1 << BUDeviceSupportOrientationMaskPortrait)
};

// 枚举定义，默认从0开始
typedef NS_ENUM(NSInteger, BUDeviceType) {
    BUDeviceTypeOther = 0,
    BUDeviceTypePhone,
    BUDeviceTypePad,
    BUDeviceTypeTV,
};

typedef NS_ENUM(NSInteger, BUDeviceOSType) {
    BUDeviceOSTypeOther = 0,
    BUDeviceOSTypeAndroid,
    BUDeviceOSTypeiOS,
    BUDeviceOSTypeWindows,
};

typedef NS_ENUM(NSInteger, BUDeviceConnectionType) {
    BUDeviceConnectionTypeUnknown = 0,
    BUDeviceConnectionTypeWIFI = 1,
    BUDeviceConnectionType2G,
    BUDeviceConnectionType3G,
    BUDeviceConnectionType4G,
    BUDeviceConnectionType5G,
};

typedef NS_ENUM(NSInteger, BUDeviceOSLang) {
    BUDeviceOSLangOther = 0,
    BUDeviceOSLangCHN,
    BUDeviceOSLangENG,
};

typedef enum : NSInteger {
    BUDeviceAirplaneStatusUnknown = -1,//未知
    BUDeviceAirplaneStatusClose = 0,//关闭飞行模式
    BUDeviceAirplaneStatusOpen = 1,//飞行模式开启
} BUDeviceAirplaneStatus;

typedef enum : NSInteger {
    BUDeviceHeadsetUnspecified = -1,//未定义
    BUDeviceHeadsetNoConnect = 0,//没有连接
    BUDeviceHeadsetConnect = 1,//连接
} BUDeviceHeadset;//有线耳机插入状态

/*
 *  levi.duan todo: BUDevice这个方法由于一个线程调取读取方法[CSJDevice loadCurrentAppInfo],另一个线程写入方法[CSJDevice dictionaryValue]造成同一个字段读取和写入操作，由于字段线程非原子操作会导致字段过多release或者retain的操作，暂时由于时间关系，先将nonatomic改成atomic字段，进行crash修复，后期会将线程冲突问题的源头进行已修复。
 */
@interface CSJDevice : NSObject

/// 设备ID，iOS系统取idfa
//@property (nonatomic, copy) NSString *did;

/// appLog获取的设备ID
@property (copy) NSString *applog_did;

/// 接口返回did,如果没有idfa情况后端生成的
@property (atomic, copy) NSString *device_id;

/// 设备IMEI
@property (atomic, copy) NSString *imei;

/// 设备类型
@property (atomic, assign) BUDeviceType type;

/// 操作系统类型，iOS取
@property (atomic, assign) BUDeviceOSType os;

/// 操作系统的版本
@property (atomic, copy) NSString *osVersion;

/// build版本号
@property (atomic, copy) NSString *buildVersion;

/// 设备设置的语言
@property (atomic, copy) NSString *devLangLocalization;

/// 设备厂商
@property (atomic, copy) NSString *vendor;

/// 设备型号
@property (nonatomic, copy) NSString *devModelType;

/// 设备的网络类型
@property (atomic, assign) BUDeviceConnectionType connType;

/// 手机存储容量 3300 add
@property (nonatomic, copy) NSString *volume_capacity;

/// 设备屏幕宽度
@property (atomic, assign) NSUInteger screenWidth;

/// 设备屏幕高度
@property (atomic, assign) NSUInteger screenHeight;

/// 系统更新时间 3300 add
@property (atomic, copy) NSString *pb;

/// SIM卡串号
@property (atomic, copy) NSString *imsi;
/// 运营商名字
@property (atomic, copy) NSString *carrierName;
/// 运营商国家码
@property (atomic, copy) NSString *MCC;
/// 运营商编码
@property (atomic, copy) NSString *MNC;
/// 设备开机时间戳，单位ms
@property (atomic, copy) NSString *boot;
/// 打开手机到请求广告的时间长度，单位ms
@property (atomic, copy) NSString *powerOnTime;
@property (atomic, copy) NSString *phoneName;
// 用户定义的设备名称，设置-通用-关于本机-名称
@property (atomic, copy) NSString *devTagName;
@property (atomic, copy) NSString *ip;
@property (atomic, copy) NSString *ipv4;
@property (atomic, copy) NSString *ipv6;

/// article_u用于广告物料请求，其他的情况走BUNetInfoHelper的userAgentString
/// 3501改为真实webview userAgent
@property (atomic, copy) NSString *userAgent;
/// GMT时区 ETC格式
@property (atomic, copy) NSString *timeFormatRegion;
/// 时区城市
@property (atomic, copy) NSString *deviceCity;
/// 时区对应的偏移秒数
@property (nonatomic, copy) NSString *secondsFromGMT;
/// 判断是否为国内的域名
//@property (nonatomic, assign) BOOL isChinaLocal;
/// 判断是否为亚洲的域名
@property (nonatomic, assign) BOOL isAsiaZone;
/// 判断是否为欧洲的域名
@property (nonatomic, assign) BOOL isEuropeZone;
/// idfv
@property (atomic, copy) NSString *idfv;
/// 设备剩余空间
@property (atomic, strong) NSNumber *deviceFreeSize;
/// 国家编码，3400
@property (atomic, copy) NSString *countryOrderNum;
/// 内存总空间，单位Byte，3400
@property (atomic, copy) NSString *totalMemory;
///
@property (atomic, copy, readonly) NSString *deviceTotalSize;
///
@property (nonatomic, copy) NSString *localTimeZone;
/// CPU数目
@property (atomic, assign) NSInteger cpuNum;
/// 设备类型
@property (atomic, copy) NSString *deviceType;
/// 完整的本地语言信息
@property (atomic, copy) NSString *localeLanguage;
///截图时间
@property (atomic, copy) NSString *screenshot_time;

///sec did
@property (atomic, copy) NSString *msdk_sec_did;

- (void)loadCurrentAppInfo;

- (void)resetPrivateInfo;

- (NSDictionary *)dictionaryValue;

///是否锁屏
+ (BOOL)is_screen_off;

///电池状态
+ (UIDeviceBatteryState)batteryState;

///电池电量
+ (float)battery_remaining_pct;

///获取应用支持方向信息
+ (BUDeviceSupportOrientationMask)supportLandscapeBySystemConfiguration;

///获取应用支持方向信息
+ (UIInterfaceOrientationMask)supportOrientationBySystemConfiguration;

/// 当前应用的方向
+ (UIInterfaceOrientation)bu_currentOrientation;

+ (instancetype)currentDevice;


/// 请求时用到，一些基础信息
+ (NSDictionary *)briefInfo;

@end

