//
//  CSJAdSDKManager+Track.h
//  CSJAdSDK
//
//  Created by Willie on 2020/12/14.
//

#import <CSJAdSDK/CSJAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJAdSDKManager (Track)

+ (void)trackInit;
+ (void)trackWillEnterForeground;
+ (void)trackDidEnterBackground;

+ (void)trackServerBiddingWithEvent:(NSString *)eventType info:(NSDictionary * _Nullable)trackInfo extra:(NSDictionary * _Nullable)eventExtra;

+ (void)trackMiniappWithEvent:(NSString *)eventType info:(NSDictionary * _Nullable)trackInfo extra:(NSDictionary * _Nullable)eventExtra;
@end

NS_ASSUME_NONNULL_END
