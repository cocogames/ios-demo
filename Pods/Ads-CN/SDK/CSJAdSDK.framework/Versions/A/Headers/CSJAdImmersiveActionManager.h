//
//  CSJAdImmersiveActionManager.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/10/25.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJActionServiceDefine.h"
NS_ASSUME_NONNULL_BEGIN
@class CSJASlotContext;
@class CSJMaterialMeta;

@interface CSJAdImmersiveActionManager : NSObject
+ (instancetype)sharedManager;

- (BOOL)handleImmersiveActionWithModel:(CSJMaterialMeta *)admodel context:(CSJASlotContext *)context fromVideo:(BOOL)fromVideo;
@end

NS_ASSUME_NONNULL_END
