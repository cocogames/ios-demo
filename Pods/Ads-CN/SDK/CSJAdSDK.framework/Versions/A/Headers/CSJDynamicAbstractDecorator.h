//
//  CSJDynamicAbstractDecorator.h
//  CSJAdSDK
//
//  Created by Rush.D.xzj on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJDynamicAbstractView;

@interface CSJDynamicAbstractDecorator : NSObject

@property (nonatomic, weak) CSJDynamicAbstractView *dynamicAbstractView;
@property (nonatomic, copy) NSString *brickType;
// default = YES;
@property (nonatomic, assign) BOOL needUsePadding;

- (void)render;

- (void)updateTheme;


- (CGRect)subComponentFrame;

@end

NS_ASSUME_NONNULL_END
