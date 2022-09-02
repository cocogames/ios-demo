//
//  CSJSDImageCacheFactory.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    BUSDImageCacheTypeDefault,//默认的 BU_SDImageCache.sharedImageCache
} BUSDImageCacheType;

@interface CSJSDImageCacheFactory : NSObject

+ (BU_SDImageCache *)imageCacheWithType:(BUSDImageCacheType)type;

@end

NS_ASSUME_NONNULL_END
