//
//  CSJCloudGameInfo.h
//  CSJAdSDK
//
//  Created by shenqichen on 2021/9/24.
//

#import <Foundation/Foundation.h>
#import "CSJPlayableInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJCloudGameInfo : NSObject <NSCoding>

@property (nonatomic, copy) NSString *cloudGameUrl;

// 0: 视频后出云游戏，1:直出云游戏
@property (nonatomic, assign) NSInteger cloudGameType;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

- (BOOL)isValid;

/// 4100：云游戏物料字段从playable中迁移, 但使用逻辑不变, 因此先继续复用playable数据结构
/// https://bytedance.feishu.cn/docs/doccnOJ7LktM8yanOB5ZS9qwGKe
- (CSJPlayableInfo*)convertToPlayableInfo;

@end

NS_ASSUME_NONNULL_END
