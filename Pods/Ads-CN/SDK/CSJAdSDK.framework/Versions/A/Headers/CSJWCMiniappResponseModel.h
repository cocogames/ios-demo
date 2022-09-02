//
//  CSJWCMiniappResponseModel.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/6/23.
//

#import <Foundation/Foundation.h>
#import "CSJModelSerialization.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJWCMiniappResponseModel : NSObject <CSJModelSerialization>
/// scheme方式拉起小程序的deeplink链接
@property (nonatomic, copy) NSString *scheme;
/// open sdk拉取小程序需要userName（目标小程序原始id）
@property (nonatomic, copy) NSString *userName;
/// open sdk拉取小程序需要path（目标小程序页面路径）(可选)
@property (nonatomic, copy, nullable) NSString *path;

/// 判断userName是否有值
- (BOOL)validOpenSDKInfo;
/// 判断scheme链接是否有值
- (BOOL)validSchemeInfo;
@end

NS_ASSUME_NONNULL_END
