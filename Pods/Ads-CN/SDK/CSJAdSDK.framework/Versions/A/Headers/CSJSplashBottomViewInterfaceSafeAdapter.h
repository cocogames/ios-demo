//
//  CSJSplashBottomViewInterfaceSafeAdapter.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/9/26.
//

#import <Foundation/Foundation.h>
#import "CSJSplashBottomViewInterface.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJSplashBottomViewInterfaceSafeAdapter : NSObject <CSJSplashBottomViewInterface>
+ (instancetype)splashBottomViewInterfaceSafeAdapterWithConfiguration:(id<CSJSplashBottomViewInterface>)configuration;
@end

NS_ASSUME_NONNULL_END
