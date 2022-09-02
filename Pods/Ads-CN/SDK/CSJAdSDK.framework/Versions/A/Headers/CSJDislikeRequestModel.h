//
//  CSJDislikeRequestModel.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/10.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJRequestModel.h"


@interface CSJDislikeRequestModel : CSJRequestModel

@property (nonatomic, copy) NSArray<NSString *> *filter_words;
@property (nonatomic, copy) NSString *action;
@property (nonatomic, assign) NSInteger timestamp;
@property (nonatomic, copy) NSString *ad_sdk_version;
@property (nonatomic, copy) NSString *extra;
@property (nonatomic, copy) NSString *ad_id;
@property (nonatomic, copy) NSString *comment; // 其他建议
@property (nonatomic, copy) NSString *dislike_source;

@end
