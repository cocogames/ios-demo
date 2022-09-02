//
//  CSJAdSDKProtocolDefines.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/9/2.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef BUAdSDKProtocolDefines_h
#define BUAdSDKProtocolDefines_h

NS_ASSUME_NONNULL_BEGIN
@protocol CSJAdLoggerProtocol <NSObject>

- (void)trackEvent:(NSString *)event params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
#endif /* BUAdSDKProtocolDefines_h */
