//
//  CSJDynamicCreativeModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicCreativeAppModel.h"
#import "CSJDynamicCreativeIconModel.h"
#import "CSJDynamicCreativeImageModel.h"
#import "CSJDynamicCreativeVideoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicCreativeModel : NSObject


@property (nonatomic, copy) NSDictionary *originDictionary;


@property (nonatomic, strong) CSJDynamicCreativeAppModel *app;
@property (nonatomic, assign) long long app_size;
@property (nonatomic, copy) NSString *button_text;
@property (nonatomic, assign) long comment_num;
@property (nonatomic, copy) NSString *creative_description;
@property (nonatomic, copy) NSString *dynamic_creative;
@property (nonatomic, copy) NSDictionary *dynamic_creativeDict;
@property (nonatomic, strong) CSJDynamicCreativeIconModel *icon;
@property (nonatomic, copy) NSArray<CSJDynamicCreativeImageModel *> *image;
@property (nonatomic, assign) NSInteger image_mode;
@property (nonatomic, assign) NSInteger interaction_type;
@property (nonatomic, assign) CGFloat score;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, strong) CSJDynamicCreativeVideoModel *video;


- (CGFloat)score_exact_i18n;
- (NSInteger)comment_num_i18n;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
