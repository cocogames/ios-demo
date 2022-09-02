//
//  CSJWebViewURLSchemeTaskDefine.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/9/16.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef BUWebViewURLSchemeTaskDefine_h
#define BUWebViewURLSchemeTaskDefine_h

@protocol CSJWebURLSchemeTaskHandler <NSObject>

- (instancetype _Nullable)initWithWebView:(WKWebView * _Nonnull)webView schemeTask:(id <WKURLSchemeTask>_Nonnull)task API_AVAILABLE(ios(11.0));

- (void)bu_startURLSchemeTask;

- (void)bu_stopURLSchemeTask;

@end


#endif /* BUWebViewURLSchemeTaskDefine_h */
