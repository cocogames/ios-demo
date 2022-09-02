//
//  CSJWebViewSetting.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/18.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJWebViewSetting : NSObject
//拦截加载本地资源使用的.添加允许跨域访问的响应头
+ (NSDictionary *)buildRequestHeadersWithUrl:(NSURL *)requestUrl;

/**
 设置过滤列表.需要尽早设置。
 例如：application:didFinishLaunchingWithOptions:方法里

 @param prefixUrlKey prefixUrlKey
 @param prefixUrl prefixUrl
 */
+ (void)registerPrefix:(NSString *)prefixUrlKey prefixUrl:(NSString *)prefixUrl;

+ (NSString *)getRegisterPrefix:(NSString *)prefixUrlKey;

@end

NS_ASSUME_NONNULL_END
