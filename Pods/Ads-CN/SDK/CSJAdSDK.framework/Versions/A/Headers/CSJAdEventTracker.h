//
//  CSJAdEventTracker.h
//  CSJAdSDK
//
//  Created by 曹清然 on 2017/6/2.
//  Copyright © 2017年 chenren. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CSJAd;

typedef enum : NSUInteger {
    BUAdEventTrackerClickScenceDefault = 1,//视频/图片展示环节
    BUAdEventTrackerClickScenceEndcard = 2,//endcard/落地页（包括endcard直出落地页)
    BUAdEventTrackerClickScencePlayable = 3,//playable
} BUAdEventTrackerClickScence;// Click 埋点上报的 ad_extra_data里，增加一个字段，标记本次点击的场景 (V4100海外) https://bytedance.feishu.cn/docs/doccneLr4ZEjdpEPrn0NWdB09xf

NS_ASSUME_NONNULL_BEGIN
@interface CSJAdEventTracker : NSObject

+ (void)trackWithTag:(NSString *)tag label:(NSString *)label adModel:(nullable id<CSJAd>)adModel extraDic:(nullable NSDictionary *)extraDic;

// 新增统计用法,避免每次都要写json方法;
+ (void)trackExtraValueWithTag:(NSString *)tag label:(NSString *)label adModel:(nullable id<CSJAd>)model extraDic:(nullable NSDictionary *)extraDic adExtraDataDic:(nullable NSDictionary *)adExtraDataDic;

@end
NS_ASSUME_NONNULL_END
