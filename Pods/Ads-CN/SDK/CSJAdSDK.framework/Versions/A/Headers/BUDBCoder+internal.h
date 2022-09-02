//
//  BUDBCoder.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/20.
//

#import <Foundation/Foundation.h>
#import "BUDBCoder.h"

NS_ASSUME_NONNULL_BEGIN

@interface BUDBCoder ()

- (NSString *)convertInsertSQLWithTableNamed:(NSString *)name;

- (NSString *)convertUpdateSQLWithTableNamed:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
