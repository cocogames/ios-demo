//
//  CSJPlayableCommonInfo.h
//  CSJAdSDK
//
//  Created by yujie on 2022/2/28.
//

#import <Foundation/Foundation.h>
#import "CSJLoadingInfo.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJPlayableCommonInfo : NSObject<NSCoding>
@property (nonatomic, strong) CSJLoadingInfo *loadingInfo;
/// 转化时，是否优先调起Playable落地页（优于DeepLink）
@property (nonatomic, assign) BOOL is_playable_top_priority;

- (instancetype)initWithDictionary:(NSDictionary *)dict
                             error:(NSError *__autoreleasing *)error NS_DESIGNATED_INITIALIZER;
@end


NS_ASSUME_NONNULL_END
