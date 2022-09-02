//
//  CSJNativeExpressVideoAdParentViewController.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/7/15.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJMaterialMeta;

@interface CSJNativeExpressVideoAdParentViewController : UIViewController
@property (nonatomic, strong) CSJMaterialMeta *materialMeta;
@property (nonatomic, assign) BOOL isExpress;
- (void)removeLoading;

@end

NS_ASSUME_NONNULL_END
