//
//  CSJEmptyCoverView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/9/25.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJCoverView.h"

NS_ASSUME_NONNULL_BEGIN

// 激励/全屏视频兜底用的，理论上是可以不用，因为最后是走自渲染的VC，不会使用到动态布局view
@interface CSJEmptyCoverView : CSJCoverView

@end

NS_ASSUME_NONNULL_END
