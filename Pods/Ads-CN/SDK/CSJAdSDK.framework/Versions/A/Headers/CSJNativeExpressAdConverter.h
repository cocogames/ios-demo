//
//  CSJNativeExpressAdConverter.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/10/10.
//  Copyright © 2020 bytedance. All rights reserved.
//

// 把 NativeAd转换为NativeExpressAdView 的转换器

#import <Foundation/Foundation.h>

#import "CSJNativeAd.h"
#import "CSJNativeExpressAdView+Interval.h"
#import "CSJNativeExpressAdManager+Block.h"

NS_ASSUME_NONNULL_BEGIN

@class CSJNativeExpressAdConverter;

@protocol CSJNativeExpressAdConverterDelegate <NSObject>

- (id<CSJNativeExpressAdViewDelegate>)expressAdViewDelegateInNativeExpressAdConverter:(CSJNativeExpressAdConverter *)nativeExpressAdConverter;
- (id<CSJNativeExpressAdViewDismissDelegate>)expressAdViewDismissDelegateInNativeExpressAdConverter:(CSJNativeExpressAdConverter *)nativeExpressAdConverter;

- (void)nativeExpressAdConverter:(CSJNativeExpressAdConverter *)nativeExpressAdConverter nativeExpressAdViewArray:(NSArray <CSJNativeExpressAdView *> *)nativeExpressAdViewArray;

@end


@class CSJNativeExpressAdConverter;

@interface CSJNativeExpressAdConverter : NSObject

@property (nonatomic, weak) id<CSJNativeExpressAdConverterDelegate> delegate;

- (id)initWithAdSlot:(CSJAdSlot *)adSlot;
- (void)convertWithNativeAdArray:(NSArray <CSJNativeAd *> *)nativeAdArray;

@end

NS_ASSUME_NONNULL_END
