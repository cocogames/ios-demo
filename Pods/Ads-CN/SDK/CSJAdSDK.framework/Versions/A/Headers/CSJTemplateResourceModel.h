//
//  CSJTemplateResourceModel.h
//  CSJAdSDK
//
//  Created by Rush.D.xzj on 2020/6/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 主模板中resource数据结构
@interface CSJTemplateResourceModel : NSObject

@property (nonatomic, copy) NSString *md5;
// 对应的本地文件信息， 只是文件名，不是文件全路径，文件的目录是在其他地方进行操作的
@property (nonatomic, copy) NSString *localUrl;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, assign) NSInteger level;


- (id)initWithDicitonary:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryValue;


@end

NS_ASSUME_NONNULL_END
