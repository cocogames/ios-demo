//
//  CSJVideoDetailPageViewController.h
//  CSJAdSDK
//
//  Created by gdp on 2017/12/10.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJActionServiceDefine.h"
#import "CSJAdSDKDefines+Private.h"
#import "CSJMaterialMeta.h"
#import "CSJAdSlot.h"

@class CSJDislikeContext;

@interface CSJVideoDetailPageViewController : UIViewController

@property (nonatomic, weak) UIViewController *rootViewController;
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, assign) CGFloat playTimeIfVideo; // 如果是视频广告接收跳转详情页前记录的播放进度 add in V3300 by chaors
@property (nonatomic, assign) CGFloat totalPlayTimeIfVideo; // 如果是视频广告总播放时长 add in V3300 by chaors
@property (nonatomic, assign) BOOL autoPlayIfVideoFromOut;   // 外部跳转前的视频是否自动播放 add in V3300 by chaors
@property (nonatomic, assign) BOOL isFromClick;

@property (nonatomic, copy) void(^CloseBlock)(void);

- (instancetype)initWithMaterial:(CSJMaterialMeta *)material;

@end
