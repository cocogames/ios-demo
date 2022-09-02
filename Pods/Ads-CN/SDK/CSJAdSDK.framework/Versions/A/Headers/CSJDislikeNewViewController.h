//
//  CSJDislikeNewViewController.h
//  CSJAdSDK
//
//  Created by xzj on 2020/4/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJDislikeWords.h"

NS_ASSUME_NONNULL_BEGIN
@class CSJMaterialMeta;
@interface CSJDislikeNewViewController : UIViewController

@property (nonatomic, copy, nullable) void(^dislikeResultBlock)(NSArray<CSJDislikeWords *> * nullable, NSString *comment);
@property (nonatomic, copy) dispatch_block_t cancelBlock;

- (instancetype)initDislikeWithMaterial:(CSJMaterialMeta *)meta startFrame:(CGRect)startFrame;

@end

NS_ASSUME_NONNULL_END
