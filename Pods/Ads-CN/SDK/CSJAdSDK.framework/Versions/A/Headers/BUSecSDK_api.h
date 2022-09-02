//
//  BUSecSDK_api.h
//  TestMsgLog
//
//  Created by 梁玉林 on 2020/11/6.
//  Copyright © 2020 梁玉林. All rights reserved.
//

#ifndef SGMSafeGuardManager_h
#define SGMSafeGuardManager_h

typedef NS_ENUM(NSUInteger, SGMSafeGuardPlatform)
{
    SGMSafeGuardPlatformHotSoon = 0,                    ///< 火山
    SGMSafeGuardPlatformAweme   = 1,                    ///< 抖音
    SGMSafeGuardPlatformEssay   = 2,                    ///< 内涵
    SGMSafeGuardPlatformCommon  = 3,                    ///< 通用
};

__BEGIN_DECLS

NSString* testMsgLog_bucn(NSString* sgm_customDeviceID, NSString* bodyMD5Hex);

NSData* SecSDK_encode_bucn(int platform, NSData* data);

NSString* sgm_data_acquisition_dataToHexString_bucn(NSData* data);

__END_DECLS

#endif /* SGMSafeGuardManager_h */
