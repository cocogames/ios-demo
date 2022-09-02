//
//  CSJDynamicRenderTemplateStrategy.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/3.
//

#import "CSJDynamicRenderStrategy.h"

NS_ASSUME_NONNULL_BEGIN




// 动态渲染->模板渲染
@interface CSJDynamicRenderTemplateStrategy : CSJDynamicRenderStrategy
- (void)render_really;

- (void)reportExpressAdShowWithBool:(BOOL)flag;

@end

NS_ASSUME_NONNULL_END
