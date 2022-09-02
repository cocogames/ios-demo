//
//  CSJDynamicLabelDecorator.h
//  CSJAdSDK
//
//  Created by Rush.D.xzj on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJDynamicAbstractDecorator.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicLabelDecorator : CSJDynamicAbstractDecorator

@property (nonatomic, strong) UILabel *label;

- (void)sizeToFitIfNeed;

@end

NS_ASSUME_NONNULL_END
