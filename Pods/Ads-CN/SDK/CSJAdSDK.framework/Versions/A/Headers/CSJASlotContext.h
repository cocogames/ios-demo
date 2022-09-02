//
//  CSJASlotContext.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/9.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJMaterialMeta.h"
#import "CSJAdSlot.h"
#import "CSJDislikeContext.h"

typedef void(^interactionBlock)(BUInteractionType interactionType);

@interface CSJASlotContext : NSObject

@property (nonatomic, weak) UIViewController *rootViewController;
@property (nonatomic, copy) NSString *source;
@property (nonatomic, strong) CSJAdSlot *adSlot;
@property (nonatomic, strong) CSJDislikeContext *dislikeContext;
@property (nonatomic, copy) interactionBlock didCloseOtherController;

// 标识来源是中间页面，避免在中间页打开落地页时走进循环
@property (nonatomic, assign) BOOL fromMiddlePage;

// 表示来源为pl落地页，自动转化时避免再次打开pl页面
@property (nonatomic, assign) BOOL fromPlayable;

// 以下三个属性需要从信息流视频预览页传到视频详情页<CSJVideoDetailPageViewController>, 用于了落地页锚点需求 add in V3300 by chaors
@property (nonatomic, assign) CGFloat playTimeIfVideo;  // 如果是视频记录当前播放进度 add in V3300 by chaors
@property (nonatomic, assign) CGFloat totalPlayTimeIfVideo;  // 如果是视频记录当前播放进度 add in V3300 by chaors
@property (nonatomic, assign) BOOL autoPlayIfVideo;  // 如果是视频是否自动播放add in V3300 by chaors

@property (nonatomic, assign) BOOL isTransform; // 是否播放是否旋转

/// 当前播放视频的进度
@property (nonatomic, strong) NSNumber *currentPlayProgress;
@property (nonatomic, assign) BOOL openPlayableLandingPage; //该参数为YES是打开playable落地页的必要不充分条件，需结合其他条件判断。若为NO，则一定不会打开pl落地页
@property (nonatomic, copy) void(^closePolicyBlock)(void);
@property (nonatomic, strong) CSJMaterialMeta *materialMeta;

@end
