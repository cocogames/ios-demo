//
//  CSJJSB3ExecuteUnitViewModel.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/6/9.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJJSB3ExecuteUnitModel.h"
#import "CSJAdInfoViewModel.h"

@class WKWebView;
NS_ASSUME_NONNULL_BEGIN

@interface CSJJSB3ExecuteUnitViewModel : NSObject

@property (nonatomic, strong, readonly) CSJJSB3ExecuteUnitModel *jsb3ExecuteUnitModel;
@property (nonatomic, strong) CSJAdInfoViewModel *infoViewModel;

- (id)initWithModel:(CSJJSB3ExecuteUnitModel *)model;

- (void)jsInteractiveNativeWithTarget:(id)target inWebView:(WKWebView *)webView;
- (void)nativeCallJSWithParameters:(NSDictionary *)parameters inWebView:(WKWebView *)webView;

@end

NS_ASSUME_NONNULL_END
