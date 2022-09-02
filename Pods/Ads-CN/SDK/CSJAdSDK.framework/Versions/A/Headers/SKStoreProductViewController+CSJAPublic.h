//
//  SKStoreProductViewController+CSJAPublic.h
//  BUAppStore
//
//  Created by weihailong on 2019/8/9.
//

#import <StoreKit/StoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SKStoreProductViewController (BUAPublic)

/// 自定义 store view的frame.如果想使用SDK内部转场，还想改变弹出view的frame，可以对这个属性进行设置。
@property (nonatomic, assign) CGRect bu_customViewFrame;

/// 标识SKController是否为预加载而创建
@property (nonatomic, assign, readonly) BOOL bu_isCreatedForPreload;

@end

NS_ASSUME_NONNULL_END
