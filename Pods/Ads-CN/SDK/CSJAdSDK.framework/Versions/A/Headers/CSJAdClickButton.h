//
//  CSJAdClickButton.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/24.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "CSJDynamicClickInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJAdClickButton : UIButton
@property (nonatomic, strong, nullable) CSJDynamicClickInfo *clickInfo;

@end

NS_ASSUME_NONNULL_END
