//
//  CSJSDKAuxiliary+LocalCache.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/8/28.
//  Copyright © 2020 bytedance. All rights reserved.
//
#import "CSJSDKAuxiliary.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJSDKAuxiliary (LocalCache)
///CSJAdDeepLinkActionManager
+ (NSString *)bu_TrackInfoDicKey;
///dpl跳转时间戳持久化key
+ (NSString *)bu_LastDeeplinkJumpTimeKey;
///CSJAdSDKManager
+ (NSString *)bu_IS_GDPR_USER_key;
///CSJAdSDKManager
+ (NSString *)bu_GDPR_key;
+ (NSString *)bu_themeStatus_key;
///CSJAdSDKManager
+ (NSString *)bu_CONSENT_URL_key;
///CSJAdSDKManager
+ (NSString *)bu_DY_ENGINE_URL_key;
///CSJAdNetworkRequest
+ (NSString *)bu_NET_CONFIG_TNC_CMD;
///CSJAdNetworkRequest
+ (NSString *)bu_NET_CONFIG_TNC_VERSION;
///CSJUSettingService
+ (NSString *)bu_SettingKey;

+ (NSString *)bu_fileCacheParentDirectoryName;
@end

NS_ASSUME_NONNULL_END
