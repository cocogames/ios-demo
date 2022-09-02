//
//  CSJNetInfoHelperProxy.h
//  CSJAdSDK
//
//  Created by Willie on 2020/8/28.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJFoundationProxy.h"


NS_ASSUME_NONNULL_BEGIN

@interfaceProxy(CSJNetInfoHelper)

+ (nullable NSString *)bu_userAgentString;

/// 网络连接状态的字符串描述
+ (NSString *)GetNetWorkType;

+ (BUNetWorkTypeCode)GetNetWorkTypeCode;

/// 获取mobileCountryCode
+ (nullable NSString *)carrierMCC;

/// 获取mobileNetworkCode
+ (nullable NSString *)carrierMNC;

/// 获取IP地址
+ (nullable NSDictionary *)bu_getIPAddresses;

/**
 *  @param preferIPv4 是否ipv4格式
 *  @return ip地址
 */
+ (NSString *)bu_getIPAddress:(BOOL)preferIPv4;

/**
 *  @param ipAddresses 获取的所有ip地址包含(ipv4,ipv6)
 *  @return ip地址
 */
+ (NSString *)bu_getIPv4Address:(NSDictionary *)ipAddresses;


/**
 *  @param ipAddresses 获取的所有ip地址包含(ipv4,ipv6)
 *  @return ip地址
 */
+ (NSString *)bu_getIPv6Address:(NSDictionary *)ipAddresses;
/// host
//+ (nullable NSString*)bu_addressOfHost:(nullable NSString *)host;

@end

NS_ASSUME_NONNULL_END
