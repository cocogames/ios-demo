//
//  BUDBField.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BUDBFieldType) {
    BUDBFieldTypeUNKNOWN = 0,
    BUDBFieldTypeREAL = 1,
    BUDBFieldTypeINTEGER = 2,
    BUDBFieldTypeTEXT = 3,
};

@interface BUDBField : NSObject

@property (nonatomic, copy) NSString *name;

@property (nonatomic, assign) BUDBFieldType type;

@property (nonatomic, assign) BOOL primary;

@property (nonatomic, assign) BOOL notNull;

@property (nonatomic, copy, readonly) NSString *typeDescription;

- (NSString *)convertToSqlString;

+ (NSArray<NSString *> *)convertToSqlStringWithFields:(NSArray<BUDBField *> *)fields;

- (BOOL)hasDefault;
- (NSString *)defaultSqlString;

@end

NS_ASSUME_NONNULL_END
