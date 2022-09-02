//
//  BUDBTable+internal.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/20.
//

#import <Foundation/Foundation.h>
#import "BUDBTable.h"
#import <sqlite3.h>

NS_ASSUME_NONNULL_BEGIN
@interface BUDBTable ()

- (instancetype)initWithDatabasePath:(NSString *)path tableName:(NSString *)tableName sqlite:(sqlite3 *)sqlite;

@end

NS_ASSUME_NONNULL_END
