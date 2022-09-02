//
//  CSJJSFileDownloader.h
//  CSJAdSDK
//
//  Created by Willie on 2022/2/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJJSFileDownloader : NSObject

+ (instancetype)sharedInstance;

- (void)downloadWithURLString:(NSString *)URLString;
- (nullable NSString *)JSStringWithURLString:(NSString *)URLString;

@end

NS_ASSUME_NONNULL_END
