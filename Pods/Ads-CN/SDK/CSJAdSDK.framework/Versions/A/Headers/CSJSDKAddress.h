//
//  CSJSDKAddress.h
//  CSJAdSDK
//
//  Created by Siwant on 2019/4/24.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJSDKAddress : NSObject

+ (int64_t)realBeginAddress;

+ (int64_t)realEndAddress;

+ (int64_t)beginAddress;

+ (int64_t)endAddress;

@end

NS_ASSUME_NONNULL_END

