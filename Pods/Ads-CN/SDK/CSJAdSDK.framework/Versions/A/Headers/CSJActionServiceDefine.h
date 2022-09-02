//
//  CSJActionServiceDefine.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/8.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CSJDeepLink;
@class CSJAppInfo;
@class CSJVideoInfo;

typedef NS_ENUM(NSInteger, BUAdDownloadActionType) {
    BUAdDownloadActionType_OpenUrl,
    BUAdDownloadActionType_FallBackUrl,
    BUAdDownloadActionType_DownloadUrl,
    BUAdDownloadActionType_UnKnown
};

/** 初始化成功回调 */
typedef void (^SuccessCallback)(void);
/** 初始化失败回调 */
typedef void (^FailedCallback)(NSError *error,NSString *failMessage);
/** 下载结果类型回调 */
typedef void(^DownloadActionBlock)(BUAdDownloadActionType actionType);
@protocol CSJActionWebModel <NSObject>
// 创意的落地页URL
@property (nonatomic, copy) NSString *targetURL;
@property (nonatomic, copy) NSString *AdTitle;

@end

@protocol CSJActionPhoneModel <NSObject>
// 广告类型为电话时，电话号码必须
@property (nonatomic, copy) NSString *phone;

@end

@protocol CSJActionDeepLinkModel <NSObject>

@property (nonatomic, strong) CSJDeepLink *deepLink;
@property (nonatomic, copy) NSString *ulink;

@end

@protocol CSJActionAppModel <NSObject>
// 应用名称
@property (nonatomic, copy) NSString *appName;

@property (nonatomic, copy) NSString *appid;

// 应用下载URL，应用下载必须
@property (nonatomic, copy) NSString *downloadURL;

@end

@protocol CSJActionVideoModel <NSObject>

@property (nonatomic, copy) NSString *AdTitle;
@property (nonatomic, copy) NSString *buttonText;

@optional
// 区分明暗投
@property (nonatomic, assign) NSInteger unionSpecial;

// 落地页链接
@property (nonatomic, copy) NSString *targetURL;

@property (nonatomic, strong) CSJAppInfo *appInfo;

@property (nonatomic, strong) CSJVideoInfo *videoInfo;

@end

