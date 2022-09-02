//
//  CSJDynamicSDKAnalysisRuler.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicLayoutUnitModel.h"

NS_ASSUME_NONNULL_BEGIN

// 前端ruler.ts
@interface CSJDynamicSDKAnalysisRuler : NSObject


/// !!!!!!!!!!! ruler 完全ok
- (void)resetCache;

- (CGSize)computeBrickSize:(CSJDynamicLayoutUnitModel *)brick limit:(CGSize)limit;

- (CGSize)getBrickSize:(CSJDynamicLayoutUnitModel *)brick;

- (CGSize)getGroupSize:(NSArray <CSJDynamicLayoutUnitModel *> *)group;
@end

NS_ASSUME_NONNULL_END
