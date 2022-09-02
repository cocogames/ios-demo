//
//  CSJAdClientBiddingHandle.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/9/16.
// 处理client Bindding 相关事件  https://bytedance.feishu.cn/docs/doccne9FOJZlqbZYrluDN5OpTRf

#import <Foundation/Foundation.h>
#import "CSJAdClientBiddingProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJAdClientBiddingHandle : NSObject<CSJAdClientBiddingProtocol>

@property (nonatomic, copy) NSDictionary *(^getMediaExtBlock)(void);//通过物料的media_ext获取 loss/win的url

/// 获取媒体传入的价格,没有传为空
- (nullable NSString *)getAuctionPrice;

@end

NS_ASSUME_NONNULL_END
