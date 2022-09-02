//
//  _CSJVideoAdReportor.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/8/3.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJVideoAdReportor.h"
#import "CSJNativeAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJVideoAdReportor : NSObject <CSJVideoAdReportor>

- (instancetype)initWithNativeAd:(CSJNativeAd *)nativeAd;

@end

NS_ASSUME_NONNULL_END
