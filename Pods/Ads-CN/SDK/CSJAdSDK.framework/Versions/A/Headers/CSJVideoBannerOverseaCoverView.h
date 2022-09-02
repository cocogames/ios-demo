//
//  CSJVideoBannerOverseaCoverView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/9/27.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJBannerOverseaCoverView.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJVideoBannerOverseaCoverView : CSJBannerOverseaCoverView
@property (nonatomic, strong) UIImageView *videoMaskImage; // 高斯模糊背景图 v3300 add

@property (nonatomic, strong) UIView *videoBottomContentView; // 用于整体展示描述和下载按钮 v3300 add
@end

NS_ASSUME_NONNULL_END
