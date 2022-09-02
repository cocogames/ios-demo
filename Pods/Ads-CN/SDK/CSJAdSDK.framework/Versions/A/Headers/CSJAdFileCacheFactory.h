//
//  CSJAdFileCacheFactory.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/25.
//

#import <Foundation/Foundation.h>

#import "CSJAdFileCache.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, BUAdFileCacheType) {
    BUAdFileCacheType_Splash,
    BUAdFileCacheType_NoSplash, // 4200 开始支持banner和feed
};



@interface CSJAdFileCacheFactory : NSObject

+ (CSJAdFileCache *)fileCacheWithFileCacheType:(BUAdFileCacheType)fileCacheType;


+ (void)clearAllCache;

@end

NS_ASSUME_NONNULL_END
