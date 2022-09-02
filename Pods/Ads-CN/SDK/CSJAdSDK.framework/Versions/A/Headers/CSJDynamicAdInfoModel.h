//
//  CSJDynamicAdInfoModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicAdInfoModel : NSObject
@property (nonatomic, copy) NSDictionary *originDictionary;
@property (nonatomic, copy) NSString *cid;
@property (nonatomic, assign) NSInteger code;
@property (nonatomic, copy) NSString *dc;
@property (nonatomic, copy) NSString *langInfoLocalization;
@property (nonatomic, copy) NSString *log_extra;
@property (nonatomic, copy) NSDictionary *log_extraDict;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
