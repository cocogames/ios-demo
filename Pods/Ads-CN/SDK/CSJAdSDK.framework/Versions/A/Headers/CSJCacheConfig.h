//
//  CSJCacheConfig.h
//  CSJCacheConfig
//
//  Created by zth on 2021/9/18.
//


/**承载SDK 内存各类存储的阈值获取  对线上媒体使用体验可能造成负向影响的阈值, 建议通过server 下发配置*/
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJCacheConfig : NSObject


+ (instancetype)defaultConfig;
/**销毁单例*/
- (void)destroyConfig;

+(instancetype) alloc __attribute__((unavailable("replace with 'defaultConfig'")));

+(instancetype) new __attribute__((unavailable("replace with 'defaultConfig'")));

-(instancetype) copy __attribute__((unavailable("replace with 'defaultConfig'")));

-(instancetype) mutableCopy __attribute__((unavailable("replace with 'defaultConfig'")));

/// MARK: BU_SDImageCacheConfig 设置缓存存储的最大数目 默认值为6
/// @Warning 云控返回数据<默认值将无效.
- (void)setUpBUSDimageCacheMaxMemoryCount;

/// MARK: BU_SDImageCacheConfig 设置缓存存储的最大内存数值 默认值为24M
/// @Warning 云控返回数据<默认值将无效
- (void)setUpBUSDimageCacheMaxMemoryCost;


@end

NS_ASSUME_NONNULL_END
