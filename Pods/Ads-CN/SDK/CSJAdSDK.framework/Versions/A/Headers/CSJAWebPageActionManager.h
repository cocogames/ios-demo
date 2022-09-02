//
//  CSJAWebPageActionManager.h
//  CSJAdSDK
//
//  Created by 曹清然 on 2017/5/25.
//  Copyright © 2017年 chenren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJActionServiceDefine.h"

@class CSJASlotContext;

@interface CSJAWebPageActionManager : NSObject

+ (instancetype)sharedManager;

- (BOOL)handleActionWithModel:(id<CSJActionWebModel>)admodel context:(CSJASlotContext *)context;

@end
