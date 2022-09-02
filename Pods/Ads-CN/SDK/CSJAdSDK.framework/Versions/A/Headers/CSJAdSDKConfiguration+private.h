//
//  CSJAdSDKConfiguration+private.h
//  CSJAdSDK
//
//  Created by Eason on 2021/3/5.
//

#import <CSJAdSDK/CSJAdSDK.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const CSJFetchSettingsNotification;

typedef NS_ENUM(NSUInteger, BUAudioSessionSetType) {
    BUAudioSessionSetType_Default = 0,
    BUAudioSessionSetType_UnSet   = 1,
    BUAudioSessionSetType_SetTrue = 2
};

@interface CSJAdSDKConfiguration ()
///settings 下发的Coppa
@property (nonatomic, strong) NSNumber *serverCoppa;
///settings 下发的GDPR
@property (nonatomic, strong) NSNumber *serverGDPR;
/// 外部传入的vid 来区分abtest
@property (atomic, copy) NSString *abvidString;
/// 从 CSJAdSDKManager 的 userExtData 中解析出的固有字段，逻辑见
/// https://bytedance.feishu.cn/docs/doccn0xMBh3CkHxoiSkxvcFN7qb#yM9hLk
@property (nonatomic, copy) NSArray *inherentUserData;

@property (nonatomic, copy) NSString *unitySetString;
@property (nonatomic, copy) NSString *unityEVString;
@property (nonatomic, assign) BUAudioSessionSetType audioSessionType;

/// 组合了CSJ区域信息的appid
/// @Note 因拆库后续满足同时初始化国内外 且  (需要满足 不同的AppID可连续初始化 这是之前可支撑的逻辑)  设置该字段.  老接口失效时 该字段失效
@property (nonatomic, copy) NSString *territoryCSJappID;

/// 获取接口层版本号
+ (NSString *)interfaceVersion;

@end

NS_ASSUME_NONNULL_END
