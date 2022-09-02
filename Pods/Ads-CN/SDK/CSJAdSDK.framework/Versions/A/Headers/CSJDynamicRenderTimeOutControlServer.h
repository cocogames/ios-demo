//
//  CSJDynamicRenderTimeOutControlServer.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/6/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface CSJDynamicRenderTimeOutControlServer : NSObject

- (void)startRenderWithDelayTime:(NSTimeInterval)delayTime
                     delayRender:(void (^)(void))completion;

@end

NS_ASSUME_NONNULL_END
