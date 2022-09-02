//
//  CSJSDKAuxiliary.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUSDKAuxiliaryTerritory) {
    BUSDKAuxiliaryTerritory_UNKOWN = -1,
    BUSDKAuxiliaryTerritory_VA = 1,
    BUSDKAuxiliaryTerritory_SG = 2,
    BUSDKAuxiliaryTerritory_CN = 3,
};

@interface CSJSDKAuxiliary : NSObject

///
+ (instancetype)shareAuxiliary;
/// 设置地域
/// @param territory 地域
+ (void)setTerritory:(BUSDKAuxiliaryTerritory)territory souceWasSetting:(BOOL)souceWasSetting;
/// 获取地区
+ (BUSDKAuxiliaryTerritory)territory;
/// 获取地区
+ (NSString *)territoryString;

+ (BOOL)isCNTerritory;

+ (BOOL)isGlobalTerritory;

+ (NSString *)sdkChannel;

@end

NS_ASSUME_NONNULL_END
