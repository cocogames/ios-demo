//
//  CSJPlayableAdHeader.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2021/3/2.
//  Copyright © 2021 bytedance. All rights reserved.
//

#ifndef CSJPlayableAdHeader_h
#define CSJPlayableAdHeader_h

#if __has_include(<BUPlayableAdKit/BUPlayableAdKit.h>)
// 走组件依赖
#import <BUPlayableAdKit/BUPlayableAdKit.h>
#else
// 走源码集成
#import "BUPlayableAdKit.h"
#endif


NS_ASSUME_NONNULL_BEGIN

// 组件依赖api未暴露，通过运行时去调用
@interface BUPlayableAd (CSJ)

- (NSDictionary *)csj_excuteJSBMethod:(NSString *)methodName params:(NSDictionary *)params;
- (BOOL)csj_responseToJSBMethod:(NSString *)methodName;
- (void)csj_fireEvent:(NSString *)eventName params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END


#endif /* BUPlayableAdHeader_h */
