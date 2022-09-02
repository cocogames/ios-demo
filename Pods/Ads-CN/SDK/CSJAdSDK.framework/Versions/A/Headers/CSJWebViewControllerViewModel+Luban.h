//
//  CSJWebViewControllerViewModel+Luban.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//


#import "CSJWebViewControllerViewModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJWebViewControllerViewModel (Luban)
@property (nonatomic, assign) BOOL isLuban;//是否为鲁班回流页
@property (nonatomic, copy) NSDictionary *luban_json;//鲁班回流页广告物料
@property (nonatomic, copy) dispatch_block_t loadLubanJsonFail;//加载鲁班广告物料失败
@property (nonatomic, strong) NSMutableArray *luban_product_ids;//鲁班回流页特卖商品ids

- (void)configLubanInfoWithURL:(NSURL *)requestURL;
- (void)registerLubanJSBridgePlugin;
- (void)preloadLubanData;

@end

NS_ASSUME_NONNULL_END
