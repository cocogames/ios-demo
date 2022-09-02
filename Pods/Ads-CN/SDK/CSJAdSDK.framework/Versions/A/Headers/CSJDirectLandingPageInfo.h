//
//  CSJDirectLandingPageInfo.h
//  CSJAdSDK
//
//  Created by shenqichen on 2021/9/27.
//

#import <Foundation/Foundation.h>
#import "CSJPlayableInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDirectLandingPageInfo : NSObject <NSCoding>

//4100 playable字段中迁移出来 https://bytedance.feishu.cn/docs/doccnOJ7LktM8yanOB5ZS9qwGKe#KYuTZa
@property (nonatomic, copy) NSString *directLandingUrl;
@property (nonatomic, assign) NSInteger displayDuration;
@property (nonatomic, assign) NSInteger closeTime;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

- (BOOL)isValid;

/// 4100：物料字段从playable中迁移, 但使用逻辑不变, 因此先继续复用playable数据结构
- (CSJPlayableInfo*)convertToPlayableInfo;

@end

NS_ASSUME_NONNULL_END
