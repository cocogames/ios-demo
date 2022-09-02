//
//  CSJDynamicBrickModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/13.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicBrickValuesModel.h"
#import "CSJDynamicViewDefine.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicBrickModel : NSObject

// 记录一下，方便开发用
@property (nonatomic, copy) NSDictionary *originDictionary;

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *dataString;
// xzj_todo 数组的问题，临时记录一下
@property (nonatomic, copy, nullable) NSArray <NSString *> *dataArray;
@property (nonatomic, copy, nullable) NSDictionary *dataDict;
// 这有可能是字符串，有可能是数组，也有可能是字典，也有可能是nil
@property (nonatomic, strong) id dataExtraInfo;
@property (nonatomic, copy) NSString *clickType;
@property (nonatomic, assign) NSInteger areaType;
/// 4300链路优选，标识当前点击区域是否是视频组件
@property (nonatomic, assign) BUDynamicClickAreaCategory clickAreaCategory;
@property (nonatomic, strong) CSJDynamicBrickValuesModel *nightThemeValues;
@property (nonatomic, strong) CSJDynamicBrickValuesModel *values;


- (id)getBrickData;



- (id)initWithDictionary:(NSDictionary *)dictionary;


- (BUDynamicBrickLogoType)dynamicBrickLogoType;

#pragma mark - SDK Analysis
- (NSDictionary *)dictionaryValue;

- (NSDictionary *)dictionaryValueNotIncludeValues;
@end

NS_ASSUME_NONNULL_END
