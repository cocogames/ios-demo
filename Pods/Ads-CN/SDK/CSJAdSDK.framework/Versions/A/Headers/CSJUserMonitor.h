//
//  CSJUserMonitor.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/9/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJUserMonitor : NSObject

- (void)resetWithSlotID:(NSString *)slotID meta:(CSJMaterialMeta *)meta;
- (void)skipClick:(NSString *)slotID;
- (void)click:(NSString *)slotID;

- (nullable NSDictionary *)dictionaryValue:(NSString *)slotID;

@end

NS_ASSUME_NONNULL_END
