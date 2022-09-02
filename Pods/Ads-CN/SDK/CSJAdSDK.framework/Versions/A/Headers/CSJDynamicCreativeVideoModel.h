//
//  CSJDynamicCreativeVideoModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicCreativeVideoModel : NSObject
@property (nonatomic, assign) NSInteger cover_height;
@property (nonatomic, copy) NSString *cover_url;
@property (nonatomic, assign) NSInteger cover_width;
@property (nonatomic, copy) NSString *endcard;
@property (nonatomic, assign) NSInteger fallback_endcard_judge;
@property (nonatomic, copy) NSString *file_hash;
@property (nonatomic, copy) NSString *resolution;
@property (nonatomic, assign) long long size;
@property (nonatomic, assign) NSInteger video_duration;
@property (nonatomic, copy) NSString *video_url;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
