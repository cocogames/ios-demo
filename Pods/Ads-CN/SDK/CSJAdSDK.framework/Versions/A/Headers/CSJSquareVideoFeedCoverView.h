//
//  CSJSquareVideoFeedCoverView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/9/20.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJFeedCoverView.h"
#import "CSJVideoAdView+CSJPlayer.h"
#import "CSJNativeAdRelatedView.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJSquareVideoFeedCoverView : CSJFeedCoverView

@property (nonatomic, strong) CSJNativeAdRelatedView *nativeAdRelatedView;

@end

NS_ASSUME_NONNULL_END
