//
//  CSJImmersiveMiddleExpressUtility.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/8/30.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJNativeAd;
@class CSJNativeExpressAdView;
@class CSJMaterialMeta;

typedef void(^BUImmersiveMiddlePageBlock)(BOOL success, CSJNativeExpressAdView * _Nullable nativeExpressView);

@interface CSJImmersiveMiddleExpressUtility : NSObject

/// 获取中间页模板
/// @param nativeAd 广告物料
- (void)bu_fetch_middleTemplateDataWithNativeAd:(CSJNativeAd * _Nullable)nativeAd;


/// 进入中间页进行渲染
/// @param nativeAd 广告物料
/// @param complete 渲染结束回调，可判断是否渲染成功
- (void)bu_immersiveMiddleExpressViewWithAd:(CSJNativeAd *)nativeAd renderComplete:(BUImmersiveMiddlePageBlock)complete;
@end

NS_ASSUME_NONNULL_END
