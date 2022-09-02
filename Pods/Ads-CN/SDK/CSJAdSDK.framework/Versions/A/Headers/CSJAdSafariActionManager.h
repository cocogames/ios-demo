//
//  CSJAdSafariActionManager.h
//  CSJAdSDK
//
//  Created by 曹清然 on 2017/5/25.
//  Copyright © 2017年 chenren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJActionServiceDefine.h"

@interface CSJSafariActionModel : NSObject <CSJActionWebModel>
@property (nonatomic, copy) NSString *targetURL;
- (instancetype)initWithString:(NSString *)urlString;
+ (instancetype)initWithURL:(NSURL *)url;
@end

@interface CSJAdSafariActionManager : NSObject

+ (instancetype)sharedManager;

- (BOOL)handleActionWithModel:(id<CSJActionWebModel>)admodel;

@end
