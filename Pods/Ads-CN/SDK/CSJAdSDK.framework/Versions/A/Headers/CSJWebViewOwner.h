//
//  CSJWebViewOwner.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/3.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJWKWebViewClient.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJWebViewOwner : NSObject
@property (nonatomic, strong) CSJWKWebViewClient *webViewClient;
@property (nonatomic, assign) BOOL isCache;
- (id)initWithWebViewClient:(CSJWKWebViewClient *)webViewClient isCache:(BOOL)isCache;
@end

NS_ASSUME_NONNULL_END
