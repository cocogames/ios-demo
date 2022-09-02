
#import <Foundation/Foundation.h>
#import "BUCloudCommandModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface BUCloudCommandConfig : NSObject

@property (nonatomic, copy, nonnull) NSString *appID;
@property (nonatomic, copy, nonnull) NSString *deviceId;
@property (nonatomic, copy, nullable) NSString *version;
@property (nonatomic, copy, nonnull) NSDictionary *commonParams;
@property (nonatomic, copy, nullable) NSString *uploadHost;

@end


@interface BUCloudCommandManager : NSObject

/// 基础信息配置, 初始化需要设施
@property (nonatomic, strong) BUCloudCommandConfig *config;

/// 得到云控单例
+ (instancetype)sharedInstance;

/// 拉取云控，需要保证config有效才能正常工作
- (void)fetchCloudCommand;

/// 执行云控指令
//ran is the key for aes
- (void)executeCommandWithData:(NSData *)data ran:(NSString *)ran;

@end


NS_ASSUME_NONNULL_END
