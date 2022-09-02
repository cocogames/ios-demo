//
//  WKWebView+CSJDAdapter.h
//  CSJAdSDK
//
//  Created by 李盛 on 2020/4/9.
//  Copyright © 2020 bytedance. All rights reserved.
//


#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface WKWebView (BUDAdapter)
+ (void)_hookHandlesURLScheme;
@end

NS_ASSUME_NONNULL_END
