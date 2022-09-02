//  CSJUnionMacros.h
//  CSJAdSDK
//
//  Created by Siwant on 2019/8/20.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

//#if __has_include(<BURelyFoundation/BUBaseRequest.h>)
//#import <BURelyFoundation/BUBaseRequest.h>
//#else
//#import "BUBaseRequest.h"
//#endif

#import "BUAgileLog.h"

#define kBU_FTC @"BU_FTC"
#define kBUTouchTrackerAssociatedKey @"kBUTouchTrackerAssociatedKey"
#define BUNativeADContainerGertureRecognizer @"BUNativeADContainerGertureRecognizer"

// ET测试总开关，正式上线发版时置0
#define BUAdETTestOpen 0
// 是否提供测试GPS功能，正式上线发版时置0
#define BU_CN_DEVOPEN 0

/// 版本号
FOUNDATION_EXPORT NSString * const CSJSDKVersion;

/***** LogTag *****/
FOUNDATION_EXPORT NSString * const CSJLogTag_Native;
FOUNDATION_EXPORT NSString * const CSJLogTag_Splash;
FOUNDATION_EXPORT NSString * const CSJLogTag_Splash_FullLink;
FOUNDATION_EXPORT NSString * const CSJLogTag_RewardedVideo;
FOUNDATION_EXPORT NSString * const CSJLogTag_SplashBrandVideo;
FOUNDATION_EXPORT NSString * const CSJLogTag_Other;
FOUNDATION_EXPORT NSString * const CSJLogTag_WebView;
FOUNDATION_EXPORT NSString * const CSJLogTag_Dynamic;
FOUNDATION_EXPORT NSString * const CSJLogTag_RenderEngine;
FOUNDATION_EXPORT NSString * const CSJLogTag_LoadDuration;
FOUNDATION_EXPORT NSString * const CSJLogTag_ImageCache;
FOUNDATION_EXPORT NSString * const CSJLogTag_TrackerReport;
FOUNDATION_EXPORT NSString * const CSJLogTag_Playable;
FOUNDATION_EXPORT NSString * const CSJLogTag_Bidding;
FOUNDATION_EXPORT NSString * const CSJLogTag_CommonInfo;
FOUNDATION_EXPORT NSString * const CSJLogTag_Track2;
FOUNDATION_EXPORT NSString * const CSJLogTag_Shake;

#define CSJLogDebug(tag, frmt, ...) BUALog(kBUALogDebug, tag, frmt, ##__VA_ARGS__)
#define CSJLogInfo(tag, frmt, ...)  BUALog(kBUALogInfo, tag, frmt, ##__VA_ARGS__)
#define CSJLogWarn(tag, frmt, ...)  BUALog(kBUALogWarn, tag, frmt, ##__VA_ARGS__)
#define CSJLogError(tag, frmt, ...) BUALog(kBUALogError, tag, frmt, ##__VA_ARGS__)


#define CSJ_ISKINDOFCLASS \
- (BOOL)isKindOfClass:(Class)aClass {\
   \
    if (aClass == nil) return NO;\
    NSString *name = NSStringFromClass(aClass);\
    BOOL result = [super isKindOfClass:aClass];\
    if (!result && [name containsString:@"BU"]) {\
        NSString *targetname =  [name stringByReplacingOccurrencesOfString:@"BU" withString:@"CSJ"];\
        result = [super isKindOfClass:NSClassFromString(targetname)];\
        return result; \
    }\
    return result;\
}

#define CSJ_ISMEMBEROFCLASS \
- (BOOL)isMemberOfClass:(Class)aClass {\
    if (aClass == nil) return NO;\
    NSString *name = NSStringFromClass(aClass);\
    BOOL result = [super isMemberOfClass:aClass];\
    if (!result && [name containsString:@"BU"]) {\
        NSString *targetname =  [name stringByReplacingOccurrencesOfString:@"BU" withString:@"CSJ"];\
        result = [super isMemberOfClass:NSClassFromString(targetname)];\
        return result; \
    }\
    return result;\
}

NS_INLINE NSInteger millisecondFrom(NSTimeInterval second) {
    NSInteger ms = 0;
    if (second >= DBL_MAX / 1000) {
        ms = round(DBL_MAX);
    } else {
        ms = round(second * 1000);
    }
    return ms;
}
