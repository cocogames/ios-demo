//
//  CSJAdSDKTestToolManager+Private.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/4/14.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJAdSDKTestToolManager.h"

@interface CSJAdSDKTestToolManager ()
@property (nonatomic, copy) NSString *hostIP;
@property (nonatomic, copy) NSString *hostPort;

+ (BOOL)isDemoEnvironment;

@end

