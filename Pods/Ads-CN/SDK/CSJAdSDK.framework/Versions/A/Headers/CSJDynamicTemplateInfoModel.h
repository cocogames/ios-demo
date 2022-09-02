//
//  CSJDynamicTemplateInfoModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicAdSizeModel.h"
#import "CSJDynamicCreativeModel.h"
#import "CSJDynamicSettingModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicTemplateInfoModel : NSObject
@property (nonatomic, copy) NSDictionary *originDictionary;

@property (nonatomic, strong) CSJDynamicAdSizeModel *adSize;
@property (nonatomic, strong) CSJDynamicCreativeModel *creative;
@property (nonatomic, strong) CSJDynamicSettingModel *setting;
@property (nonatomic, copy) NSString *diff_template_Plugin;
@property (nonatomic, copy) NSDictionary *diff_template_PluginDict;
@property (nonatomic, copy, readonly) NSDictionary *synthesis_template_PluginDict;
@property (nonatomic, copy) NSString *platform;
@property (nonatomic, copy) NSString *template_Plugin;
@property (nonatomic, copy) NSDictionary *template_PluginDict;

- (id)initWithDictionary:(NSDictionary *)dictionary;

- (void)update_dynamic_creativeIfNeedWithLogExtraDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
