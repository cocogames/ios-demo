//
//  CSJUnionRequestModel+Factory.h
//  CSJAdSDK
//
//  Created by 李盛 on 2018/5/17.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import "CSJUnionRequestModel.h"
#import "CSJAdSlot.h"
#import "CSJAPIClient.h"

@interface CSJUnionRequestModel (Factory)
+ (instancetype)unionRequestModel:(CSJAdSlot *)slot slotParams:(NSDictionary *)slotParams reqType:(BURewardedVideoRequestType)reqType;

@end
