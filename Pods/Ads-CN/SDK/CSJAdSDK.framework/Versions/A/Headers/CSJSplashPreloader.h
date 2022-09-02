//
//  CSJSplashPreloader.h
//  CSJAdSDK
//
//  Created by carl on 2017/9/6.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJMaterialMeta+Splash.h"

@class CSJAdSlot;
@class BUPersistence;

typedef void(^splashSuccessGetMateria)(CSJMaterialMeta *materialMeta, NSNumber *isCache, NSDictionary *extraInfo);
typedef void(^splashGetMateria)(CSJMaterialMeta *materialMeta, BUMaterialMetaStatus status);
typedef void(^splashFailGetMateria)(NSError *error, BOOL timeOut, NSNumber *isCache, NSDictionary *extraInfo);
typedef void(^failure)(NSError *error, NSDictionary *extraInfo);
typedef void(^splashCacheLoadError)(BUMaterialMetaStatus status);

@interface CSJSplashPreloader : NSObject

@property (nonatomic, assign) NSTimeInterval timeout;

+ (instancetype)sharedPreloader;

+ (id<BUPersistenceProtocol>)defaultPersistence;

- (void)materialMetaForSplash:(CSJAdSlot *)slot sucess:(splashSuccessGetMateria)success failure:(splashFailGetMateria)failure;

- (void)deleteSplashDiskData;

@end
