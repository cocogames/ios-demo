//
//  CSJWebViewController+Luban.h
//  CSJAdSDK
//
//  Created by Siwant on 2019/7/2.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import "CSJWebViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJWebViewController (Luban)
@property (nonatomic, assign) BOOL isLuban;//是否为鲁班回流页
@property (nonatomic, copy) NSDictionary *luban_json;//鲁班回流页广告物料
@property (nonatomic, copy) dispatch_block_t loadLubanJsonFail;//加载鲁班广告物料失败
@end

NS_ASSUME_NONNULL_END
