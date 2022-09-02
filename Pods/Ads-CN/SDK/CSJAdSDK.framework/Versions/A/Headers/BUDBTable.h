//
//  BUDBTable.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/20.
//

#import <Foundation/Foundation.h>
#import "BUDBCondition.h"
#import "BUDBModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, BUDBOrder) {
    BUDBOrderASC = -1,
    BUDBOrderDesc = 1,
};

typedef struct {
    BUDBOrder order;
    const char *field;
} BUDBOrderBy;

static inline
BUDBOrderBy BUDBOrderByMake(BUDBOrder order, NSString *field) {
    return (BUDBOrderBy){order, [field UTF8String]};
}

typedef struct {
    int offset;
    int count;
} BUDBLimit;

static inline BUDBLimit BUDBLimitMake(int offset, int count) {
    return (BUDBLimit){offset, count};
}

extern const BUDBOrderBy BUDBOrderByNone;
extern const BUDBOrderBy BUDBOrderByCreateTimeASC;
extern const BUDBOrderBy BUDBOrderByCreateTimeDESC;

extern const BUDBLimit BUDBLimitNone;

//extern NSString *const BUDBTableCreateTimeField;

@interface BUDBTable : NSObject

@property (nonatomic, copy, readonly) NSString *tableName;
// 插入或者更新
- (BOOL)insert:(id<BUDBModel>)obj;

- (BOOL)update:(id<BUDBModel>)obj where:(BUDBCondition *)where;

- (BOOL)updateWithSqlString:(NSString *)sqlString where:(BUDBCondition *)where;

- (NSInteger)selectAllCount;
- (NSArray<id<BUDBModel>> *)selectWithWhere:(BUDBCondition *_Nullable)where orderBy:(BUDBOrderBy)orderBy limit:(BUDBLimit)limit class:(Class)class;

- (BOOL)deleteWithWhere:(BUDBCondition *_Nullable)where;

- (BOOL)deleteAll;
@end

NS_ASSUME_NONNULL_END
