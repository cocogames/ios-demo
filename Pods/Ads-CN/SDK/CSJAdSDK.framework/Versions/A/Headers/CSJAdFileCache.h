//
//  CSJAdFileCache.h
//  AFNetworking
//
//  Created by Rush.D.Xzj on 2021/2/25.
//

#import <Foundation/Foundation.h>
#import "CSJAdFileCacheConfig.h"

NS_ASSUME_NONNULL_BEGIN



@interface CSJAdFileCache : NSObject

@property (nonatomic, strong, readonly) CSJAdFileCacheConfig *cacheConfig;

#pragma mark - init & dealloc
- (instancetype)initWithCacheConfig:(CSJAdFileCacheConfig *)cacheConfig;


#pragma mark - Public
- (void)setData:(NSData *)data withKey:(NSString *)key;
- (void)existWithKey:(NSString *)key completionBlock:(void(^)(BOOL))completionBlock;
- (void)dataWithKey:(NSString *)key completionBlock:(void(^)(NSData *))completionBlock;

- (void)clearAllCache;


#pragma mark - Class Method
+ (void)setupParentDirectoryName:(NSString *)directoryName;


@end

NS_ASSUME_NONNULL_END
