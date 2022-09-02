//
//  CSJNativeExpressRewardedVideoAdViewController.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/8/7.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
@class CSJNativeExpressRewardedVideoAdView;
@class CSJNativeAd;
@class CSJAdSlot;
@class CSJDislikeContext;

NS_ASSUME_NONNULL_BEGIN

@protocol CSJNativeExpressVideoAdDelegate <NSObject>
@optional
- (void)nativeExpressVideoAdDidPlayFinishWithError:(nullable NSError *)error;
- (void)nativeExpressVideoAdDidClickSkip;
- (void)nativeExpressVideoAdEndcardWillClose;
- (void)nativeExpressVideoAdEndcardDidClose;
/// native express video ad reward verify: include C2C and S2S methods .
- (void)nativeExpressVideoAdServerRewardDidSucceedVerify:(BOOL)verify;
- (void)nativeExpressVideoAdServerRewardDidFailWithError:(nullable NSError *)error;
@end

@interface CSJNativeExpressRewardedVideoAdViewController : UIViewController
@property (nonatomic, weak) id<CSJNativeExpressVideoAdDelegate> rewardedVideoAd;
@property (nonatomic, assign) BOOL isRewardedVideo;
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, copy) dispatch_block_t purePlayableClickBlock;


- (instancetype)initWithNativeExpressAdView:(CSJNativeExpressRewardedVideoAdView *)expressAdView purePlayableNativeAd:(CSJNativeAd *)purePlayableNativeAd;

@end

NS_ASSUME_NONNULL_END
