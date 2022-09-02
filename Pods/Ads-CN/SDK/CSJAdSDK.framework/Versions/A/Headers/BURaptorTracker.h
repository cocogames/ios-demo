//
//  BURaptorTracker.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/5/14.
//

#import <Foundation/Foundation.h>

#import "BURaptorTrackerDefine.h"


NS_ASSUME_NONNULL_BEGIN

@interface BURaptorTracker : NSObject

#pragma mark - Class Method
+ (void)setupRaptorTrack;



#pragma mark - Public
- (void)setup;
- (void)eventData:(NSDictionary *)data;

#pragma mark - Signal
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
