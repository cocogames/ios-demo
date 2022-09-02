//
//  CSJAdNetworkRequest.h
//  CSJAdSDK
//
//  Created by 李盛 on 2018/4/3.
//  Copyright © 2018年 bytedance. All rights reserved.
//




NS_ASSUME_NONNULL_BEGIN
@interface CSJAdNetworkRequest : BUNetworkRequest
@property (class, nonatomic, strong, readonly) NSString *bu_base_URL;
@end

//动态布局 子模板 专用请求方法，超时时间为5s
@interface CSJDynamicRequest : CSJAdNetworkRequest

+ (instancetype)requestWithURL:(NSString *)url
                        method:(BURequestMethod)method
                     parameter:(NSDictionary * _Nullable)paraDic
         completionWithSuccess:(BURequestCompletionBlock _Nullable)success
                       failure:(BURequestCompletionBlock _Nullable)failure;
@end

//动态布局 主模板 专用请求方法
@interface CSJDynamicTemplateRequest : CSJAdNetworkRequest

+ (instancetype)requestWithURL:(NSString *)url
                        method:(BURequestMethod)method
                     parameter:(NSDictionary * _Nullable)paraDic
         completionWithSuccess:(BURequestCompletionBlock _Nullable)success
                       failure:(BURequestCompletionBlock _Nullable)failure;
@end


@interface  CSJGetADSRequest: CSJAdNetworkRequest
@end

// 开屏请求物料
@interface  CSJGetSplashADSRequest: CSJGetADSRequest
@end

/// Extlog接口，即applog
@interface  CSJExtlogRequest: CSJAdNetworkRequest

@property (nonatomic, copy) NSString *applogBaseUrl;

@end


/// ET平台接口，测试包环境下转发一份applog数据
@interface  CSJETLogRequest: CSJAdNetworkRequest
@end

/// ET平台接口，测试包环境下转发一份applog数据
@interface  CSJWCMiniappReqeust: BUNetworkRequest
@end
NS_ASSUME_NONNULL_END


