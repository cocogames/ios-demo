//
//  CSJAdActionManager.h
//  CSJAdSDK
//
//  Created by 曹清然 on 2017/5/25.
//  Copyright © 2017年 chenren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJASlotContext.h"
#import "CSJMaterialMeta.h"
#import "CSJActionServiceDefine.h"

@protocol CSJAd;

NS_ASSUME_NONNULL_BEGIN

@interface CSJAdActionManager : NSObject

+ (instancetype)sharedManager;

/*
 下载app
 */
- (void)bu_handleAppActionWithModel:(CSJMaterialMeta *)adModel context:(nonnull CSJASlotContext *)context withDownloadActionType:(DownloadActionBlock)actionType withSucessCallBack:(nonnull SuccessCallback)sucessCallBack withFailedCallback:(nonnull FailedCallback)failedCallback;


/*
 电话拨打
 */
- (void)bu_handelCallActionWithModel:(id<CSJAd, CSJActionPhoneModel,CSJActionWebModel>)adModel
                             context:(CSJASlotContext *)context;


- (void)bu_handelCallActionWithModel:(id<CSJAd, CSJActionPhoneModel,CSJActionWebModel>)adModel
                       withIsWebPage:(BOOL)isWebPage
                             context:(CSJASlotContext *)context;


/*
 跳转落地页
 */
- (void)bu_handleWebPageActionWithModel:(id<CSJActionWebModel, CSJActionDeepLinkModel>)admodel
                                context:(CSJASlotContext *)context;


/*
 打开safari浏览器
 */
- (void)bu_handleSafariActionWithModel:(id<CSJActionWebModel,CSJActionDeepLinkModel>)admodel
                               context:(CSJASlotContext *)context;


/*
 打开视频详情页
 */
- (void)bu_handleVideoAdActionWithModel:(id<CSJActionVideoModel, CSJActionDeepLinkModel,CSJActionWebModel>)admodel
                                context:(CSJASlotContext *)context;

- (void)bu_splashHandleWebPageActionWithModel:(id<CSJActionWebModel, CSJActionDeepLinkModel,CSJActionWebModel>)admodel context:(CSJASlotContext *)context;
+ (void)gotoDetailPage:(CSJMaterialMeta *)materialMeta
               context:(CSJASlotContext *)context;
+ (void)gotoSplashDetailPage:(CSJMaterialMeta *)materialMeta context:(CSJASlotContext *)context;

/*
 打开隐私详情页页
 */
- (void)bu_openPolicy:(CSJMaterialMeta *)materialMeta
              context:(CSJASlotContext *)context;

@end

NS_ASSUME_NONNULL_END
