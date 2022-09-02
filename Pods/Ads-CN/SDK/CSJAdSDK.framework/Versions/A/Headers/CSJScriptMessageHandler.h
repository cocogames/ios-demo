//
//  CSJScriptMessageHandler.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/5/28.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
// https://www.jianshu.com/p/6ba2507445e4
// 原有的引用关系
// selfVC 强引用 WKWebView 强引用WKWebViewConfiguration 强引用WKUserContentController 强引用scriptMessageHandler(self) 导致循环引用
// 修改后的引用关系
// selfVC 强引用 WKWebView 强引用WKWebViewConfiguration 强引用WKUserContentController 强引用scriptMessageHandler(KSAdScriptMessageHandler)弱引用scriptMessageHandler(self) 打破循环引用
NS_ASSUME_NONNULL_BEGIN

@interface CSJScriptMessageHandler : NSObject <WKScriptMessageHandler>

@property (nonatomic, weak) id<WKScriptMessageHandler> realScriptMessageHandler;

- (id)initWithHandler:(id<WKScriptMessageHandler>)handle;

@end

NS_ASSUME_NONNULL_END
