//
//  SKStoreProductViewController+CSJAPrivate.h
//  BUAppStore
//
//  Created by weihailong on 2019/8/9.
//

#import <StoreKit/StoreKit.h>

@interface SKStoreProductViewController (BUAPrivate)

@property (nonatomic, assign) BOOL bu_isFirstLoad;
@property (nonatomic, assign) BOOL bu_isCreatedForPreloadInner;

@end

