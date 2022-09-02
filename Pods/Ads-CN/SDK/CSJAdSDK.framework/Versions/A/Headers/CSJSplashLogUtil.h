//
//  CSJSplashLogUtil.h
//  CSJAdSDK
//
//  Created by ByteDance on 2022/5/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const CSJLogTag_Splash_Init_Load;
FOUNDATION_EXPORT NSString * const CSJLogTag_Splash_Total_Load;
FOUNDATION_EXPORT NSString * const CSJLogTag_Splash_Meta_Load;
FOUNDATION_EXPORT NSString * const CSJLogTag_Splash_Image_Load;
FOUNDATION_EXPORT NSString * const CSJLogTag_Splash_Video_Load;
FOUNDATION_EXPORT NSString * const CSJLogTag_Splash_Template_Load;
FOUNDATION_EXPORT NSString * const CSJLogTag_Splash_Render;



@interface CSJSplashLogUtil : NSObject

+ (instancetype)sharedInstance;

- (void)beginWithTag:(NSString *)tag  logStr:(NSString *)logStr;

- (void)endWithTag:(NSString *)tag  logStr:(NSString *)logStr;

@end

NS_ASSUME_NONNULL_END
