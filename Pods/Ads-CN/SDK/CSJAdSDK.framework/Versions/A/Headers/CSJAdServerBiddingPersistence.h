//
//  CSJAdServerBiddingPersistence.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/2/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUAdServerBiddingPersistenceType) {
    /// 预请求
    BUAdServerBiddingPersistencePreFetch                    = 0,
    /// 新插屏预请求
    BUAdServerBiddingPersistenceInterstitialPreFetch        = 1,
    /// 预缓存
    BUAdServerBiddingPersistencePreCache                    = 2,
};

@class BUPersistence;
@protocol BUPersistenceProtocol;
@interface CSJAdServerBiddingPersistence : NSObject
+ (id<BUPersistenceProtocol>)biddingPersistenceWithSlot:(CSJAdSlot *)slot type:(BUAdServerBiddingPersistenceType)type;
@end

@interface CSJAdServerBiddingBannerPersistence : CSJAdServerBiddingPersistence

@end

@interface CSJAdServerBiddingInterstitialPersistence : CSJAdServerBiddingPersistence

@end

@interface CSJAdServerBiddingFeedPersistence : CSJAdServerBiddingPersistence

@end

@interface CSJAdServerBiddingDrawPersistence : CSJAdServerBiddingPersistence

@end

@interface CSJAdServerBiddingPasterPersistence : CSJAdServerBiddingPersistence

@end

@interface CSJAdServerBiddingSplashPersistence : CSJAdServerBiddingPersistence

@end

@interface CSJAdServerBiddingRewardPersistence : CSJAdServerBiddingPersistence

@end

@interface CSJAdServerBiddingFullScreenPersistence : CSJAdServerBiddingPersistence

@end

NS_ASSUME_NONNULL_END
