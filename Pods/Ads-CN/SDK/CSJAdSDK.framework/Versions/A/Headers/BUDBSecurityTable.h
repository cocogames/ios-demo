//
//  BUDBSecurityTable.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/21.
//

#import "BUDBTable.h"

NS_ASSUME_NONNULL_BEGIN

@interface BUDBSecurityTable : BUDBTable

- (void)insert:(id<BUDBModel>)obj callback:(void(^)(BOOL success))callback;

- (void)update:(id<BUDBModel>)obj where:(BUDBCondition *)where callback:(void(^)(BOOL success))callback;

- (void)selectWithWhere:(BUDBCondition *_Nullable)where orderBy:(BUDBOrderBy)orderBy limit:(BUDBLimit)limit class:(Class)class callback:(void(^)(NSArray<id<BUDBModel>> *list))callback;

- (void)deleteWithWhere:(BUDBCondition *)where callback:(void(^)(BOOL success))callback;

@end

NS_ASSUME_NONNULL_END
