//
//  CSJTplInfo.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/9/10.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, CSJTplMaterialType) {
    CSJTplMaterialType_UnKnow = 0, // 未知
    CSJTplMaterialType_Image = 1, // 图片模版
    CSJTplMaterialType_Video = 2  // 视频模版
};

@interface CSJTplInfo : NSObject <NSCoding>
/// 动态布局增量的CDN地址
@property (nonatomic, copy) NSString *templateDataUrl;

/// 动态布局增量的md5
@property (nonatomic, copy) NSString *templateDataMd5;

/// 动态布局的id
@property (nonatomic, copy) NSString *templateDataId;

/// 动态布局的data
@property (nonatomic, copy) NSString *templateData;

/// 动态布局的diff_data
@property (nonatomic, copy) NSString *templateDiffData;

/// 动态布局的主模板version
@property (nonatomic, copy) NSString *version;

/// 动态创意
@property (nonatomic, copy) NSString *dynamic_creative;

@property (nonatomic, assign) CGFloat score_exact_i18n;

@property (nonatomic, assign) NSInteger comment_num_i18n;

@property (nonatomic, assign) CSJTplMaterialType material_type;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

@end

