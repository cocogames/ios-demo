//
//  CSJApp.h
//  CSJAdSDK
//
//  Created by chenren on 10/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface CSJApp : NSObject

// 开发者的申请的appid唯一标识
@property (nonatomic, copy) NSString *appID;

// app应用名
@property (nonatomic, copy) NSString *name;

// 开发者app包名，bundle name
@property (nonatomic, copy) NSString *packageName;

// app当前版本号
@property (nonatomic, copy) NSString *version;
/// 4700 open sdk拉起小程序，上报是否接入符合预期版本的opensdk
@property (nonatomic, assign) NSUInteger userfulOpenSDK;

- (NSDictionary *)dictionaryValue;

+ (instancetype)currentApp;

@end

