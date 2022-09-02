//
//  CSJWebViewLoadManager.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/3.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJWebViewLoadManager : NSObject


@property (nonatomic, strong, readonly) NSOperationQueue *operationQueue;

#pragma mark - Signal
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
