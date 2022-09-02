//
//  NSURLRequest+CSJAd.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/10/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURLRequest (CSJAd)

+ (NSURLRequest *)csj_webViewRequestWithURL:(NSURL *)URL;

@end

NS_ASSUME_NONNULL_END
