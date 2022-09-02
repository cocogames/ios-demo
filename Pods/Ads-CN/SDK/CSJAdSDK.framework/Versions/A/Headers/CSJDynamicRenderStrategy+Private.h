//
//  CSJDynamicRenderStrategy+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/5.
//

#import "CSJDynamicRenderStrategy.h"
#import "CSJRenderInteractionModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicRenderStrategy ()


#pragma mark - safeDelegate

- (NSTimeInterval)safeDelegate_renderTimeoutInDynamicRenderStrategy:(CSJDynamicRenderStrategy *)dynamicRenderStrategy;
- (NSInteger)safeDelegate_playPercentInDynamicRenderStrategy:(CSJDynamicRenderStrategy *)dynamicRenderStrategy;

- (void)safeDelegate_dynamicRenderStrategy:(CSJDynamicRenderStrategy *)dynamicRenderStrategy reportError:(NSError *)error;
- (void)safeDelegate_dynamicRenderStrategy:(CSJDynamicRenderStrategy *)dynamicRenderStrategy reportLabel:(NSString *)label;

#pragma mark - Protected


- (NSDictionary *)_pro_handleRenderDidFinishWithDictionary:(NSDictionary *)js2NativeParams error:(NSError **)error;


#pragma mark - jsCallNative
- (void)jsCallNative_showSKOverlay;

- (CSJRenderInteractionModel *)jsCallNative_type:(BURenderInteractionType)type params:(NSDictionary * _Nullable)params;

- (void)addReopenSKOverlayObserver;


#pragma mark - Transform

@end

NS_ASSUME_NONNULL_END
