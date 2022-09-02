//
//  CSJWebVC.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/12/5.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJWKWebViewClient.h"

NS_ASSUME_NONNULL_BEGIN
@class CSJMaterialMeta;
@interface CSJWebVC : UIViewController

@property (nonatomic, copy) dispatch_block_t closeBlock;
@property (nonatomic, assign) BOOL showCopyLinkButton;

- (instancetype)initWithMaterialMeta:(CSJMaterialMeta *)material;
- (instancetype)initWithSize:(CGSize)size;
- (void)bu_loadRequest:(NSURL *)requestURL;
@end
NS_ASSUME_NONNULL_END
