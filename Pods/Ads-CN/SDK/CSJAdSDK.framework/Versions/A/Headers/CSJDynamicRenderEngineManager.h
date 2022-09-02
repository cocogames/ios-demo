//
//  CSJDynamicRenderEngineManager.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicView.h"

// 原生动态化1.0，2.0的渲染引擎

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicRenderEngineManager : NSObject

@property (nonatomic, strong, nullable) NSError *createError;

- (nullable CSJDynamicView *)dynamicViewWithInfoViewModel:(CSJAdInfoViewModel *)infoViewModel dynamicNativeViewModel:(CSJDynamicNativeViewModel *)dynamicNativeViewModel layoutInfoDictionary:(NSDictionary *)layoutInfoDictionary error:(NSError **)error;

#pragma mark - Signal
+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
