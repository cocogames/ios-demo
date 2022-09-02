//
//  CSJVideoPrefetchManager+Ad.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/12/14.
//


#import "CSJNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface BUVideoPrefetchManager (Ad)

// 使用广告结构体加载视频
- (void)csj_prefetchWithNativeAd:(CSJNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
