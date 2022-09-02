//
//  CSJAPIThrottling.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/23.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 广告API限流 策略
 */
@interface CSJAPIThrottling : NSObject
@property (nonatomic, assign) BOOL enable;


- (BOOL)canMakeRequest;
- (void)reportAPIStat:(NSString *)rit;
@end
