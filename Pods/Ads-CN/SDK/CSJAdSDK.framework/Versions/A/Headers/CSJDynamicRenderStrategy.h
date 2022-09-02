//
//  CSJDynamicRenderStrategy.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/3.
//

#import <Foundation/Foundation.h>
#import "CSJRenderStrategy+Private.h"
#import "CSJRenderResultModel.h"
#import "CSJRenderInteractionModel.h"

NS_ASSUME_NONNULL_BEGIN



typedef NS_ENUM(NSInteger, BUExpressRenderDidFinishSource) {
    BUExpressRenderDidFinishSourceJSBridge1,            // JSBridge1
    BUExpressRenderDidFinishSourceJSBridge3,            // JSBridge3
    BUExpressRenderDidFinishSourceDynamic,              // 兜底动态布局
};

@class CSJDynamicRenderStrategy;

@protocol BUDynamicRenderStrategyDelegate <CSJRenderStrategyDelegate>

@optional


/// renderEngine透传给容器View
- (NSTimeInterval)renderTimeoutInDynamicRenderStrategy:(CSJDynamicRenderStrategy *)dynamicRenderStrategy;
- (NSInteger)playPercentInDynamicRenderStrategy:(CSJDynamicRenderStrategy *)dynamicRenderStrategy;
- (void)dynamicRenderStrategy:(CSJDynamicRenderStrategy *)dynamicRenderStrategy reportError:(NSError *)error;
- (void)dynamicRenderStrategy:(CSJDynamicRenderStrategy *)dynamicRenderStrategy reportLabel:(NSString *)label;

@end

// 动态渲染
@interface CSJDynamicRenderStrategy : CSJRenderStrategy



- (void)render;


@end

NS_ASSUME_NONNULL_END
