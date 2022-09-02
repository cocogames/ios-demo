//
//  CSJVideoInfo.h
//  CSJAdSDK
//
//  Created by gdp on 2017/12/10.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, BUVideoEncodeType) {
    BUVideoEncodeType_H264      = 0,        // H624 方式播放
    BUVideoEncodeType_H265      = 1,        // HEVC 方式播放
};


@interface CSJVideoInfo : NSObject<NSCoding>

/// 编码格式
@property (nonatomic, assign) BUVideoEncodeType encodeType;

// 视频占位图高度
@property (nonatomic, assign) NSInteger coverHeight;

// 视频占位图宽度
@property (nonatomic, assign) NSInteger coverWidth;

// 视频占位图链接
@property (nonatomic, copy) NSString *coverUrl;

// 视频解析度
@property (nonatomic, copy) NSString *resolution;

// 视频文件大小
@property (nonatomic, assign) CGFloat size;

// 视频时长
@property (nonatomic, assign) NSInteger videoDuration;

// 视频地址
@property (nonatomic, copy) NSString *videoUrl;

//本地缓存视频地址
@property (nonatomic, strong) NSURL *videoLocalURL;

// 记录已播放时间，用于续播
@property (nonatomic, assign) CGFloat playedSeconds;

// 当前播放器状态,用于打点loading就算播放
@property (nonatomic, assign) BOOL isVideoPlaying;

// endcard 落地页地址
@property (nonatomic, copy) NSString *endcard;

// playable zip下载地址
@property (nonatomic, copy) NSString *playableZipUrl;

// 视频详情页地址
@property (nonatomic, copy) NSString *detailPage;

// 视频文件hash值
@property (nonatomic, copy) NSString *fileHash;

//物料中添加字段 fallback_endcard_judge，默认值为2，不依赖前端判断，走线上逻辑；值为1时，依赖前端判断。不发fallback_endcard_judge默认为1
//1就走前端判断，非1或者没有，就线上逻辑
@property (nonatomic, assign) NSInteger fallbackEndcardJudge;

// 视频预加载大小，单位byte 默认300kb
@property (nonatomic, assign) NSInteger video_preload_size;

/// 是否支持播放降级
@property (nonatomic, assign) BOOL video_backup;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

- (NSDictionary *)dictionaryValue;

@end
