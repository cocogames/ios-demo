//
//  CSJRenderEngineDefine.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/17.
//

#import <Foundation/Foundation.h>

// 渲染引擎最终渲染成功或者失败的方式
typedef NS_ENUM(NSInteger, BURenderEngineRenderType) {
    BURenderEngineRenderTypeNone                =           -1,          // 未渲染
    BURenderEngineRenderTypeTemplate                =           0,          // 动态布局渲染
    BURenderEngineRenderTypeSDKCover                =           1,          // 兜底渲染(SDK固定样式)
    BURenderEngineRenderTypeRenderNative             =           2,          // 原生动态化1.0
    BURenderEngineRenderTypeRenderNative2             =           3,          // 原生动态化2.0
    BURenderEngineRenderTypeLyex             =           4,          // Lynx
    BURenderEngineRenderTypeBrandBanner             =           5,          // 品牌广告
};
