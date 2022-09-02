//
//  CSJDynamicSDKAnalysisFlex.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/7/9.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicLayoutUnitModel.h"
#import "CSJDynamicSDKFlexiableInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicSDKAnalysisFlex : NSObject

+ (NSArray <CSJDynamicSDKFlexiableInfoModel *> *)flexiableAdjustSize:(CGFloat)targetSize originalValues:(NSArray <CSJDynamicSDKFlexiableInfoModel *> *)originalValues;

+ (CGFloat)flexUnitSize:(CGFloat)num;

@end

NS_ASSUME_NONNULL_END
