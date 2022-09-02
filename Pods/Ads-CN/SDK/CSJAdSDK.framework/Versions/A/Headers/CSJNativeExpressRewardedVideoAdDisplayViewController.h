//
//  CSJNativeExpressRewardedVideoAdDisplayViewController.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/8/8.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJVideoAdEnum.h"

@class CSJNativeExpressRewardedVideoAdView;

NS_ASSUME_NONNULL_BEGIN

@interface CSJNativeExpressRewardedVideoAdDisplayViewController : UIViewController

@property (nonatomic, assign) BUChildTransformDirection transformDirection;    //自己是否旋转
@property (nonatomic, assign) BOOL isRewardedVideo;

- (instancetype)initWithNativeExpressAdView:(CSJNativeExpressRewardedVideoAdView *)expressAdView;

@end

NS_ASSUME_NONNULL_END
