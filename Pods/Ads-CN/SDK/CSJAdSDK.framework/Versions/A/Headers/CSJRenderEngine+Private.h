//
//  CSJRenderEngine+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/13.
//

#import "CSJRenderEngine.h"
#import "CSJRenderStrategy.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJRenderEngine ()
@property (nonatomic, strong, readwrite) CSJRenderResultModel *renderResultModel;

// 最后触发成功/失败回调的渲染策略，一定会有值的。因为无兜底渲染策略也是一种策略
@property (nonatomic, strong, readwrite) CSJRenderStrategy *resultRenderStrategy;

#pragma mark - Debug Info
- (NSString *)logKeyName;
@end

NS_ASSUME_NONNULL_END
