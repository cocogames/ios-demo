//
//  CSJDynamicNativeViewModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJDynamicViewDefine.h"
#import "CSJDynamicTemplateInfoModel.h"
#import "CSJDynamicAppInfoModel.h"
#import "CSJDynamicAdInfoModel.h"
#import "CSJAdInfoViewModel.h"

NS_ASSUME_NONNULL_BEGIN

// xzj_todo_must  这个类居然有两个作用
@interface CSJDynamicNativeViewModel : NSObject

@property (nonatomic, copy) NSDictionary *originDictionary;

@property (nonatomic, strong) CSJDynamicTemplateInfoModel *templateInfoModel;
@property (nonatomic, strong) CSJDynamicAppInfoModel *appInfoModel;
@property (nonatomic, strong) CSJDynamicAdInfoModel *adInfoModel;
// xzj_todo_must 需要删除
@property (nonatomic, strong) CSJAdInfoViewModel *infoViewModel;

// 这一块是SDK解析引擎需用用到的
- (id)initWithDictionary:(NSDictionary *)dict infoViewModel:(CSJAdInfoViewModel *)infoViewModel;

// 这一块是渲染引擎需用用到的。 xzj_todo
// CSJDynamicView 相关的

#pragma mark - Public
- (NSInteger)videoDuration;
- (BUDynamicViewSkipShowPolicy)skipShowPolicyWithSkipShowTime:(NSInteger *)skipShowTime;
- (BOOL)showSkipWhenPlayEnd;
- (BOOL)originMuted;
- (NSString *)appIconURLString;
- (NSString *)appName;
- (CGFloat)appScore;
- (CGFloat)realAppScore;
- (CGFloat)score_exact_i18n;
- (long)comment_num_i18n;
- (long)appCommentNum;
- (NSString *)button_text;
- (CGSize)recommendSize;

- (CGFloat)skipTime;
- (BOOL)checkChangeSkipName;

- (UIColor *)calcuColor;


@end

NS_ASSUME_NONNULL_END
