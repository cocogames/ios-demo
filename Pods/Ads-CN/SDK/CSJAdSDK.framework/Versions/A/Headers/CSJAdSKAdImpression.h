//
//  CSJAdSKAdImpression.h
//  CSJAdSDK
//
//  Created by Eason on 2021/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJSKANADImpressionObject;

@interface CSJAdSKAdImpression : NSObject

+ (void)startImpression:(CSJSKANADImpressionObject *)model completionHandler:(nullable void (^)(NSError *__nullable error))completion;

+ (void)endImpression:(CSJSKANADImpressionObject *)model completionHandler:(nullable void (^)(NSError *__nullable error))completion;

@end

NS_ASSUME_NONNULL_END
