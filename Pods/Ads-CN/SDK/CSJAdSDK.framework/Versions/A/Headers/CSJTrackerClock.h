//
//  CSJTrackerClock.h
//  CSJAdSDK
//
//  Created by Siwant on 2019/11/12.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CSJTrackerProxy;

NS_ASSUME_NONNULL_BEGIN

@interface CSJTrackerClock : NSObject
@property (nonatomic, assign) NSInteger clockType;
@property (nonatomic, copy) NSString *sentNotification;

- (instancetype)initWithTrackerProxy:(CSJTrackerProxy *)trackerProxy;
@end

NS_ASSUME_NONNULL_END
