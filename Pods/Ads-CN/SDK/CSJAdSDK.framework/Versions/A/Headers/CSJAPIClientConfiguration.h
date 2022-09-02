//
//  CSJAPIClientConfiguration.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/2/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJAPIClientConfiguration : NSObject
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, copy) NSString *requestURL;
@property (nonatomic, assign) NSInteger reqType;
@property (nonatomic, copy, nullable) NSDictionary *requestDictionary;
@property (nonatomic, copy, nullable) NSDictionary *slotParams;
// 4400 serverbidding 预请求
@property (nonatomic, copy, nullable) NSString *reqeustID;
@end

NS_ASSUME_NONNULL_END
