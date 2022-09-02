//
//  MSManagerUtils.h
//  MetaSecSDKiOS
//
//  Created by bytedance on 2020/4/28.
//  Copyright © 2020 bytedance. All rights reserved.
//

// 接入文档请查看 https://bytedance.feishu.cn/docs/doccnF0ltvaddAOoRSsFmH8ztBe
// 新接入的业务方，即新的appid必须拉oncall 二次配置授权 https://bytedance.feishu.cn/docs/doccnDH6or8BeKzL5hRw1jxHa9d

#import <Foundation/Foundation.h>
#import "MSConfig.h"
NS_ASSUME_NONNULL_BEGIN

@interface PglMSManagerML : NSObject
+ (instancetype)new __attribute__((unavailable("please use [PglMSManagerML initWithConfig:]")));
- (instancetype)init __attribute__((unavailable("please use [PglMSManagerML initWithConfig:]")));

// PglMSManagerML初始化接口，该接口必须调用，且在appid不变的情况下只能调用一次
- (instancetype)initWithConfig:(PglMSConfigML*)config;

//必填项:deviceid、did，该接口既是设置did的接口，又是一个合规确认的接口。在用户确认隐私合规之前，此接口不可调用，一旦调用会delay xx 秒后触发设备信息采集；但是用户确认隐私合规弹窗后，该接口又必须要调用，以确保安全SDK可以获取到did。具体使用方法可以通过监听did变更的方式来触发，并调用reportForScence接口上报更改，具体见上方的接入文档示例。
- (PglMSManagerML *(^)( NSString* _Nonnull ))setDeviceID;

//tob的必填项，字节内部的app不用理会
- (PglMSManagerML *(^)( NSString* _Nonnull ))setBDDeviceID;

//必填项，PglMSConfigML配置更改接口:installid,如果初始化时在新增设备上没有获取到或者installid有更新，要求通过监听的方式必须调用该接口，并调用 reportForScence接口上报更改，具体见上方的接入文档示例。
- (PglMSManagerML *(^)( NSString* _Nonnull ))setInstallID;

//可选项，PglMSConfigML配置更改接口:idfa,不主动采集，如果业务方有采集或者idfa异步获取的，可以通过该接口填入，并调用 reportForScence接口,上报更改
- (PglMSManagerML *(^)( NSString* _Nonnull ))setIDFA;

//必填项，PglMSConfigML配置更改接口:用户组件TTAccountSDK 生成的sessionid,非uid,当前uid登录时生成的session,如果初始化时没有获取到可以不设置该接口。但是后续用户有登入登出行为导致sessionid有更新，后续要求必须通过 PglMSManagerML 再次填入
- (PglMSManagerML *(^)( NSString* _Nonnull ))setSessionID;

//必填项，PglMSConfigML配置更改接口:安装渠道
- (PglMSManagerML *(^)( NSString* _Nonnull ))setChannel;

//选填项:采集模式变化时回调该接口
- (PglMSManagerML *(^)( MSMLCollectMode ))setMode;



/**
* @brief setCustomInfo()
*
* @param  dic a NSDictionary * that the key and the value must be NSString* ,otherwise other types will be dropped.
*
* @return PglMSManagerML *.
*/
- (PglMSManagerML *(^)( NSDictionary<NSString* , NSString*>* _Nonnull ))setCustomInfo;

//获取PglMSManagerML 初始化后的示例副本，如果没有调用i- (instancetype)initWithConfig:(PglMSConfigML*)config 接口初始化或者初始化没有完成，则返回nil
//如果初始化时候，不方便给下游传递 msManager 实例，可以通过该获取业务实例的副本，一样可以用来上报风险
//PglMSManagerML* msManagerCopy = [[PglMSManagerML get:@"6666"];
//[msManagerCopy reportForScene:@"SCENE_NAME"]; // 填写具体场景名称，便于后期风险分析
+ (instancetype)get:(NSString*) appID;

//主动上报风险接口，scene 为任意长度大于0 的NString* 的有场景含义的任意字符串，例如 @"hardboot"、@"login"、@"order" 等等
- (void) reportForScene:(NSString* _Nonnull)scene;

@end

NS_ASSUME_NONNULL_END
