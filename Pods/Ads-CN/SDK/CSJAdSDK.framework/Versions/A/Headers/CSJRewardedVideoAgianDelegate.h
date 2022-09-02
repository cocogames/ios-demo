//
//  CSJRewardedVideoAgianDelegate.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2021/5/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^RewardAgainSuccessCompletion)(void);
typedef void (^RewardAgainFailCompletion)(void);

@protocol CSJRewardedVideoAgianDelegate <NSObject>

- (instancetype)initWithRewardedVideoAd:(id)rewardAd;
- (void)loadRewardAgianWithSuccess:(RewardAgainSuccessCompletion)success fail:(RewardAgainFailCompletion)fail;
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
