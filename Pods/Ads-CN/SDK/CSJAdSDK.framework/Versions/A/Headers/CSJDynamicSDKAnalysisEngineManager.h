//
//  CSJDynamicSDKAnalysisEngineManager.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/6/16.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicSDKAnalysisEngineManager : NSObject


- (NSDictionary *)layoutInfoFromDictionary:(NSDictionary *)dict infoViewModel:(CSJAdInfoViewModel *)infoViewModel error:(NSError **)error havePreloadDefaultInfo:(BOOL *)havePreloadDefaultInfo;

- (void)async_preloadDefaultInfo;

#pragma mark - Signal
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
