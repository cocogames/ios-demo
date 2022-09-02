//
//  BUDBOperation.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/20.
//

#import <Foundation/Foundation.h>
#import "BUDBField.h"
#import "BUDBTable.h"
#import "BUDBSecurityTable.h"

NS_ASSUME_NONNULL_BEGIN

@interface BUDatabase : NSObject

+ (instancetype)databaseWithName:(NSString *)name;

- (BOOL)createTableIfNeededWithName:(NSString *)name fields:(NSArray<BUDBField *> *)fields;

- (BUDBTable *)selectTableWithName:(NSString *)name;

- (__kindof BUDBTable *)selectTableWithName:(NSString *)name security:(BOOL)security;


+ (NSString *)rootPath;
@end

NS_ASSUME_NONNULL_END
