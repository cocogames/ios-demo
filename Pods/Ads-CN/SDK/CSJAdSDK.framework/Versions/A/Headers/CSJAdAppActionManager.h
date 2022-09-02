//
//  BUAdAppDownloadManager.h
//  BUSDKProject
//
//  Created by ranny_90 on 2017/5/20.
//  Copyright © 2017年 ranny_90. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJActionServiceDefine.h"
#import "CSJAppStoreManager.h"

@class CSJASlotContext;
@class CSJMaterialMeta;

@interface CSJAdAppActionManager : NSObject

+ (instancetype)sharedManager;

-(BUAdDownloadActionType)handleActionWithModel:(CSJMaterialMeta *)material WithSucessCallBack:(SuccessCallback)sucessCallBack WithFailedCallback:(FailedCallback)failedCallback context:(CSJASlotContext *)context;

- (BUAppStoreOpenType)openAppStoreTypeWithMaterial:(CSJMaterialMeta *)material;

@end
