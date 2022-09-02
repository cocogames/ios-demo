//
//  CSJDynamicImageInfoModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/5/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicImageInfoModel : NSObject

// 记录一下，方便开发用
@property (nonatomic, copy) NSDictionary *originDictionary;

@property (nonatomic, copy) NSString *url;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger width;
- (id)initWithDictionary:(NSDictionary *)dictionary;

+ (instancetype)defaultDynamicImageInfoModel;

- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END
