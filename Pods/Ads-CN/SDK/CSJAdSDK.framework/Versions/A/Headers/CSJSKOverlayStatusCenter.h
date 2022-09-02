//
//  BUAppStatusCenter.h
//  CSJAdSDK
//
//  Created by Eason on 2021/6/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos) __TVOS_PROHIBITED
@protocol CSJSKOverlayStatusDelegate <NSObject>

@optional
- (void)storeOverlayDidFailToLoadWithError:(NSError *)error NS_SWIFT_NAME(storeOverlayDidFailToLoad(error:));
- (void)storeOverlayDidFinishPresentation NS_SWIFT_NAME(storeOverlayDidFinishPresentation());
- (void)storeOverlayDidClick NS_SWIFT_NAME(storeOverlayDidClick());
- (void)storeOverlayDidClickGet NS_SWIFT_NAME(storeOverlayDidClickGet());

@end

API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos) __TVOS_PROHIBITED
@interface CSJSKOverlayStatusCenter : NSObject

@property (nonatomic, weak) id<CSJSKOverlayStatusDelegate> delegate;

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
