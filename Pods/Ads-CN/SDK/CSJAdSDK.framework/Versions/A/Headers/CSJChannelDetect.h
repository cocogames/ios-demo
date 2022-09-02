//
//  CSJChannelDetect.h
//  CSJAdSDK
//
//  Created by shenqichen on 2022/6/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJChannelDetect : NSObject

+ (instancetype)sharedInstance;

- (void)collectInfo:(id)delegate caller:caller slot:(CSJAdSlot*)slot;

@end

NS_ASSUME_NONNULL_END
