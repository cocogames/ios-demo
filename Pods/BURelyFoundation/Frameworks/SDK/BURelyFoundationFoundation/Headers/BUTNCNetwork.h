//
//  BUTNCNetwork.h
//  BUAdSDK
//
//  Created by Siwant on 2019/12/17.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BUNetworkRequest;
@class BUTNCServiceConfig;

typedef void (^BUAdGetDomainsCompletion)(NSDictionary *_Nullable domains);

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface BUTNCNetwork : NSObject

+ (instancetype)sharedInstance;

/// TNC容灾域名。key: 原host, value: 容灾host。eg. { @"is.snssdk.com": @"is-hl.snssdk.com" }
- (NSDictionary *)domainsWithAppKey:(NSString *)appKey;

/// TNC容灾域名的失败次数，单个host失败次数达到3次则不使用该容灾域名。key: 容灾host, value: 次数。eg. { @"is-hl.snssdk.com": @(3) }
@property (nonatomic, strong, readonly) NSMutableDictionary *failDomains;

/// 记录失败的容灾域名次数
- (BOOL)recordFailCountDomain:(BUNetworkRequest *)networkRequest;

/**
 TNC 切流获取域名
*/
- (void)getDomainsWithConfig:(BUTNCServiceConfig *)config andCompletion:(__nullable BUAdGetDomainsCompletion)completion;

@end

NS_ASSUME_NONNULL_END
