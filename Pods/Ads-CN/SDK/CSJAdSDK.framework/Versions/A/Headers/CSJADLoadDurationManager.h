//
//  CSJADLoadDurationManager.h
//  CSJAdSDK
//
//  Created by Willie on 2020/12/28.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CSJAdSlot, CSJADLoadContext;

/// APP 当前的启动类型
typedef enum : NSUInteger {
    BUAPPActiveTypeColdLaunch, ///< 冷启动
    BUAPPActiveTypeHotLaunch,  ///< 热启动
} BUAPPActiveType;

NS_ASSUME_NONNULL_BEGIN

/// 用来管理在追踪广告加载耗时的过程中所产生的数据
@interface CSJADLoadDurationManager : NSObject

/// 获取当前 APP 的启动类型，需要先调用 `startTrackAPPActiveType`
@property (nonatomic, assign, readonly) BUAPPActiveType APPActiveType;
/// 开始追踪 APP 的启动类型
- (void)startTrackAPPActiveType;
/// 结束追踪 APP 的启动类型
- (void)stopTrackAPPActiveType;

/// 获取单例
+ (instancetype)sharedManager;

/// 为指定的 slot 创建一个 CSJADLoadContext 对象并交由 CSJADLoadDurationManager 管理
/// @param slot 需要追踪的 slot 对象
- (void)createADLoadContextWithSlot:(CSJAdSlot *)slot;

/// 根据指定的 slot 获取对应的 CSJADLoadContext 对象
/// @param slot 需要追踪的 slot 对象
- (nullable CSJADLoadContext *)ADLoadContextWithSlot:(CSJAdSlot *)slot;

/// 移除指定的 slot 获取对应的 CSJADLoadContext 对象
/// @param slot 需要追踪的 slot 对象
- (void)removeADLoadContextWithSlot:(CSJAdSlot *)slot;

@end

NS_ASSUME_NONNULL_END
