//
//  CSJAdSDKManager+CSJToken.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/2/18.
//

#import <CSJAdSDK/CSJAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJAdSDKManager (BUToken)
+ (nullable NSDictionary *)pbu_ServerBiddingPreFetchWithSlot:(CSJAdSlot *)slot requestID:(NSString *)requestID;

+ (nullable NSDictionary *)pbu_ServerBiddingPreCacheWithSlot:(CSJAdSlot *)slot;
@end

NS_ASSUME_NONNULL_END
