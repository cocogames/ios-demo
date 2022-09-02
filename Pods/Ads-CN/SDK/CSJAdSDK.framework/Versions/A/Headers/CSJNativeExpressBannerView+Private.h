//
//  CSJNativeExpressBannerView+Private.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/10/13.
//  Copyright © 2020 bytedance. All rights reserved.
//


#import "CSJNativeExpressBannerView.h"
#import "CSJNativeExpressAdManager+Block.h"
#import "CSJNativeExpressAdView+Interval.h"
#import "CSJNativeExpressAdView+Video.h"
#import "CSJNativeExpressAdView.h"
#import "CSJAdSlot.h"
#import "CSJAdSDKError.h"
#import "CSJUSettingService.h"
#import "CSJUnionMacros.h"
#import "CSJAdSlot+Private.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJNativeExpressBannerView ()
@property (nonatomic, weak) UIViewController *rootViewController;
@property (nonatomic, strong, nullable) CSJNativeExpressAdView *expressAdView;
@property (nonatomic, strong, nullable) CSJNativeExpressAdView *anotherExpressAdView;
@property (nonatomic, assign) CGSize adSize;


@property (nonatomic, assign, readwrite) NSInteger interval;

@property (nonatomic, strong) CSJNativeExpressAdManager *nativeExpressAdManager;
@property (nonatomic, strong, nullable) CSJNativeExpressAdManager *anotherAdManager;//view复用，只用一个manager无法实现轮播
@property (nonatomic, strong) BUTimer *timer;
@property (nonatomic, assign) NSInteger playItems;
@property (nonatomic, assign) BOOL isCarousel;
@property (nonatomic, copy) NSString *lastAdm;

// 默认是动态布局，外界可以更改
@property (nonatomic, assign) BUAdSlotRenderType realSlotRenderType;

@end

NS_ASSUME_NONNULL_END
