//
//  CSJAdSDKManager+Private.h
//  CSJAdSDK
//
//  Created by carl on 2017/11/22.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJAdSDKDefines.h"
#import "CSJAdSDKManager.h"

//// 请注意该值与SDK的BUInterfaceNotifyKey_ThemeStatusChanged 保持一致
#define BUAdNotifyKey_ThemeStatusChanged            @"BUAdNotifyKey_ThemeStatusChanged"

@interface CSJAdSDKManager ()
@property (nonatomic, copy, readonly, class) NSString *sdkName;

@property (atomic, copy) NSString *extInfo;

@property (nonatomic, copy) NSString *consent_url;
/// 动态布局动态下发的地址
@property (nonatomic, copy) NSString *dyn_draw_engine_url;
/// 是否为国外
//@property (nonatomic, assign) BOOL overSeas;
//@property (nonatomic, assign) int territoryType;

///IABTCF_TCString
/// 3300 add
@property (nonatomic, copy) NSString *tcString;
///IABTCF_gdprApplies,0，不是GDPR覆盖地区的用户1，是GDPR覆盖地区的用户unset，未设置-1，不支持TCF（默认）,unset传-1，不支持传-2.
/// 3300 add
@property (nonatomic, assign) NSInteger gdprApplies;
@property (nonatomic, assign) BOOL isInit;//V4100 海外需求  是否调用了初始化方法


+ (instancetype)sharedInstance;

// 媒体的secretyKey
+ (NSString *)secretyKey;
// 设置log的extInfo,每次都设置,如果有没设置的取上次
+ (void)setExtInfo:(NSString *)extInfo;
// 获取log的extInfo ,要求与当前请求物料对应,实时获取
+ (NSString *)getExtInformationKey:(NSString *)key;
// 获取对应物料的extInfo
+ (NSString *)getExtInformationKey:(NSString *)key extInfo:(NSString *)extInfo;
// 是否为demo的appId
+ (BOOL)isPangleUnionOfficialoID;

+ (BOOL)isDemoAppID;
+ (BOOL)isDemoBundleID;
// 国内biddingToken生成通用方法，目前主要用于M
+ (NSString *)biddingTokenWithSlot:(CSJAdSlot *)slot;

/// 向测试工具发出通知
/// @param name 通知名称
/// @param useInfo 携带的数据
+ (void)postNotificaitonToMeasurementWithName:(NSString *)name info:(NSDictionary *)useInfo;

/// 测试工具是否可用
+ (BOOL)validTestMeasurementSDK;

/// 测试工具更新基本信息
+ (void)updateTestMeasurementBaseInfo;

+ (BOOL)BUAdSDKManagerInitialized;

/// 最终展示的language
+ (NSString *)bu_currentLanguage;

/// TCF监听，暂时10秒执行一次
- (void)fireTCFTimer;

/// 接口层版本号
+ (NSString *)interfaceVersion;

/// 依赖层版本号
+ (NSString *)relyVersion;

@end

