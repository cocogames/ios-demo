//
//  CSJSDKMonitor.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/12/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, BUSDKStartType) {
    BUSDKStartType_Cold        =           0,
    BUSDKStartType_Warm        =           1,
};
@interface CSJSDKMonitor : NSObject

#pragma mark - ads_parameter
// https://bytedance.feishu.cn/wiki/wikcn8fXf1nA6HHZwHUDeAEYNHd
// 需要atomic，会自增
@property (atomic, assign, readonly) NSInteger showCount;
#pragma mark - Public
- (void)showCountIncrement;
- (NSDictionary *)ads_parameter_dictionaryValue;

@end

NS_ASSUME_NONNULL_END
