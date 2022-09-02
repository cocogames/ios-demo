//
//  CSJTemplateResourceArchiveModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/5/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJTemplateResourceArchiveModel : NSObject
@property (nonatomic, copy) NSString *md5;
// 对应的本地文件信息
@property (nonatomic, copy) NSString *localUrl;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSDictionary *map;

- (id)initWithDicitonary:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryValue;


- (BOOL)valid;
@end

NS_ASSUME_NONNULL_END
