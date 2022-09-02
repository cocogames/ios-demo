//
//  CSJRewardedVideoRequestModel.h
//  CSJAdSDK
//
//  Created by gdp on 2018/1/18.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJRequestModel.h"

@class CSJRewardedVideoModel;

@interface CSJRewardedVideoRequestModel : CSJRequestModel <CSJToDictionary>

// 奖励名称
@property (nonatomic, copy) NSString *rewardName;

// 奖励数量
@property (nonatomic, assign) NSInteger rewardAmount;

// 网路类型
@property (nonatomic, assign) NSInteger network;

// sdk 版本
@property (nonatomic, copy) NSString *sdkVersion;

// 应用 ua
@property (nonatomic, copy) NSString *userAgent;

// 广告物料 extra
@property (nonatomic, strong) NSDictionary *extra;

// 媒体透传物料 extra
@property (nonatomic, strong) NSString *mediaExtra;

// CSJRewardedVideoModel
@property (nonatomic, strong) CSJRewardedVideoModel *rewardedVideoModel;

// 视频时长
@property (nonatomic, assign) CGFloat videoDuration;

// 观看时长
@property (nonatomic, assign) NSInteger duration;

// 开始播放时间戳
@property (nonatomic, assign) NSInteger playStartTs;

// 播放完成时间戳
@property (nonatomic, assign) NSInteger playEndTs;

// 奖励类型
@property (nonatomic, assign) BURewardType rewardType;

// 第三方游戏 user id 标识
@property (nonatomic, copy) NSString *userId;

// 游戏交易 id 标识
@property (nonatomic, copy) NSString *transId;

- (NSDictionary *)dictionaryValue;

- (instancetype)initWithRewardedVideoModel:(CSJRewardedVideoModel *)rewardedVideoModel extInfo:(NSString *)extInfo extraDic:(NSDictionary *)extraDic;

@end
