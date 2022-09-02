//
//  CSJVideoAdActionManager.h
//  CSJAdSDK
//
//  Created by gdp on 2017/12/10.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJActionServiceDefine.h"

@class CSJASlotContext;

@interface CSJVideoAdActionManager : NSObject

+ (instancetype)sharedManager;

- (BOOL)handleVideoAdActionWithModel:(id<CSJActionVideoModel>)admodel context:(CSJASlotContext *)context;

@end
