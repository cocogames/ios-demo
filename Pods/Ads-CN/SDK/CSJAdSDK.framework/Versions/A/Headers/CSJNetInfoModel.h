//
//  CSJNetInfoModel.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJNetInfoModel : NSObject
- (void)updateWithIP:(NSString *)ip;
- (void)updateWithIPv4:(NSString *)ipv4;
- (void)updateWithIPv6:(NSString *)ipv6;

// 多线程安全，获取ip信息使用以下接口获取，不要使用属性获取
- (NSString *)ipInfoStr;
- (NSString *)ipv4InfoStr;
- (NSString *)ipv6InfoStr;

- (NSDictionary<NSString *, NSString*> *)applogNetInfoCustom;
@end

NS_ASSUME_NONNULL_END
