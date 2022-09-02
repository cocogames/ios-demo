//
//  CSJDislikeViewController.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/10.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJDislikeWords.h"

typedef NS_ENUM(NSInteger, BUShowPosition) {
    BUShowPosition_Bottom = 0,// 从底部弹出（默认）
    BUShowPosition_Middle = 1,// 居中展示
};

NS_ASSUME_NONNULL_BEGIN

@interface CSJDislikeViewController : UIViewController

@property (nonatomic, copy, nullable) void(^dislikeResult)(NSArray<CSJDislikeWords *> * nullable);

@property (nonatomic, copy) dispatch_block_t cancel;

@property (nonatomic, assign) BUShowPosition position;

- (instancetype)initViewControllerWithReasons:(NSArray<CSJDislikeWords *> *) filterWords;

@end

NS_ASSUME_NONNULL_END
