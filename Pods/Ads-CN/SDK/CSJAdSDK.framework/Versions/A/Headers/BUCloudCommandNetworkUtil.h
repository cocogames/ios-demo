
#import <Foundation/Foundation.h>
#import "BUCloudCommandModel.h"
//ran is the key for aes
typedef void (^BUCloudCommondSuccessBlock)(id responseObject, NSData *data, NSString *ran);
typedef void (^BUCloudCommondFailureBlock)(NSError *error);

typedef NS_ENUM(NSInteger, BUCloudCommandRequestMethod)
{
    BUCloudCommandRequestMethodGet = 0,
    BUCloudCommandRequestMethodPost = 1,
};

@interface BUCloudCommandNetworkUtil : NSObject

+ (void)requestWithUrl:(NSString *)url
         requestMethod:(BUCloudCommandRequestMethod)requestMethod
                params:(NSDictionary *)params
        requestHeaders:(NSDictionary *)requestHeaders
               success:(BUCloudCommondSuccessBlock)success
               failure:(BUCloudCommondFailureBlock)failure;

+ (void)uploadDataWithUrl:(NSString *)url
                 fileName:(NSString *)fileName
                 fileType:(NSString *)fileType
                     data:(NSData *)data
                   params:(NSDictionary *)params
             commonParams:(NSDictionary *)commonParams
                 mimeType:(NSString *)mimeType
           requestHeaders:(NSDictionary *)requestHeaders
                  success:(BUCloudCommondSuccessBlock)success
                  failure:(BUCloudCommondFailureBlock)failure;

+ (void)uploadMultiDataWithUrl:(NSString *)url
                     dataArray:(NSArray<BUCloudCommandMultiData *> *)dataArray
                        params:(NSDictionary *)params
                  commonParams:(NSDictionary *)commonParams
                requestHeaders:(NSDictionary *)requestHeaders
                       success:(BUCloudCommondSuccessBlock)success
                       failure:(BUCloudCommondFailureBlock)failure;

@end

