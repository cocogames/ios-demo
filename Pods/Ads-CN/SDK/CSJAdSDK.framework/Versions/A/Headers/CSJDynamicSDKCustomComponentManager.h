//
//  CSJDynamicSDKCustomComponentManager.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/8/3.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicLayoutUnitModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicSDKCustomComponentManager : NSObject

- (id)initWithRendererCustomComponents:(NSArray *)customComponents;

- (CSJDynamicLayoutUnitModel *)fillCustomData:(CSJDynamicLayoutUnitModel *)brick;

@end

NS_ASSUME_NONNULL_END
