//
//  UnionKitDefine.h
//  CSJAdSDK
//
//  Created by carl on 2017/11/26.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CSJAd <NSObject>
//此AdID其实是Cid，历史遗留问题
@property (nonatomic, copy) NSString *AdID;
@property (atomic, copy) NSString *extInfo;
@property (nonatomic, copy, nullable) NSString *appLogBaseUrl;//applog上报地址 4300 Bidding在广告响应中指定事件上报机房 https://bytedance.feishu.cn/docx/doxcnmAR7rojbQGwk9pAr3iqWKe

@optional
/// Mopub聚合竞价
@property (nonatomic, copy) NSString *mopubAuctionPrice;
- (void)reportClickUrls;

/// 4400 serverbidding 预缓存Adm回传的log_ext信息
/// 需要拼接到show的log_extra
@property (nonatomic, copy, nullable) NSString *preCacheLogExt;

- (BOOL)validShakeTrigger;
@end

