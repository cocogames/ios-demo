//
//  CSJNativeExpressAdView+middlePage.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/11/4.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJNativeExpressAdView.h"

NS_ASSUME_NONNULL_BEGIN
@class CSJNativeExpressAdView;
@class CSJMaterialMeta;
@protocol CSJImmersiveMiddleExpressDelegate <NSObject>
/// 返回上一级页面
/// @param nativeExpressAdView 模板视图
- (void)nativeExpressViewImmersiveMiddlePageBack:(CSJNativeExpressAdView *)nativeExpressAdView;

/// 沉浸式点击bar或相关推荐创意区点击事件回调
/// @param nativeExpressAdView 模板视图
/// @param materialMeta 点击App对应的物料
- (void)nativeExpressView:(CSJNativeExpressAdView *)nativeExpressAdView creativeClickWithMaterial:(CSJMaterialMeta *)materialMeta;

@end

@interface CSJNativeExpressAdView()
/// 标记二级模板页已展示，区别模板广告的一级页面
@property (nonatomic, assign) BOOL validImmersiveExpressView;

@property (nonatomic, weak) id<CSJImmersiveMiddleExpressDelegate> middleExpressDelegate;

/// 相关推荐页物料JSON
@property (nonatomic, copy) NSDictionary *relatedMaterialMetaJSON;
/// 相关推荐页物料字典，便于点击推荐app时进行查询
@property (nonatomic, strong) NSMutableDictionary<NSString *, CSJMaterialMeta *> *relatedAdAppsID;

- (void)safeDelegate_immersiveMiddleExpressPageBack;
- (void)safeDelegate_immersiveMiddleExpressClickWithMaterial:(CSJMaterialMeta *)matrialMeta;

@end

NS_ASSUME_NONNULL_END
