//
//  BUAdCallManager.h
//  BUSDKProject
//
//  Created by ranny_90 on 2017/5/20.
//  Copyright © 2017年 ranny_90. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJActionServiceDefine.h"
@class CSJASlotContext;

NS_ASSUME_NONNULL_BEGIN

@interface CSJAdCallActionManager : NSObject

+ (instancetype)sharedManager;

- (void)handelActionWithModel:(id<CSJActionPhoneModel>)adModel context:(CSJASlotContext *)context;

- (BOOL)handelActionWithModel:(id<CSJActionPhoneModel>)adModel WithIsWebPage:(BOOL)isWebPage context:(CSJASlotContext *)context;

@end

NS_ASSUME_NONNULL_END
