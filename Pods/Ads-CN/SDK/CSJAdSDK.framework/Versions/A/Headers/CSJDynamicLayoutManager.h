//
//  CSJDynamicLayoutManager.h
//  CSJAdSDK
//
//  Created by Rush.D.xzj on 2020/6/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJTemplateDataModel.h"
#import "CSJTemplateModel.h"

NS_ASSUME_NONNULL_BEGIN


@interface CSJDynamicLayoutManager : NSObject
#pragma mark - Template
// 国内外环境切换，机房改变 更新动态布局模板 渲染引擎
// dcChanged 实际表示是否变更了主模板下载地址
// YES表示变更了， NO表示没有没有变更
- (void)fetchTemplateWithDCChanged:(BOOL)dcChanged;
// 主模板的资源URL对应的本地url
- (nullable NSString *)templateResourceLocalURLWithURL:(NSString *)url;
- (CSJTemplateModel *)mainTemplateModel;

#pragma mark - Template Data
// 获取物料的时候，通过slotId获取相关的子模板的信息的时候
- (NSArray *)cacheExistTemplateDataWithSlotId:(NSString *)slotId;
// 单个更新+获取  有数据则获取，没有数据获取本地缓存的同时请求一次数据
- (void)fetchTemplateDataWithSlotId:(NSString *)slotId model:(CSJTemplateDataModel *)model completionBlock:(void(^)(NSString *templateData, NSError *error))completionBlock;
- (CSJTemplateDataModel *)templateDataModelWithId:(NSString *)templateDataId;

#pragma mark - Cache
// 删除所有模板和模板增量的本地缓存
+ (void)deleteAllLocalData;

#pragma mark - Signal
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
