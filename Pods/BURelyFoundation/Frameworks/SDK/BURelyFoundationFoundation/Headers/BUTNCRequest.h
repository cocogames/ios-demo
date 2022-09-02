//
//  BUTNCRequest.h
//  BUAdSDK
//
//  Created by Siwant on 2019/12/19.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "BUNetworkRequest.h"

NS_ASSUME_NONNULL_BEGIN

/// 获取TNC切流备用域名
@interface BUTNCRequest: BUNetworkRequest

+ (instancetype)requestWithDomains:(NSArray<NSString *> *)domains url:(NSString *)url andParams:(NSDictionary *)params;

/// 记录三个getdomains域名中请求失败的case，下次使用其他可用的域名
- (void)recordFailDomain:(BUNetworkRequest *)networkRequest;
@end

NS_ASSUME_NONNULL_END
