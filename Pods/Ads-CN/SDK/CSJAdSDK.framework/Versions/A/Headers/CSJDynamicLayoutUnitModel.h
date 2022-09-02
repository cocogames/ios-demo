//
//  CSJDynamicLayoutUnitModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/24.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJDynamicBrickModel.h"
#import "CSJDynamicSDKAnalysisHeader.h"


@class CSJDynamicCreativeModel;

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicLayoutUnitModel : NSObject

// SDK render
// 记录一下，方便开发用
@property (nonatomic, copy) NSDictionary *originDictionary;
@property (nonatomic, copy) NSDictionary *originDictionary_notIncludeChildren;

@property (nonatomic, assign) CGFloat buDynamic_x; // 相对于屏幕的 x
@property (nonatomic, assign) CGFloat buDynamic_y; // 相对于屏幕的 y
@property (nonatomic, assign) CGFloat buDynamic_width;
@property (nonatomic, assign) CGFloat buDynamic_height;
@property (nonatomic, assign) CGFloat buDynamic_remainWidth;
@property (nonatomic, copy) NSString *buDynamic_id;
@property (nonatomic, strong) CSJDynamicBrickModel *buDynamic_brick;
// 这里把children给忽略了

- (id)initWithDictionary:(NSDictionary *)dictionary;


#pragma mark - SDK Analysis

@property (nonatomic, copy) NSString *componentId;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSArray <NSArray <CSJDynamicLayoutUnitModel *> *> *children;
@property (nonatomic, readonly) NSArray <CSJDynamicLayoutUnitModel *> *realChildArray;
@property (nonatomic, copy) NSDictionary *values;
@property (nonatomic, copy) NSDictionary *customComponentDefaultValues;

@property (nonatomic, copy) NSDictionary *themeValues;
@property (nonatomic, weak) CSJDynamicLayoutUnitModel *parent;
@property (nonatomic, weak, readonly) CSJDynamicCreativeModel *creativeModel;

- (id)initWithDictionary:(NSDictionary *)dictionary parent:(CSJDynamicLayoutUnitModel *_Nullable)parent;

- (void)updateValuesInfoWithDefaultDictionary:(NSDictionary *)defaultDict creativeModel:(CSJDynamicCreativeModel *)creativeModel;

- (void)updateTagGroupCountIfNeedWithCreativeModel:(CSJDynamicCreativeModel *)creativeModel;

- (NSDictionary *)dictionaryValue;
- (NSDictionary *)dictionaryValueNotIncludeValues;
- (void)printBaseInfoWithKey:(NSString *)key;

- (NSString *)debugInfoWithParentType:(NSString *)parentType;


- (void)printBaseInfoWithKey:(NSString *)key parentType:(NSString *)parentType;

- (BOOL)isLeaf;
- (BOOL)isAbsolute;
- (BOOL)isFixed;
- (BOOL)isNoDataBrick;
- (BOOL)heightCanBeFlex;
- (BOOL)widthCanBeFlex;


- (BOOL)is_customComponentVesselBrick;
- (BOOL)is_root;
@end

NS_ASSUME_NONNULL_END
