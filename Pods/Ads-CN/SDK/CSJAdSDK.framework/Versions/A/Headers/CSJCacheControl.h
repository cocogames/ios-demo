//
//  CSJCacheControl.h
//  CSJAdSDK
//
//  Created by 李盛 on 2019/5/23.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJCacheControl : NSObject

+ (void)clearAllCache;
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
