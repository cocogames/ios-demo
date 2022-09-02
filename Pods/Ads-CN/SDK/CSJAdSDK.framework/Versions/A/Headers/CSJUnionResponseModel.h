//
//  CSJUnionResponseModel.h
//  CSJAdSDK
//
//  Created by chenren on 11/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJResponseModel.h"

@class CSJMaterialMeta;

@interface CSJUnionResponseModel : CSJResponseModel
/// 返回广告
@property (nonatomic, copy) NSArray<CSJMaterialMeta *> *creativesAry;

/// 头条did
@property (nonatomic, copy) NSString *did;

/// 返回信息
@property (nonatomic, copy) NSString *message;

/// reason
@property (nonatomic, assign) NSInteger reason;

/// error_msg 接口reason是整形,需要转换,与自定义msg冲突,所以新建一个属性
@property (nonatomic, strong) NSString *errorMsg;

/// 服务端返回的错误描述码
@property (nonatomic, copy) NSString *desc;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

@end

