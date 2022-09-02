
#import <Foundation/Foundation.h>
#import "CSJAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

#define kCSJCLogMaxSize     20
#define kCSJCLogExpireDays  7
#define kCSJCLogLogLevel    kBUALogWarn

@interface CSJClogConfigModel : NSObject <NSCoding>

/// 是否打开云控
@property (nonatomic, assign) BOOL isOpen;

/// 日志记录最低等级
@property (nonatomic, assign) kBUALogLevel logLevel;

/// 本地日志文件过期时间，单位天
@property (nonatomic, assign) NSUInteger expireDays;

/// 本地日志文件总体占用的最大磁盘空间，单位M
@property (nonatomic, assign) NSUInteger maxSize;

/// 隐私等级控制，隐私要求，保留字段
@property (nonatomic, assign) NSInteger privacyLevel;

/// 构建model
- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
