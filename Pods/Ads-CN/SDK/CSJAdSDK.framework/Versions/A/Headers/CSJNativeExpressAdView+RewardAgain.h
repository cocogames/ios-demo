//
//  CSJNativeExpressAdView+RewardAgain.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/5/12.
//

#import <CSJAdSDK/CSJAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJNativeExpressAdView (RewardAgain)
- (void)showRewardAgainEntrance;

/// 4600 激励视频“再看一个”入口前置事件
/// @param params jsb回调参数
- (void)jsCallNative_showRewardPlayAgainWithParams:(NSDictionary *)params;
@end

NS_ASSUME_NONNULL_END
