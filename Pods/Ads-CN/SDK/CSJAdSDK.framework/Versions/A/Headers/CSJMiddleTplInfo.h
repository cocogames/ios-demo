//
//  CSJMiddleTplInfo.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/8/27.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJMiddleTplInfo : NSObject <NSCoding>
/// 动态布局增量的CDN地址
@property (nonatomic, copy) NSString *middleTemplateDataUrl;

/// 动态布局增量的md5
@property (nonatomic, copy) NSString *middleTemplateDataMd5;

/// 动态布局的id
@property (nonatomic, copy) NSString *middleTemplateDataId;

/// 动态布局的data
@property (nonatomic, copy) NSString *middleTemplateData;

/// 动态布局的diff_data
@property (nonatomic, copy) NSString *middleTemplateDiffData;

/// 动态布局的主模板version
@property (nonatomic, copy) NSString *middleVersion;

/// 动态创意
@property (nonatomic, copy) NSString *middle_dynamic_creative;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;
@end

NS_ASSUME_NONNULL_END
