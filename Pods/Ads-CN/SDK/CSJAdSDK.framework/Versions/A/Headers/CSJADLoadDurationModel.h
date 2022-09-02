//
//  CSJADLoadDurationModel.h
//  CSJAdSDK
//
//  Created by Willie on 2020/12/25.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 保存加载广告过程中各个结点耗时数据的类型
@interface CSJADLoadDurationModel : NSObject

#pragma mark - 请求广告物料阶段
/// 聚合平台物料返回的时间
@property (nonatomic, assign) NSTimeInterval SDKReceiveUnionMetarialsTime;
@property (nonatomic, assign) NSTimeInterval SDKFinishParseUnionMetarialsTime;
/// APP 调用加载广告接口的时间点
@property (nonatomic, assign) NSTimeInterval APPBeginRequestTime;
/// SDK 开始发起网络请求获取广告物料的时间点
@property (nonatomic, assign) NSTimeInterval SDKBeginNetworkRequstTime;
/// SDK 收到广告物料数据返回的时间点
@property (nonatomic, assign) NSTimeInterval SDKReciveNetworkResponesTime;
/// SDK 收到的广告物料数据中所携带的服务端处理数据时长
@property (nonatomic, assign) NSTimeInterval serverProcessingDuration;
/// SDK 完成解析广告物料数据的时间点
@property (nonatomic, assign) NSTimeInterval SDKEndNetworkResponesSerializeTime;

/// 获取加载广告物料的总耗时
- (NSInteger)durationOfLoadADMaterial;
/// 获取获取广告物料过程中各个节点的耗时数据
- (NSDictionary *)detailOfLoadADMaterial;
/// 开屏自渲染的耗时
- (NSDictionary *)splash_native_render_timeDictionary;
#pragma mark - 下载素材资源阶段

/// 素材是否来自本地缓存，默认 YES
@property (nonatomic, assign) BOOL isResourceFromCache;
/// SDK 开始发起网络请求获取素材数据的时间点
@property (nonatomic, assign) NSTimeInterval SDKBeginResourceRequestTime;
/// SDK 收到资源数据返回的时间点
@property (nonatomic, assign) NSTimeInterval SDKReciveResourceResponesTime;
/// SDK 完成缓存素材的时间点
@property (nonatomic, assign) NSTimeInterval SDKEndResourceCacheTime;
/// 缓存图片资源的大小，单位 KB
@property (nonatomic, assign) CGFloat resourceImageSize;
/// 缓存图片资源的分辨率，e.g. 1024x768
@property (nonatomic, copy) NSString *resourceImageResolution;
/// 缓存图片资源的响应头
@property (nonatomic, strong) NSDictionary *resourceImageHTTPHeader;
/// SDK 开始查询素材本地缓存的时间点
@property (nonatomic, assign) NSTimeInterval SDKBeginResourceCacheQueryTime;

/// 获取下载素材数据的总耗时
- (NSInteger)durationOfLoadADResource;
/// 获取下载素材数据过程中各个节点的耗时数据
- (NSDictionary *)detailOfLoadADResource;

- (NSInteger)biddingDurationOfLoadAD;


#pragma mark - 回调给 APP 阶段

/// SDK 给 APP 回调广告加载完成的时间点
@property (nonatomic, assign) NSTimeInterval callbackToAPPTime;

/// 获取加载广告的总耗时
- (NSInteger)durationOfLoadAD;


#pragma mark - 下载动态模版阶段

/// SDK 开始发起下载动态模版的时间点
@property (nonatomic, assign) NSTimeInterval SDKBeginLoadTemplateTime;
/// SDK 下载动态模版结束的时间点
@property (nonatomic, assign) NSTimeInterval SDKEndLoadTemplateTime;

/// 获取下载模版的总耗时
- (NSInteger)durationOfLoadADTemplate;

#pragma mark - 渲染阶段

/// SDK render开始
@property (nonatomic, assign) NSTimeInterval SDKBeginRenderTime;
/// SDK render结束
@property (nonatomic, assign) NSTimeInterval SDKEndRenderTime;

/// 获取渲染的总耗时
- (NSInteger)durationOfRender;

#pragma mark - 加载总耗时
- (NSInteger)durationOfTotalLoadAD;
- (NSDictionary *)detailOfTotalLoadAD;

@end

@interface CSJADLoadDurationModel (Convenience)

/// 通过 image 和 data 参数给 `resourceImageSize` 和 `resourceImageResolution` 赋值
/// `resourceImageSize` 来自 data | image，优先 data
/// `resourceImageResolution` 来自 image
///
/// @param data 图片的 data
/// @param image 图片对象
- (void)fillImageSizeAndResolutionWithData:(NSData *)data image:(UIImage *)image ;

@end

NS_ASSUME_NONNULL_END
