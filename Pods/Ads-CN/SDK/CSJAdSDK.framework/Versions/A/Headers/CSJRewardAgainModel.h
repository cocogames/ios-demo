//
//  CSJRewardAgainModel.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2021/6/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BURewardAgainType) {
    BURewardAgainType_closeBtn           = 1,   //1 ： 点击X时展示挽留弹框入口
    BURewardAgainType_endcard    = 2,   //2 ：EndCard上展示再看一个按钮入口
    BURewardAgainType_all         = 3   //3 ： 1 和 2 功能都有   其他 ：不展示再看一个入口
};


@interface CSJRewardAgainModel : NSObject

/// 3800 激励视频再看一个
@property (nonatomic, assign) BURewardAgainType againType;
/// 3800 二次请求激励视频携带的参数
@property (nonatomic, copy) NSString *preSessions;
/// 4300 二次请求激励视频携带的独立rit参数
@property (nonatomic, copy) NSString *playAgainRit;

@property (nonatomic, copy) NSString *buttonText;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError *__autoreleasing *)error;
@end

NS_ASSUME_NONNULL_END
