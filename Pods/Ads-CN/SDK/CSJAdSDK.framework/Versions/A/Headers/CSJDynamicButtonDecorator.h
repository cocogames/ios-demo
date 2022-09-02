//
//  CSJDynamicButtonDecorator.h
//  CSJAdSDK
//
//  Created by Rush.D.xzj on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJDynamicAbstractDecorator.h"
#import "CSJAdClickButton.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicButtonDecorator : CSJDynamicAbstractDecorator

@property (nonatomic, strong) CSJAdClickButton *button;
@end

NS_ASSUME_NONNULL_END
