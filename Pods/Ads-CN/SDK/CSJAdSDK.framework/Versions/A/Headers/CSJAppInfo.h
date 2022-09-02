//
//  CSJAppInfo.h
//  CSJAdSDK
//
//  Created by chenren on 10/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJActionServiceDefine.h"
#import <CoreGraphics/CoreGraphics.h>

@interface CSJAppInfo : NSObject <CSJActionAppModel, NSCoding>

/// 广告主APP名称
@property (nonatomic, copy) NSString *appName;

/// appid
@property (nonatomic, copy) NSString *appid;

/// 应用下载URL，应用下载必须
@property (nonatomic, copy) NSString *downloadURL;

/// 评分（星级），取值范围 [1,5]
@property (nonatomic, assign) CGFloat score;

/// 评论人数
@property (nonatomic, assign) NSInteger commentNum;

/// 广告安装包大小,单位byte, 取不到时为0
@property (nonatomic, assign) NSInteger appSize;

///
@property (nonatomic, copy) NSString *packageName;

/// tag
@property (nonatomic, copy) NSArray *creativeTags;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

- (NSDictionary *)dictionaryValue;

@end

