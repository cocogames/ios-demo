//
//  BURequest.h
//  CSJAdSDK
//
//  Created by chenren on 11/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJRequestModel.h"
#import "CSJUser.h"
#import "CSJApp.h"
#import "CSJDevice.h"
#import "CSJABTest.h"
#import "CSJAdSlot.h"

@interface CSJUnionRequestModel : CSJRequestModel <CSJToDictionary>

/// requestID
@property (nonatomic, copy) NSString *requestID;

/// SDK的版本
@property (nonatomic, copy) NSString *adSDKVersion;

/// 用户ID
@property (nonatomic, copy) NSString *userID;

/// 头条did,感觉没有用到
@property (nonatomic, copy) NSString *did;

/// 用户的基本信息
@property (nonatomic, strong) CSJUser *user;

/// 流量类型
@property (nonatomic, copy) NSString *sourceType;

/// sourceType为app时，必须提供
@property (nonatomic, strong) CSJApp *app;

/// 移动设备的信息
@property (nonatomic, strong) CSJDevice *device;

/// article_u
@property (nonatomic, copy) NSString *ua;

/// IP
@property (nonatomic, copy) NSString *ip;

/// IPv4
@property (nonatomic, copy) NSString *ipv4;

/// IPv6
@property (nonatomic, copy) NSString *ipv6;

/// 广告位的信息
@property (nonatomic, strong) NSMutableArray *adslotsAry;

/// 主动请求还是被动请求
@property (nonatomic, strong) NSNumber *req_type;

/// 时间戳
@property (nonatomic, strong) NSNumber *ts;

/// 请求签名
@property (nonatomic, copy) NSString *req_sign;

/// 落地页的商品id列表，用于鲁班回流页
@property (nonatomic, copy) NSArray *source_temai_product_ids;

/// AB Test需要带上 
@property (nonatomic, strong) CSJABTest *abTest;

/// iOS 14 network id list
@property (nonatomic, copy) NSArray *network_id_list;

/// 3800 激励视频再看一个需求
@property (nonatomic, copy) NSString *preSessions;

@property (nonatomic, copy) NSString *playAgainRit;

@property (nonatomic, weak) CSJAdSlot *slot;

/// 4200 代码位组ID, 用于样式ab
@property (nonatomic, strong) NSNumber *code_group_id;

/// 用于接口之间透传数据
@property (nonatomic, copy) NSString *extra_data;

/// 4400 server bidding异步打包请求物料
@property (nonatomic, copy) NSString *material_keys;

- (NSDictionary *)dictionaryValue;

@end


