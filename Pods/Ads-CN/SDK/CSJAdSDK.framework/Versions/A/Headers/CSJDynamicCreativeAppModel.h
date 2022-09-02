//
//  CSJDynamicCreativeAppModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicCreativeAppModel : NSObject
@property (nonatomic, copy) NSString *app_name;
@property (nonatomic, assign) long long app_size;
@property (nonatomic, copy) NSString *appleid;
@property (nonatomic, assign) long comment_num;
@property (nonatomic, copy) NSString *download_url;
@property (nonatomic, copy) NSString *package_name;
@property (nonatomic, assign) CGFloat score;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
