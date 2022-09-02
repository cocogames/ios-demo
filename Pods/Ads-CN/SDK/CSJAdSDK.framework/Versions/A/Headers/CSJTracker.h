//
//  CSJTracker.h
//  CSJAdSDK
//
//  Created by 曹清然 on 2017/5/31.
//  Copyright © 2017年 chenren. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJTracker : NSObject
+ (instancetype)sharedTracker;
- (void)eventData:(NSDictionary*)event;
@end

NS_ASSUME_NONNULL_END
