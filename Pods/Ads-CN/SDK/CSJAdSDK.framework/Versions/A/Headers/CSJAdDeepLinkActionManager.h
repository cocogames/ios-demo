//
//  CSJAdDeepLinkActionManager.h
//  CSJAdSDK
//
//  Created by carl on 2018/1/4.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJActionServiceDefine.h"

@protocol CSJAd;
@class CSJASlotContext;

@interface CSJAdDeepLinkActionManager : NSObject

+ (instancetype)sharedManager;

#pragma mark - Public(Splash)
- (void)handleActionWithModel:(id<CSJActionDeepLinkModel, CSJActionWebModel>) model context:(CSJASlotContext *)context completionBlock:(void(^)(BOOL))completionBlock;
- (BOOL)canPresentPlayableLandingPageWithContext:(CSJASlotContext *)context meta:(id<CSJActionDeepLinkModel, CSJActionWebModel>)model;
@end
