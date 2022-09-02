//
//  CSJAppStorePreloadItemPendant.h
//  CSJAdSDK
//
//  Created by Eason on 2021/2/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^BUAppStoreRootCallBack)(void);

@interface CSJAppStorePreloadItemPendant : NSObject
@property (nonatomic, copy) BUAppStoreRootCallBack _Nullable callBackBlock;
@end

NS_ASSUME_NONNULL_END
