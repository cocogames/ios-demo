//
//  CSJDynamicEngineAdapter.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/1/12.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, BUDynamicEngineVersion) {
    BUDynamicEngineVersion_1           =           1,
    BUDynamicEngineVersion_2           =           2,
};

@interface CSJDynamicEngineAdapter : NSObject
+ (instancetype)dynamicEngineAdapterWithDynamicEnginVersion:(BUDynamicEngineVersion)dynamicEngineVersion;

- (NSDictionary *)layoutInfoWithOriginInfo:(NSDictionary *)originInfo infoViewModel:(CSJAdInfoViewModel *)infoViewModel userInfo:(NSDictionary **)userInfo error:(NSError **)error;


#pragma mark - Override Report
- (NSDictionary *)beginAnalysisUserInfo;

#pragma mark - Override Key
- (NSString *)dynamic_sub_analysis_start;
- (NSString *)dynamic_sub_analysis_end;
- (NSString *)dynamic_sub_render_start;
- (NSString *)dynamic_sub_render_end;
- (NSString *)version_log_key;
- (NSInteger)componentNotExistErrorCode;
@end

NS_ASSUME_NONNULL_END
