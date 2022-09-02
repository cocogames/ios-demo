//
//  BUDBCondition.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BUDBConditionType) {
    BUDBConditionTypeEqual,
    BUDBConditionTypeNotEqual,
    BUDBConditionTypeGrand,
    BUDBConditionTypeGrandOrEqual,
    BUDBConditionTypeLess,
    BUDBConditionTypeLessOrEqual,
    BUDBConditionTypeIn,
    BUDBConditionTypeNotIn,
    BUDBConditionTypeLike,
};

typedef NS_ENUM(NSUInteger, BUDBConditionConnector) {
    BUDBConditionConnectorOR,
    BUDBConditionConnectorAND,
};

@class BUDBSingleCondition;

@interface BUDBCondition : NSObject

- (NSString *)conditionString;

@end

@interface BUDBSingleCondition : BUDBCondition

@property (nonatomic, copy) NSString *field;

@property (nonatomic, strong, nullable) id value;

@property (nonatomic, assign) BUDBConditionType type;

@end

@interface BUDBGroupCondition : BUDBCondition

- (instancetype)initWithCondition:(BUDBSingleCondition *)condition;

@property (nonatomic, assign) BUDBConditionConnector connector;

- (void)addCondition:(BUDBSingleCondition *)condition;

@end

NS_ASSUME_NONNULL_END
