//
//  BUDBModel.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/20.
//

#import <Foundation/Foundation.h>
#import "BUDBCoder.h"

NS_ASSUME_NONNULL_BEGIN

@protocol BUDBModel <NSObject>
@optional
- (instancetype)initWith_b1u2_DBCoder:(BUDBCoder *)coder;

- (void)encodeWith_b1u2_DBCoder:(BUDBCoder *)coder;

@end



NS_ASSUME_NONNULL_END
