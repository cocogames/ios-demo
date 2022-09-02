//
//  CSJAppStoreTracker.h
//  BUAppStore
//
//  Created by Siwant on 2018/9/10.
//

#import <Foundation/Foundation.h>
#import "CSJAdSDKDefines+Private.h"
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, BUAdOpenAppStoreType) {
    BUAdOpenAppStoreTypeSKStore = 1,
    BUAdOpenAppStoreTypeOpenURL = 2,
};

@interface CSJAppStoreTracker : NSObject

/// AppStore预加载打点方法
/// @param event 打点tag
/// @param label 打点label
/// @param appleId 应用商店appID
/// @param storeOpenType BUAdOpenAppStoreType 不上传就传nil
/// @param adModel <CSJAd>
/// @param params params
+ (void)trackWithEvent:(NSString *)event
                 label:(NSString *)label
               appleID:(NSString *)appleId
         storeOpenType:(NSNumber *_Nullable)storeOpenType
               adModel:(nullable id<CSJAd>)adModel
            extraParam:(nullable NSDictionary *)params;

@end
NS_ASSUME_NONNULL_END
