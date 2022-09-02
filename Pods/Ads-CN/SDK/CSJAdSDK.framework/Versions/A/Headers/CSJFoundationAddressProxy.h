//
//  CSJFoundationAddressProxy.h
//  CSJAdSDK
//
//  Created by Willie on 2020/8/28.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJFoundationProxy.h"

NS_ASSUME_NONNULL_BEGIN

@interfaceProxy(CSJFoundationAddress)

+ (int64_t)bu_beginAddress;

+ (int64_t)bu_endAddress;

@end

NS_ASSUME_NONNULL_END
