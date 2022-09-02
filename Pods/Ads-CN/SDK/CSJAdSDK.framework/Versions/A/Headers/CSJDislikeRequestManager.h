//
//  CSJDislikeRequestManager.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/10.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CSJAd;
@class CSJDislikeWords;

@interface CSJDislikeRequestManager : NSObject

+ (void)requestWithModel:(id<CSJAd>)adModel filterWords:(NSArray<CSJDislikeWords *> *) filterWords comment:(NSString *)comment dislikeSource:(NSString *)dislikeSource;

@end
