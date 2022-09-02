//
//  NSError+CSJAd.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/4/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUErrorCodeInternal) {
    BUErrorCodeInternal_0               =           0,
    BUErrorCodeInternal_100             =           100,
    BUErrorCodeInternal_9527            =           9527,
    BUErrorCodeInternal_9528            =           9528,
    BUErrorCodeInternal_9529            =           9529,
    BUErrorCodeInternal_100001          =           100001,
    BUErrorCodeInternal_100002          =           100002,
    BUErrorCodeInternal_100003          =           100003,
    BUErrorCodeInternal_100004          =           100004, // 开屏渲染的时候，缓存图片未命中
};

typedef NS_ENUM(NSInteger, BUAppStorePreloadErrorCode) {
    BUAppStorePreloadErrorCodeAppIDIsNil      = 1101,
    BUAppStorePreloadErrorCodeSystemLimited   = 1102,
    BUAppStorePreloadErrorCodeAppInBackGround = 1102,
    BUAppStorePreloadErrorCodeIsPreloading    = 1103,
    BUAppStorePreloadErrorCodePreloadOnlyWIFI = 1104
};


@interface NSError (CSJAd)
// 网络错误的统一规划 方式一：网络异常的错误，例如服务器出错，超时错误之类的，纯网络出错
+ (NSError *)csj_errorWithNetworkError:(NSError *)error;
// 网络错误的统一规划方式二：服务端返回的错误码和错误信息，一般错误码是response.code和response.description
+ (NSError *)csj_errorWithNetworkErrorCode:(NSInteger)code;
+ (NSError *)csj_errorWithNetworkErrorCode:(NSInteger)code msg:(NSString *)msg;
// 其他各种自定义的内部异常逻辑错误
+ (NSError *)csj_errorWithCode:(NSInteger)code;
+ (NSError *)csj_errorWithCode:(NSInteger)code msg:(NSString *)msg;



+ (NSError *)csj_errorWithError:(NSError *)error mergedError:(NSError *)mergedError;
@end

@interface NSError (CSJAdInternal)
+ (NSError *)csj_splashFileCacheError;
@end

@interface NSError (CSJAdDynamic)
+ (NSDictionary *)csj_dynamicUserInfoWithError:(NSError *)error;
@end

NS_ASSUME_NONNULL_END
