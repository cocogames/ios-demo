//
//  CSJSKOverlayManager.h
//  CSJAdSDK
//
//  Created by Eason on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos) __TVOS_PROHIBITED
@protocol CSJSKOverlayManagerDelegate <NSObject>

@optional

- (void)storeOverlayDidFailToLoadWithError:(NSError *)error NS_SWIFT_NAME(storeOverlayDidFailToLoad(error:));
- (void)storeOverlayWillStartPresentation NS_SWIFT_NAME(storeOverlayWillStartPresentation());
- (void)storeOverlayDidFinishPresentation NS_SWIFT_NAME(storeOverlayDidFinishPresentation());
- (void)storeOverlayWillStartDismissal NS_SWIFT_NAME(storeOverlayWillStartDismissal());
- (void)storeOverlayDidFinishDismissal NS_SWIFT_NAME(storeOverlayDidFinishDismissal());

@end

API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos) __TVOS_PROHIBITED
@interface CSJSKOverlayManager : NSObject

+ (BOOL)hadShowSKOverlay;
+ (void)showOverlayWithSKANModel:(CSJAdInfoViewModel *)model;
+ (void)reShowOverlayWithIndexModel;
+ (void)dismissOverlay;
+ (void)setDelegateObjct:(NSObject<CSJSKOverlayManagerDelegate> *)objct;

@end

NS_ASSUME_NONNULL_END
