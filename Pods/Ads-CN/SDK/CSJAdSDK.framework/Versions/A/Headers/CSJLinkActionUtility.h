//
//  CSJLinkActionUtility.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/10/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface CSJLinkActionUtility : NSObject
/**
 This is a simplified version of @c [CSJLinkActionUtility bu_openURL:options:completion:], which provides empty @c options
 dictionary and nil @c completion.

 @param url A URL.
 */
+ (void)csj_openURL:(NSURL*)url;

/**
 This is a wrapper method that picks the correct version of @c [UIApplication  openURL:] (versus
 @c [UIApplication  openURL:options:completionHandler:]) base the iOS target.

 @param url A URL.
 @param options A dictionary of options to use when opening the URL.
 @param completion The block to execute with the results.
 */
+ (void)csj_openURL:(NSURL*)url
        options:(NSDictionary<UIApplicationOpenExternalURLOptionsKey, id> *)options
     completion:(void (^ __nullable)(BOOL success))completion;

/**
 Make sure that LSApplicationQueriesSchemes and Scheme are configured in Info.plist
 This is a simplified version of @c [UIApplication canOpenURL:]
 @param url A URL
 */
+ (BOOL)csj_canOpenURL:(NSURL *)url;


/**
 * Will open URL Notification
 */
+ (void)csj_postWillOpenURLNotification;

/**
 Did open URL Notification
 @param success Open URL if successs
 */
+ (void)csj_postDidOpenURLNotificationWith:(BOOL)success;
@end

NS_ASSUME_NONNULL_END
