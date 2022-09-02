//
//  BUTrackerDispatchManager.h
//  AFNetworking
//
//  Created by Rush.D.Xzj on 2022/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BUTrackerDispatchManager : NSObject

- (void)setup;

- (void)applog_eventData:(NSDictionary *)params;
- (void)applog_eventData:(NSDictionary *)params clockType:(NSInteger)clockType;
- (void)stats_eventData:(NSDictionary *)params;
- (void)stats_eventData:(NSDictionary *)params clockType:(NSInteger)clockType;


#pragma mark - Signal
+ (instancetype)sharedInstance;



@end

NS_ASSUME_NONNULL_END
