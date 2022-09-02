//
//  NSObject+BUDBModel.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/21.
//

#import <Foundation/Foundation.h>
#import "BUDBModel.h"

NS_ASSUME_NONNULL_BEGIN

@class BUDBSecurityTable;

@protocol BUDBAutoModel <BUDBModel>
@optional
+ (NSString *)b1u2_databaseName;

+ (NSString *)b1u2_tableName;

+ (NSArray<NSString *> *)b1u2_ignoreProperties;

+ (NSString *)b1u2_primaryKey;

+ (instancetype)b1u2_selectLastOneFromTable;

- (void)b1u2_insertOrUpdateToTable;

- (void)b1u2_deleteFromTable;

- (BUDBSecurityTable *)b1u2_table;

+ (BUDBSecurityTable *)b1u2_table;
@end

@interface NSObject (BUDBModel)

@end

NS_ASSUME_NONNULL_END
