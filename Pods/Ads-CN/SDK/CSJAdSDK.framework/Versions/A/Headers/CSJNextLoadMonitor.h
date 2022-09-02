//
//  CSJNextLoadMonitor.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/2/10.
//https://bytedance.feishu.cn/docx/doxcnfBjmEbWyO4TDpibt3wYdWg

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJNextLoadMonitor : NSObject

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;
+ (instancetype)sharedInstance;

- (void)recordAdShowWithSlot:(CSJAdSlot *)slot material:(CSJMaterialMeta *)material;

@end

NS_ASSUME_NONNULL_END
