//
//  CSJStatsTracker.h
//  CSJAdSDK
//
//  Created by Siwant on 2019/11/12.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJStatsTracker : NSObject
/// 默认离线模式，可配置实时模式，用完之后依旧需要配置离线模式
@property (nonatomic, assign) NSInteger clockType;
@property (nonatomic, copy) NSString *batchURLString;
+ (instancetype)sharedTracker;

/// 默认BUTrackerClockTypeInit | BUTrackerClockTypeAppWillEnterForground | BUTrackerClockTypeAppDidEnterBackground
- (void)eventData:(NSDictionary*)event;
- (void)eventData:(NSDictionary*)event clockType:(NSInteger)clockType;
@end

NS_ASSUME_NONNULL_END
