
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUCloudCommandStatus) {
    BUCloudCommandStatusNever = 0,             // 未上传过
    BUCloudCommandStatusInProgress = 1,        // 上传中
    BUCloudCommandStatusSucceed = 2,           // 上传成功
    BUCloudCommandStatusFail = 3,              // 失败
};

/////////////////////////////////////////////////////////////////////

@interface BUCloudCommandMultiData : NSObject

@property (nonatomic, copy) NSString *mimeType;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, strong) NSData *data;
@property (nonatomic, copy) NSString *fileType;  // 目前支持json, log, xml, text

@end

@interface BUCloudCommandModel : NSObject

@property (nonatomic, strong) NSNumber *commandId;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSDictionary *params;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end

/////////////////////////////////////////////////////////////////////

@interface BUCloudCommandResult : NSObject

@property (nonatomic, strong) NSNumber *commandId;
@property (nonatomic, assign) BUCloudCommandStatus status;
@property (nonatomic, copy, nullable) NSString *errorMessage;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, strong) NSData *data;
@property (nonatomic, copy) NSString *mimeType;  // Deprecated, 迁移到slardar平台后，该字段已废弃
@property (nonatomic, copy) NSString *fileType;  // 目前支持json, log, xml, text
@property (nonatomic, assign) long long operateTimestamp;   // 命令生效时间戳

@property (nonatomic, assign) BOOL isMultiData;
@property (nonatomic, copy) NSArray<BUCloudCommandMultiData *> *multiDataArray;
@property (nonatomic, strong) NSDictionary *additionalUploadParams; // 上传时的额外参数

@property (nonatomic, copy, nullable) dispatch_block_t uploadSuccessedBlock;
@property (nonatomic, copy, nullable) void(^uploadFailedBlock)(NSError *error);

@end

typedef void(^BUCloudCommandResultCompletion)(BUCloudCommandResult *result);

@protocol BUCloudCommandProtocol <NSObject>
@required
/// 创建用于执行指令的实例变量
+ (instancetype)createInstance;

/// 执行命令
- (void)excuteCommand:(BUCloudCommandModel *)model
           completion:(BUCloudCommandResultCompletion)completion;

@end

/////////////////////////////////////////////////////////////////////

FOUNDATION_EXPORT void BUCloudCommandRegisterCommand(NSString *type, Class<BUCloudCommandProtocol> commandClass);
FOUNDATION_EXPORT Class<BUCloudCommandProtocol> BUCloudCommandForType(NSString *type);

NS_ASSUME_NONNULL_END

