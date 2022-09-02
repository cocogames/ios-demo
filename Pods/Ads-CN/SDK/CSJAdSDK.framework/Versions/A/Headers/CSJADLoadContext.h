//
//  CSJADLoadContext.h
//  CSJAdSDK
//
//  Created by Willie on 2021/1/4.
//

#import <Foundation/Foundation.h>

@class CSJAdSlot, CSJMaterialMeta, CSJADLoadDurationModel, CSJADLoadSplashContext;

NS_ASSUME_NONNULL_BEGIN

/// 集中保存追踪广告加载耗时的过程中所产生的数据的类型
@interface CSJADLoadContext : NSObject

/// 追踪的代码位数据
@property (nonatomic, strong) CSJAdSlot *slot;
/// 追踪的物料数据
@property (nonatomic, strong) CSJMaterialMeta *material;
/// 追踪的加载耗时数据
@property (nonatomic, strong) CSJADLoadDurationModel *loadDurationModel;
/// 追踪的开屏广告相关数据
@property (nonatomic, strong) CSJADLoadSplashContext *splashContext;

@end

NS_ASSUME_NONNULL_END
