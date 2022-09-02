//
//  CSJADViewTrackInfo.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/11/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJADViewTrackInfo : NSObject

@property (nonatomic, assign) NSTimeInterval viewDidAllVisibleTime;
@property (nonatomic, strong, nullable) NSDate *didEnterBackgroundDate;
@property (nonatomic, strong, nullable) NSDate *willEnterForegroundDate;
//海外v4200 补充展示相关数据上报 https://bytedance.feishu.cn/docs/doccnjUZHJyu0XqW5WVF66TMUGf
@property (nonatomic, assign) NSTimeInterval showStartTime;//首次展示的时间
@property (nonatomic, assign) NSTimeInterval showFirstQuartileTime;//展示到达25%的时间
@property (nonatomic, assign) NSTimeInterval showMidTime;//展示到达50%的时间 单位ms
@property (nonatomic, assign) NSTimeInterval showThirdQuartileTime;//展示到达75%的时间
@property (nonatomic, assign) NSTimeInterval showFullTime;//展示到达100%的时间

- (nullable NSDictionary *)showTimeDict;
- (NSInteger)duration;

@end

NS_ASSUME_NONNULL_END
