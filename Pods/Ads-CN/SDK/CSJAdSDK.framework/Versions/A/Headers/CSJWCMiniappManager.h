//
//  CSJWCMiniappManager.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/6/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJWCMiniappInfo;
@class CSJASlotContext;
@protocol CSJActionDeepLinkModel;
@protocol CSJAd;
@protocol CSJActionWebModel;

typedef void(^CSJWCMiniappCompleteBlock)(BOOL, NSDictionary* __nullable);
@interface CSJWCMiniappManager : NSObject
+ (instancetype)manager;

/// 微信open sdk是否用符合预期
+ (BOOL)validWCOpenSDK;

/// 处理scheme和open sdk拉起小程序事件
/// @param model 物料信息
/// @param context 数据上下文
/// @param completionBlock 结果回调
+ (BOOL)handleWCMiniappActionWithModel:(id<CSJActionDeepLinkModel, CSJAd, CSJActionWebModel>)model context:(CSJASlotContext *)context completionBlock:(CSJWCMiniappCompleteBlock __nullable)completionBlock;
@end

NS_ASSUME_NONNULL_END
