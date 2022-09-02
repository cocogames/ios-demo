//
//  CSJLogRateConfigModel.h
//  CSJAdSDK
//
//  Created by Willie on 2021/1/8.
//

#import <Foundation/Foundation.h>
#import "CSJModelSerialization.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJLogRateConfigModel : NSObject <CSJModelSerialization>

@property (nonatomic, assign) float globalRate;
@property (nonatomic, assign) float classPropertyRate;

@end

NS_ASSUME_NONNULL_END
