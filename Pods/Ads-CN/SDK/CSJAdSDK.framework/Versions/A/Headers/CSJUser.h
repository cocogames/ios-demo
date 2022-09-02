//
//  CSJUser.h
//  CSJAdSDK
//
//  Created by chenren on 10/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJAdSDKDefines.h"

@interface CSJUser : NSObject

// 用户手机号码
@property (nonatomic, copy) NSString *phone;

// 用户额外其它信息
@property (nonatomic, copy) NSString *data;

// 中国区，用户年龄组(青少年合规)
@property (nonatomic, assign) BUAdSDKAgeGroup ageGroup;

// Coppa 儿童隐私协议，1为儿童，0成年，-1未设定
@property (nonatomic, strong) NSNumber *coppa;

// CCPA 海外CCPA合规，加州消费者隐私法案，0允许开启，1为拒绝开启，-1默认情况
@property (nonatomic, assign) NSNumber *CCPA;

// 是否为gdpr用户，1是，0不是，-1不确定
@property (nonatomic, assign) NSNumber *is_gdpr_user;

// gdpr 海外GDPR合规，1为开启隐私保护，0关闭隐私保护，-1不确定
@property (nonatomic, assign) NSNumber *GDPR;

////0不下发广告,不能建立画像 1下发非个性化,不能建立画像 2下发个性化 3300 add
@property (nonatomic, assign) NSInteger personalized_ad;

- (NSDictionary *)dictionaryValue;

@end

