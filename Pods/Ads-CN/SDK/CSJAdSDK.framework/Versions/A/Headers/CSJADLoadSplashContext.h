//
//  CSJADLoadSplashContext.h
//  CSJAdSDK
//
//  Created by Willie on 2021/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 保存追踪广告加载耗时的过程中开屏广告相关的数据
@interface CSJADLoadSplashContext : NSObject

/// 最终给出的开屏广告的加载类型，`cache_ad` 给出的是预加载的广告，`real_time_ad` 给出的是实时广告
@property (nonatomic, copy) NSString *splashFinalType;

@property (nonatomic, assign) NSInteger renderControl; //服务端下发渲染策略

@property (nonatomic, assign) NSInteger renderSequence; //服务端下发渲染策略

@property (nonatomic, assign) NSInteger realRenderSequence; //实际渲染策略
/// 是否展示点睛
@property (nonatomic, assign) BOOL isZoomOut;

/// 是否是预加载
@property (nonatomic, assign) BOOL isPreload;

@end

NS_ASSUME_NONNULL_END
