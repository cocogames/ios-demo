//
//  CSJAdMonitorManager.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/9/16.
//

#import <Foundation/Foundation.h>
#import "CSJExpressAdMonitor.h"
#import "CSJUserMonitor.h"
#import "CSJSDKMonitor.h"
#import "CSJThreadMonitor.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJAdMonitorManager : NSObject

@property (nonatomic, strong, readonly) CSJExpressAdMonitor *expressAdMonitor;
@property (nonatomic, strong, readonly) CSJUserMonitor *userMonitor;
@property (nonatomic, strong, readonly) CSJSDKMonitor *sdkMonitor;
@property (nonatomic, strong, readonly) CSJThreadMonitor *threadMonitor;

#pragma mark - Signal
+ (instancetype)sharedInstance;
- (instancetype)init UNAVAILABLE_ATTRIBUTE;
+ (instancetype)new UNAVAILABLE_ATTRIBUTE;

@end

NS_ASSUME_NONNULL_END
