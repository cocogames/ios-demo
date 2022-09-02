//
//  CSJSplashViewModel+Bidding.h
//  CSJAdSDK
//
//  Created by ByteDance on 2022/6/19.
//

#import "CSJSplashViewModel.h"
#import "CSJNativeAdsManager.h"
#import "CSJNativeAdsManager+Private.h"
#import "CSJAdSDKManager+Private.h"
#import "CSJAdClientBiddingHandle.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJSplashViewModel (Bidding)<CSJNativeAdsManagerDelegate>

- (CSJAdClientBiddingHandle *)getClientBiddingHandle;

- (void)setAdMarkup:(NSString *)adm;
- (NSString *)biddingToken;

- (void)setPrice:(nullable NSNumber*)auctionPrice;
- (void)win:(nullable NSNumber*)auctionBidToWin;
- (void)loss:(nullable NSNumber*)auctionPrice lossReason:(nullable NSString*)lossReason winBidder:(nullable NSString*)winBidder;


@end

NS_ASSUME_NONNULL_END
