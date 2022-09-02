//
//  CSJDynamicJSAnalysisEngineManager.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/6/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicJSAnalysisEngineManager : NSObject

- (NSDictionary *)layoutInfoFromDictionary:(NSDictionary *)dict error:(NSError **)error;
- (void)updateJSContextWithJSURL:(NSString *)jsURL;

- (BOOL)isJSContextExist;

#pragma mark - Signal
+ (instancetype)sharedInstance;


#pragma mark - 1 & 2 check
- (void)startDynamic1;
- (void)startDynamic2;
- (void)insertLayoutUnitMessage:(NSString *)message;
- (void)endDynamic;



@end

NS_ASSUME_NONNULL_END
