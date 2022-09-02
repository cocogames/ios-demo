//
//  CSJAdFileCacheConfig.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@interface CSJAdFileCacheConfig : NSObject

@property (nonatomic, copy) NSString *directoryName;

// 默认值是0，当<=0表示无限
@property (nonatomic, assign) NSInteger maxFileCount;

// 单位是字节，默认值是0，当<=0表示无限
@property (nonatomic, assign) NSInteger maxSize;

// 关键日志，可选
@property (nonatomic, copy) NSString *keyLog;

#pragma mark - Public Method
- (BOOL)valid;


@end

NS_ASSUME_NONNULL_END
