//
//  CSJSKOverlayProtocol.h
//  CSJAdSDK
//
//  Created by Eason on 2021/7/27.
//

#ifndef BUSKOverlayProtocol_h
#define BUSKOverlayProtocol_h

#import <Foundation/Foundation.h>

API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos) __TVOS_PROHIBITED
@protocol CSJSKOverlayCallBackDelegate <NSObject>

@optional

- (void)storeOverlay:(NSObject *_Nonnull)overlay didFailToLoadWithError:(NSError *_Nullable)error NS_SWIFT_NAME(storeOverlayDidFailToLoad(_:error:));
- (void)storeOverlay:(NSObject *_Nonnull)overlay willStartPresentation:(NSObject *_Nullable)transitionContext NS_SWIFT_NAME(storeOverlayWillStartPresentation(_:transitionContext:));
- (void)storeOverlay:(NSObject *_Nonnull)overlay didFinishPresentation:(NSObject *_Nullable)transitionContext NS_SWIFT_NAME(storeOverlayDidFinishPresentation(_:transitionContext:));
- (void)storeOverlay:(NSObject *_Nonnull)overlay willStartDismissal:(NSObject *_Nullable)transitionContext NS_SWIFT_NAME(storeOverlayWillStartDismissal(_:transitionContext:));
- (void)storeOverlay:(NSObject *_Nonnull)overlay didFinishDismissal:(NSObject *_Nullable)transitionContext NS_SWIFT_NAME(storeOverlayDidFinishDismissal(_:transitionContext:));

@end

API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos) __TVOS_PROHIBITED
@protocol CSJSKOverlayAppConfigurationDelegate <NSObject>

@optional

/// Creates a new app overlay configuration that will show an app from the App Store.
/// @param appIdentifier the app identifier of the app to show.
/// @param position the desired position of the overlay.
- (instancetype _Nullable)initWithAppIdentifier:(NSString *_Nonnull)appIdentifier position:(NSInteger)position NS_SWIFT_NAME(init(appIdentifier:position:));

/// The identifier of the app that will be shown.
@property (nonatomic, retain) NSString * _Nullable appIdentifier;

/// A token representing an App Analytics campaign.
@property (nonatomic, retain, nullable) NSString *campaignToken;

/// The provider token for the developer that created the app being presented.
@property (nonatomic, retain, nullable) NSString *providerToken;

/// The position an overlay will show at on screen.
@property (nonatomic) NSInteger position;

/// Allows the user to interactively dismiss an overlay.
@property (nonatomic) BOOL userDismissible;

- (void)setAdditionalValue:(nullable id)value forKey:(NSString *_Nonnull)key;

- (nullable id)additionalValueForKey:(NSString *_Nonnull)key NS_WARN_UNUSED_RESULT;

@end

API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos) __TVOS_PROHIBITED
@protocol CSJSKOverlayDelegate <NSObject>

@optional

/// Creates an overlay with the provided configuration.
/// @param configuration the configuration for the overlay.
- (instancetype _Nullable )initWithConfiguration:(NSObject *_Nullable)configuration;

#if !TARGET_OS_OSX
/// Attempts to present an app overlay in a `UIWindowScene`.
- (void)presentInScene:(UIWindowScene *_Nonnull)scene API_AVAILABLE(ios(14.0)) NS_EXTENSION_UNAVAILABLE("Overlays are not available in extensions");

#endif

/// A delegate for overlay events.
@property (nonatomic, weak, nullable) id <CSJSKOverlayCallBackDelegate> delegate;

/// The overlay configuration.
@property (readonly, copy) NSObject * _Nullable configuration;

@end

API_AVAILABLE(ios(14.0)) API_UNAVAILABLE(macos, watchos) __TVOS_PROHIBITED
@protocol BUSKOverlayClassDelegate

@optional

/// Dismisses an overlay being presented in a `UIWindowScene`.
+ (void)dismissOverlayInScene:(UIWindowScene *_Nullable)scene API_AVAILABLE(ios(14.0)) NS_EXTENSION_UNAVAILABLE("Overlays are not available in extensions");

@end

#endif /* BUSKOverlayProtocol_h */
