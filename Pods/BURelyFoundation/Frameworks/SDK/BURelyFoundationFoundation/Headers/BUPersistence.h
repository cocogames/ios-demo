//
//  BUPersistence.h
//  BUPersistence
//
//  Created by Chen Hong on 2017/1/10.
//  Copyright © 2017年 Chen Hong. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, BUPersistentType) {
    BUPersistentTypePlist,
    BUPersistentTypeMMAP,
    BUPersistentTypeCustom,
};

@interface BUPersistenceOption : NSObject

@property (nonatomic, assign) BUPersistentType type;

@property (nonatomic, assign) BOOL shouldRemoveAllObjectsOnMemoryWarning;

@property (nonatomic, assign) BOOL shouldRemoveAllObjectsWhenEnteringBackground;

@property (nonatomic, assign) BOOL supportNSCoding;

/// 4000 是否需要LRU删除缓存
@property (nonatomic, assign) BOOL supportLRU;

/// 4400 缓存个数，默认为最大整数不限制
@property (nonatomic, assign) NSUInteger capacityCount;

/// 4400 缓存大小，默认为10M，暂时不支持
@property (nonatomic, assign) NSUInteger capacitySize;

@end

@protocol BUPersistenceProtocol <NSObject>

- (NSArray *)allObjects;

- (void)allObjectsWithSafeBlock:(void(^)(NSArray *))block;

- (nullable id)objectForKey:(nullable NSString *)key;

- (nullable NSArray *)objectsForKeys:(NSArray *)keys;

- (void)updateObjectsForKeys:(NSArray *)keys WithBlock:(NSDictionary * (^)(NSArray *objects))block;

- (BOOL)setObject:(nullable id<NSCoding, NSObject>)object forKey:(nullable NSString *)key;

- (BOOL)hasObjectForKey:(nullable NSString *)key;

- (BOOL)removeAll;

- (BOOL)removeObjectsForKeys:(NSArray<NSString *> *)keys;

- (BOOL)save;

@optional
- (void)onMemoryWarning;

@end

@interface BUPersistence : NSObject <BUPersistenceProtocol>


+ (nullable instancetype)persistenceWithName:(NSString *)name;

/// 公共的BUPersistence 实例对象
/// 当不需要特定的设置name时,可以使用commonPersistence
/// @Warning , 当使用commonPersistence时,  key值的设置请注意唯一性,防止key值覆盖的问题发生
+ (nullable instancetype)commonPersistence;

+ (nullable instancetype)persistenceWithName:(NSString *)name option:(BUPersistenceOption *)option;

+ (NSString *)cacheDirectory;


#pragma mark - Publick
+ (void)setSDKVersion:(NSString *)sdkVersion;
+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
