//
//  CSJInfoHelperProxy.h
//  CSJAdSDK
//
//  Created by Willie on 2020/8/28.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJFoundationProxy.h"

NS_ASSUME_NONNULL_BEGIN

@interfaceProxy(CSJDefaultImageInfo)

@property (nonatomic, assign) NSInteger w;
@property (nonatomic, assign) NSInteger h;
@property (nonatomic, assign) NSInteger size;
@property (nonatomic, copy) NSString *colorSpace;
@property (nonatomic, copy) NSString *textureFormat;
@property (nonatomic, copy) NSString *filterName;
@property (nonatomic, copy) NSString *extDesc;
@property (nonatomic, copy) NSString *extType;

@end

@interfaceProxy(CSJInfoHelper)

/**
 *  获取info.plist中的CFBundleDisplayName
 *
 *  @return 如果没有，返回CFBundleName
 */
+ (nullable NSString *)bu_appDisplayName;

/**
 *  获取info.plist发布版本号
 *
 *  @return 可能为nil
 */
+ (nullable NSString *)bu_versionName;

/**
 *  @return 获取plist中的CFBundleIdentifier
 */
+ (nullable NSString *)bu_bundleIdentifier;

/**
 *  @return 获取aid
 */
+ (nullable NSString *)bu_ssAppID;

/// 获取默认图片信息
+ (CSJDefaultImageInfoProxy *)bu_defaultImageInfo;


+ (BOOL)bu_checkAppstoreTargetUrlPrefix:(NSString *)targetUrl;

@end

NS_ASSUME_NONNULL_END
