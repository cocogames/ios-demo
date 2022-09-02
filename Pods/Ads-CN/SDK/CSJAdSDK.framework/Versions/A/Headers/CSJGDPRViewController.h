//
//  CSJGDPRViewController.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2020/1/17.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJGDPRViewController : UIViewController

@property (nonatomic, copy) dispatch_block_t confirm;

@property (nonatomic, copy) dispatch_block_t cancel;

- (instancetype)initViewControllerWithContentUrl:(NSString *) contentUrl;

@end

NS_ASSUME_NONNULL_END
