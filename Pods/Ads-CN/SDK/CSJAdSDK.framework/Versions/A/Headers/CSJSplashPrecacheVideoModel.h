//
//  CSJSplashPrecacheVideoModel.h
//  CSJAdSDK
//
//  Created by ByteDance on 2022/5/5.
//

#import <Foundation/Foundation.h>
#import "CSJBasicModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJSplashPrecacheVideoModel : CSJBasicModel

// 广告创意id
@property (nonatomic, copy) NSString *cid;

// 视频素材链接
@property (nonatomic, copy) NSString *url;

// 视频素材的唯一key
@property (nonatomic, copy) NSString *file_hash;

// 素材生效时间
@property (nonatomic, assign) NSTimeInterval effective_time;

// 素材失效时间
@property (nonatomic, assign) NSTimeInterval expiration_time;

// 数据是否有效
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
