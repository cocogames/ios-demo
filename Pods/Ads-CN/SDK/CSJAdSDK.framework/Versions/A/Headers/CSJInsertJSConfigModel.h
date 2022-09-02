//
//  CSJInsertJSConfigModel.h
//  CSJAdSDK
//
//  Created by Willie on 2022/2/16.
//

#import "CSJModelSerialization.h"

@class CSJPerformanceJSModel;

NS_ASSUME_NONNULL_BEGIN

/// 在 webView 中执行 JS 的配置模型
@interface CSJInsertJSConfigModel : NSObject <NSSecureCoding, CSJModelSerialization>

/// 需要执行的 JS
@property (nonatomic, strong, nullable) CSJPerformanceJSModel *performanceJS;

@end

/// 在 webView 中执行 JS 的模型
@interface CSJPerformanceJSModel : NSObject <NSSecureCoding, CSJModelSerialization>

/// JS 的 URL
@property (nonatomic, copy) NSString *URL;
/// 需要执行的时机
/// load_finish 在 webView 加载成功时执行
@property (nonatomic, copy) NSArray<NSString *> *executeTime;

@end

NS_ASSUME_NONNULL_END
