//
//  CSJPlayableDownload.h
//  CSJAdSDK
//
//  Created by 李盛 on 2019/6/18.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJMaterialMeta+Private.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^buPlayableDownloadsuccess)(NSDictionary *prama);
typedef void(^buPlayableDownloadFailure)(NSDictionary *prama);

@interface CSJPlayableDownload : NSObject

// 标识当前请求的zip路径,来表示当前的请求值
@property (nonatomic, copy) NSString *currentZipUrl;
// 单例
+ (instancetype)sharedPlayableDownload;
// 开始下载zip (包含埋点事件)
- (void)downloadDataAndTrackWithMeta:(CSJMaterialMeta *)materialMeta success:(buPlayableDownloadsuccess)success fail:(buPlayableDownloadFailure)fail;
// 开始下载zip
- (void)downloadDataWithUrl:(NSString *)url success:(buPlayableDownloadsuccess)success fail:(buPlayableDownloadFailure)fail;
// 根据相对路径查找本地路径
- (NSString *)relativePath:(NSString *)relativePath;
// 根据相对路径查找本地缓存
- (BOOL)existDataWithRelativePath:(NSString *)relativePath;

@end

NS_ASSUME_NONNULL_END
