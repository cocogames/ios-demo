//
//  CSJTemplateDataModel.h
//  CSJAdSDK
//
//  Created by Rush.D.xzj on 2020/6/11.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 子模板数据结构
@interface CSJTemplateDataModel : NSObject
// 子模板ID
@property (nonatomic, copy) NSString *templateDataId;
// 子模板下载url地址
@property (nonatomic, copy) NSString *url;

// 子模板数据的版本号
@property (nonatomic, copy) NSString *version;
// 子模板数据
@property (nonatomic, copy) NSString *data;
// 子模板下载url地址下载后的data字符串进行 bu_md5Hash
@property (nonatomic, copy) NSString *md5;
// 在缓存中创建的时间, 精确到毫秒
@property (nonatomic, assign) NSTimeInterval createDateTimeInterval;
// 在缓存中更新的时间, 精确到毫秒
@property (nonatomic, assign) NSTimeInterval modifyDateTimeInterval;

- (id)initWithDicitonary:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryValue;

// 是否有URL缓存
- (BOOL)haveURLCache;
// 是否有数据缓存
- (BOOL)haveDataCache;

- (void)updateCreateDateTime;
- (void)updateModifyDateTime;

@end

NS_ASSUME_NONNULL_END
