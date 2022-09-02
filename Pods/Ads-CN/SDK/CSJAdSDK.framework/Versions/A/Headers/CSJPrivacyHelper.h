//
//  CSJPrivacyHelper.h
//  AFNetworking
//
//  Created by Willie on 2021/9/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 封装隐私数据获取过程的类
@interface CSJPrivacyHelper : NSObject

/// 获取纬度
/// 优先从 `CSJAdSDKConfiguration.configuration.privacyProvider` 中获取
/// 其次从 `[CSJSDKAuxiliary bu_getInformation:CSJ_Auxiliary_latitude]` 中获取
+ (nullable NSNumber *)latitude;

/// 获取经度
/// 优先从 `CSJAdSDKConfiguration.configuration.privacyProvider` 中获取
/// 其次从 `[CSJSDKAuxiliary bu_getInformation:CSJ_Auxiliary_longitude]` 中获取
+ (nullable NSNumber *)longitude;

@end

NS_ASSUME_NONNULL_END
