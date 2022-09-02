//
//  CSJDynamicSettingModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicSettingModel : NSObject

@property (nonatomic, assign) NSInteger fv_skip_show;
@property (nonatomic, assign) NSInteger rv_skip_time;
@property (nonatomic, assign) NSInteger iv_skip_time;
@property (nonatomic, assign) NSInteger video_type;
@property (nonatomic, assign) NSInteger show_dislike;
@property (nonatomic, assign) NSInteger video_adaptation;
@property (nonatomic, assign) NSInteger voice_control;
@property (nonatomic, assign) BOOL skip_change_to_close;


- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
