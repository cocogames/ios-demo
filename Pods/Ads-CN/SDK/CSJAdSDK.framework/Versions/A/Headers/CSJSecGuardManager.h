//
//  CSJSecGuardManager.h
//  CSJAdSDK
//
//  Created by bytedance_yuanhuan on 2018/8/13.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "BUCommonMacros.h"

/*
 device_id 依赖广告物料接口
 dc 依赖setting接口
 device_id 和 dc 同时存在进行SecSDK初始化
 */

@interface CSJSecGuardManager : NSObject
/// 3300 add
@property (nonatomic, assign) BOOL initialized;


+ (instancetype)sharedInstance;

///3300 add 初始化sdk
- (void)setupSecSDK;
- (void)sendWithDid:(NSString *)did;
/**
 * 对bodyMD5Hex+deviceID+ts加签，不要在意名字
 * 原始数据格式：bodyMD5Hex_deviceID_ts
 * @param bodyMD5Hex post请求body的MD5 HEXString
 * @return 加签后的hexStr，拼接到请求里
 * @description 如果接入方自己做服务，那参数传什么都可以
 */
- (NSString *)bodyEncry:(NSString *)bodyMD5Hex;
- (NSDictionary *)doHttpReqSignByUrl:(NSString *)urlString body:(NSData *)bodyData;

@end
