//
//  CSJVideoAdEnum
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/8/9.
//  Copyright © 2019 bytedance. All rights reserved.
//

#ifndef BUVideoAdEnum_h
#define BUVideoAdEnum_h
#import "CSJAdSDKDefines.h"

typedef NS_ENUM(NSUInteger, BUNativeExpressVideoOrientation) {//物料配置方向
    BUNativeExpressVideoOrientationPortrait     = 1,         //竖屏
    BUNativeExpressVideoOrientationLandscape    = 2,         //横屏
};

typedef NS_ENUM(NSUInteger, BUChildTransformDirection) {//子控制器旋转方向
    BUChildTransformDirectionNone     = 0,         //不旋转
    BUChildTransformDirectionLeft     = 1,         //向左旋转
    BUChildTransformDirectionRight    = 2,         //向右旋转
};

FOUNDATION_EXPORT NSString* NSStringFromRitScene(BURitSceneType type);

#endif /* BUVideoAdEnum_h */
