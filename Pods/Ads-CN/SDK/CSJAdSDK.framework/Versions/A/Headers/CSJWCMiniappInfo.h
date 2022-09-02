//
//  CSJWCMiniappInfo.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/4/8.
//

#import <Foundation/Foundation.h>
#import "CSJModelSerialization.h"
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, CSJWcMiniappSkipType) {
    /// 非微信小程序广告
    CSJWcMiniappSkipType_None = 0,
    /// deeplink默认逻辑
    CSJWcMiniappSkipType_Default = 1,
    /// 通过deeplink链接拉起小程序, 有50w次请求限制(4600)
    CSJWcMiniappSkipType_Scheme,
};

typedef NS_ENUM(NSUInteger, CSJWcMiniappOpenMethod) {
    /// open sdk方式拉起微信小程序
    CSJWcMiniappOpenMethod_SDK = 1,
    /// scheme方式拉起微信小程序
    CSJWcMiniappOpenMethod_Scheme,
};

@interface CSJWCMiniappInfo : NSObject <CSJModelSerialization>
/// 4600 请求拉起微信小游戏scheme链接的地址
@property (nonatomic, copy) NSString *wcMiniappLink;
/// 4600 是否使用scheme拉起小程序 1：走原来转化逻辑 2：是用scheme来去小程序
@property (nonatomic, assign) CSJWcMiniappSkipType wcSkipType;
/// 4600 广告主ID
@property (nonatomic, copy) NSString *advID;
/// 4600 建站页面ID
@property (nonatomic, copy) NSString *siteID;

/// 4700 open sdk注册需要的app id(微信开放平台应用id)
@property (nonatomic, copy) NSString *wcAppID;
/// 4700 open sdk注册需要的universal link
@property (nonatomic, copy) NSString *wcUniversialLink;
/// 4700 通过open sdk拉起微信小游戏请求小程序username, path链接的地址
@property (nonatomic, copy) NSString *wcMiniappSDK;
/// 4700 拉起小程序的方式 1： open sdk  2: scheme
@property (nonatomic, assign) CSJWcMiniappOpenMethod wcOpenMethod;

/// 请求拉起小程序信息地址
/// wc_miniapp_shceme, wc_miniapp_sdk
- (NSString *)wcMiniappSourceURL;

/// 是否是Scheme方式调起小程序
- (BOOL)preferSchemeLinkAction;

/// 是否是Open SDK方式调起小程序
- (BOOL)preferOpenSDKAction;

/// scheme方式拉起起小程序信息是否可用
- (BOOL)validWCMiniappLink;
/// open sdk方式拉起起小程序信息是否可用
- (BOOL)validWCMiniappOpenSDK;
/// open sdk 注册信息是否可用
- (BOOL)validWCMiniappOpenSDKRegisterInfo;
@end

NS_ASSUME_NONNULL_END
