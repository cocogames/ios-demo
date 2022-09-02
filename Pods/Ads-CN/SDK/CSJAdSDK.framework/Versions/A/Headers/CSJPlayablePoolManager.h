//
//  CSJPlayablePoolManager.h
//  CSJAdSDK
//
//  Created by admin on 2021/6/21.
//

#import <Foundation/Foundation.h>
#import "CSJRewardedVideoWebViewController.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJPlayablePoolManager : NSObject
@property (nonatomic, assign) NSInteger maxCache;
+ (instancetype)sharedInstance;

/// 获取物料对应的key
/// @param meta 物料
+ (NSString *)keyForMaterial:(CSJMaterialMeta *)meta;

/// 获取预渲染的pl对象
/// @param key key
- (CSJRewardedVideoWebViewController * _Nullable)playableForKey:(NSString *)key;


/// 预渲染方法
/// @param material 物料
/// @param slot 广告slot
/// @param key key
- (void)render:(CSJMaterialMeta *)material slot:(CSJAdSlot *)slot forKey:(NSString *)key;


/// 获取渲染进度的埋点数据
/// @param material 物料
- (NSDictionary *)getRenderStatusFor:(CSJMaterialMeta *)material;
@end

NS_ASSUME_NONNULL_END
