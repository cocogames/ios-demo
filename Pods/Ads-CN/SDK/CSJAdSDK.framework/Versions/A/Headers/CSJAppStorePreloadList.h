//
//  CSJAppStorePreloadList.h
//  BUAppStore
//
//  Created by Siwant on 2018/9/10.
//

#import <Foundation/Foundation.h>
#import "CSJAppStorePreloadItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJAppStorePreloadList : NSObject

@property (nonatomic, assign) NSUInteger maxPreloadCount;

- (nullable CSJAppStorePreloadItem *)preloadItemForAppID:(NSString *)appId;

- (nullable CSJAppStorePreloadItem *)duplicatedPreloadItemForAppID:(NSString *)appId;

- (void)addItem:(CSJAppStorePreloadItem *)item;

- (void)removeItem:(CSJAppStorePreloadItem *)item;

- (void)removeItemBySKController:(SKStoreProductViewController *)controller;

- (void)removeItemByAppID:(NSString *)appId;

- (void)clearCache;

@end

NS_ASSUME_NONNULL_END
