//
//  CSJSplashOuterCallTracker.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/11/17.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CSJMaterialMeta;
@class CSJAdSlot;

typedef NS_ENUM(NSInteger,BUSplashAvailableType){
    BUSplashAvailableType_loaclCheckInvalid     = 0,      //物料存储时长超时
    BUSplashAvailableType_serverCheckInvalid    = 1,      //服务端校验不通过
    BUSplashAvailableType_serverCheckValid      = 2       //服务端验证可用
};

@interface CSJSplashOuterCallTracker : NSObject
//外部调用 timeOut 传递开发者时长
+ (void)logOuterCallWithAdSlot:(CSJAdSlot *)adslot timeout:(NSTimeInterval)timeout;
//返回外部调用
+ (void)logOuterCallSendWithAdSlot:(CSJAdSlot *)adslot materialMeta:(CSJMaterialMeta *)materialMeta splashExtraInfoDic:(NSDictionary *)splashExtraInfoDic;
//外部调用无返回
+ (void)logOuterCallNoRspWithAdSlot:(CSJAdSlot *)adslot error:(NSError *)error;
//外部调用无返回增加额外参数
+ (void)logOuterCallNoRspWithAdSlot:(CSJAdSlot *)adslot error:(NSError *)error extraDic:(NSDictionary *)extraDic;
//加载超时
+ (void)logLoadTimeoutWithAdSlot:(CSJAdSlot *)adslot;
//加载素材失败
+ (void)logLoadCreativeErrorWithSlot:(CSJAdSlot *)slot
                        materialMeta:(CSJMaterialMeta *)materialMeta
                            imageUrl:(NSURL *)imageURL
                               error:(NSError *)error;
//物料缓存校验结果上报
+ (void)logLoadMaterialInvalidWithSlot:(CSJAdSlot *)slot
                          materialMeta:(CSJMaterialMeta *)cacheMaterialMeta
                          availabeType:(BUSplashAvailableType)availabeType
                       timeOutDuration:(NSNumber *)timeOutDuration;

// log接口
+ (void)logTimeDiffTag:(NSString *)tag label:(NSString *)label startTime:(CFTimeInterval)startTime materialMeta:(CSJMaterialMeta *)materialMeta;
@end
