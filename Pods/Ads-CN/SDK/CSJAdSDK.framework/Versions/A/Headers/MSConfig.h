//
//  MSConfig.h
//  MetaSecSDKiOS
//
//  Created by bytedance on 2020/4/28.
//  Copyright © 2020 bytedance. All rights reserved.
//
// 接入文档请查看 https://bytedance.feishu.cn/docs/doccnF0ltvaddAOoRSsFmH8ztBe
// 新接入的业务方，即新的appid必须拉oncall 二次配置授权 https://bytedance.feishu.cn/docs/doccnDH6or8BeKzL5hRw1jxHa9d


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MSMLClientType) {
    MS_ML_CLIENT_TYPE_UNKNOWN = -1,
    MS_ML_CLIENT_TYPE_INHOUSE = 0,
    MS_ML_CLIENT_TYPE_INNER = 0,
    MS_ML_CLIENT_TYPE_BUSINESS = 1
};
typedef NS_ENUM(NSInteger, MSMLCollectMode) {
    
    COLLECT_MODE_ML_TEEN            = 280,      // 国内青少年模式
    COLLECT_MODE_ML_MINIMIZE        = 290,      // 国内最小化权限模式
    COLLECT_MODE_FINANCE            = 300,      // 财经特有模式，其他业务线不要用
    COLLECT_MODE_DEFAULT            = 99999     // 国内默认正常模式
};

@interface PglMSConfigML : NSObject

+ (instancetype)new __attribute__((unavailable("please use [initWithAppID:License:] or [initWithSDKID:SubAppID:License:]")));
- (instancetype)init __attribute__((unavailable("please use [initWithAppID:License:] or [initWithSDKID:SubAppID:License:]")));

// PglMSConfigML配置初始化接口，app初始化使用该接口，license申请见操作文档 https://bytedance.feishu.cn/docs/doccny0YGd9wpqwRCvKdXSFJuag#
// - (instancetype)initWithAppID: (NSString* _Nonnull)appID License:(NSString * _Nonnull)licenseStr; 适配国内合规，请使用下面接口
- (instancetype)initWithAppID: (NSString* _Nonnull)appID License:(NSString * _Nonnull)licenseStr Mode:(MSMLCollectMode)mode;

// PglMSConfigML配置初始化接口，中台SDK初始化使用该接口，license申请见操作文档 https://bytedance.feishu.cn/docs/doccny0YGd9wpqwRCvKdXSFJuag#
// - (instancetype)initWithSDKID: (NSString* _Nonnull)sdkID SubAppID:(NSString * _Nonnull)subAppID License:(NSString * _Nonnull)licenseStr; 适配国内合规，请使用下面接口
- (instancetype)initWithSDKID: (NSString* _Nonnull)sdkID SubAppID:(NSString * _Nonnull)subAppID License:(NSString * _Nonnull)licenseStr Mode:(MSMLCollectMode)mode;

//必填项:客户端类型枚举值，MS_ML_CLIENT_TYPE_INHOUSE（字节开发的app，字节的同学填这个）、MS_ML_CLIENT_TYPE_BUSINESS（字节的外部客户，其他公司开发的app）
- (PglMSConfigML *(^)( MSMLClientType))     setClientType;

 //慎重 必填项:deviceid、did，该接口既是设置did的接口，又是一个合规确认的接口。一旦调用并且传入的did有值，会delay xx 秒后触发设备信息采集。所以请先判断用户是否已经同意隐私协议，在用户确认隐私协议合规之前，此接口不可调用；在非新增设备上，用户如果已经同意了隐私协议，该接口必须要调用。
- (PglMSConfigML *(^)( NSString* _Nonnull ))setDeviceID;

//tob的必填项，字节内部的app不用理会
- (PglMSConfigML *(^)( NSString* _Nonnull ))setBDDeviceID;

//必填项:installid,如果新增设备初始化时没有获取到可以不填
- (PglMSConfigML *(^)( NSString* _Nonnull ))setInstallID;

//可选项，PglMSConfigML配置更改接口:idfa,不主动采集，如果业务方有采集或者idfa异步获取的，后续要求可以通过 PglMSManagerML 再次填入，并调用 reportForScence接口上报更改，有助于分析作弊case
- (PglMSConfigML *(^)( NSString* _Nonnull ))setIDFA;

//可选项:用户组件TTAccountSDK 生成的sessionid,非uid,当前uid登录时生成的session,如果初始化时没有获取到可以不设置该接口。但是后续用户有登入登出行为导致sessionid有更新，后续要求必须通过 PglMSManagerML 再次填入
- (PglMSConfigML *(^)( NSString* _Nonnull ))setSessionID;

//必填项:安装渠道
- (PglMSConfigML *(^)( NSString* _Nonnull ))setChannel;

/**
* @brief setCustomInfo()
*
* @param  dic a NSDictionary * that the key and the value must be NSString* ,otherwise other types will be blocked.
*
* @return PglMSConfigML *.
*/
- (PglMSConfigML *(^)( NSDictionary<NSString* , NSString*>* _Nonnull dic))setCustomInfo;
- (PglMSConfigML *(^)(NSString* _Nonnull key, NSString* _Nonnull val)) addAdvanceInfo;

@end

NS_ASSUME_NONNULL_END
