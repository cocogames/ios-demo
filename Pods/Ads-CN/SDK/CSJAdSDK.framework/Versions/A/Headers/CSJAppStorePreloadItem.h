//
//  CSJAppStorePreloadItem.h
//  BUAppStore
//
//  Created by Siwant on 2018/9/10.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "CSJSKANStoreProductModel.h"
#import "CSJAdSDKDefines+Private.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUAppStorePreloadState) {
    BUAppStorePreloadPend   = 0,
    BUAppStorePreloading    = 1,
    BUAppStorePreloadFinish = 2,
    BUAppStorePreloadError  = 3,
    BUAppStorePreloadBreak  = 4,
};

@interface CSJAppStorePreloadItem : NSObject

@property (nonatomic, assign) BOOL isPresentAnimated;
@property (nonatomic, assign) BOOL isDismissAnimated;
@property (nonatomic, assign) BOOL isDuplicated;
@property (nonatomic, readonly, copy) NSString *appID;
@property (nonatomic, readonly, strong) id<CSJAd> adModel;

@property (nonatomic, readonly, assign) BUAppStorePreloadState state;
@property (nonatomic, readonly, strong) SKStoreProductViewController *productController;

@property (nonatomic, strong) CSJSKANStoreProductModel *adNetworkModel;

/** 标记是否为复用过的 item. preload 过程中，点击直接打开，复用这个正在 preload 的 item，而不是重新 new 一个。*/
@property (nonatomic, assign) BOOL isUsePreloading;

///3501 add 各个预加载对象分别记录状态
@property (nonatomic, assign) BOOL presenting;

///3501 add 各个预加载对象分别记录状态
@property (nonatomic, assign) BOOL visible;

- (instancetype)initWithAppID:(NSString *)appId adModel:(id<CSJAd>)adModel;

- (void)loadProductCompletion:(nullable void(^)(BOOL result, NSError * __nullable error, CSJAppStorePreloadItem * _Nonnull item))completion;

- (void)stopLoad;

- (void)openProductByController:(UIViewController *)controller
              presentCompletion:(void (^ __nullable)(void))presentCompletion
              dismissCompletion:(void (^ __nullable)(CSJAppStorePreloadItem* item))dismissCompletion;

@end

@interface CSJAppStorePreloadItem (Tracker)
/// 预加载时间戳
- (void)resetLoadTimestamp;

- (void)startPreloadTimeTrackEvent;

- (void)stopPreloadTimeTrackEvent;


/// 显示时间戳
- (void)resetShowTimestamp;

- (void)startShowTimeTrackEvent;

- (void)stopShowTimeTrackEvent;

// 新
//- (void)resetTimestamp;
//
//- (void)startPreloadTimeTrackEvent;
//
//- (void)stopPreloadTimeTrackEvent;
@end

NS_ASSUME_NONNULL_END
