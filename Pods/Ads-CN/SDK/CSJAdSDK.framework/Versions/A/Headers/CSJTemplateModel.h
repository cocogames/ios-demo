//
//  CSJTemplateModel.h
//  CSJAdSDK
//
//  Created by Rush.D.xzj on 2020/6/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJTemplateResourceModel.h"
#import "CSJTemplateResourceArchiveModel.h"


NS_ASSUME_NONNULL_BEGIN
// 主模板数据结构
@interface CSJTemplateModel : NSObject
@property (nonatomic, copy) NSString *main;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSArray<CSJTemplateResourceModel *> *resources;
@property (nonatomic, strong) CSJTemplateResourceArchiveModel *resources_archive;
// 兜底动态布局需要下载的js资源地址
@property (nonatomic, copy) NSString *fallback;

- (NSDictionary *)resourcesMap;


- (id)initWithDicitonary:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryValue;

- (BOOL)mainURLValid;
// 以前渲染引擎的resource list
- (BOOL)resourceListValid;
// 新的渲染引擎的resource archive
- (BOOL)resourcesArchiveValid;
// 整个资源的resource
- (BOOL)resourcesValid;
#pragma mark - Not Need Cache
// 是否已经重新加载过
@property (nonatomic, assign) BOOL reload;

@end

NS_ASSUME_NONNULL_END
