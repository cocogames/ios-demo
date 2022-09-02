//
//  CSJDynamicTimingPolicyDecorator.h
//  CSJAdSDK
//
//  Created by Rush.D.xzj on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicAbstractDecorator.h"
#import "CSJDynamicAbstractViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicTimingPolicyDecorator : CSJDynamicAbstractDecorator <CSJDynamicAbstractViewTimingProtocol>

@end

NS_ASSUME_NONNULL_END
