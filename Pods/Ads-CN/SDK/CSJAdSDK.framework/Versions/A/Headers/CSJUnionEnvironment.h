//
//  CSJUnionEnvironment.h
//  CSJAdSDK
//
//  Created by chenren on 18/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJApp.h"
#import "CSJDevice.h"
#import "CSJUser.h"
#import "CSJNetInfoModel.h"
@interface CSJUnionEnvironment : NSObject

+ (CSJApp *)currentApp;

+ (CSJDevice *)currentDevice;

+ (CSJUser *)currentUser;

+ (CSJNetInfoModel *)currentIP;
/// 470x 记录get_ads返回ipv4的信息
+ (void)setClientIPv4Address:(NSString *)ipv4;
@end

