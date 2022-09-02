//
//  CSJUnionEnum.h
//  Pods
//
//  Created by zth on 2021/7/30.
//

/**
 该类承担 项目中公共枚举列表,  这里并不包含 对开发者披露的 枚举
  @Warning 文件所处位置不太合适
 */
#ifndef BUUnionEnum_h
#define BUUnionEnum_h

/**请示请求复用预加载时, 此时预加载的状态枚举, 这是一个复用结果的表示 */
typedef NS_ENUM(NSInteger, BUAdPreloadResultType) {
    
    BUAdPreloadResultNone                     = 0, /**<复用的预加载广告，但是物料尚未获取到*/
    BUAdPreloadResultMaterialMeta             = 1, /**<复用的预加载广告，物料获取到，但是视频仍未获取到*/
    BUAdPreloadResultMaterialMetaAndVideo     = 2, /**< 复用的预加载广告，物料视频均获取完成 */
};


#endif /* BUUnionEnum_h */
