//
//  CSJDynamicAppInfoModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicAppInfoModel : NSObject
@property (nonatomic, copy) NSDictionary *originDictionary;

@property (nonatomic, assign) NSInteger aid;
@property (nonatomic, assign) NSInteger themeStatus;
@property (nonatomic, copy) NSString *appName;
@property (nonatomic, copy) NSString *sdkEdition;
@property (nonatomic, copy) NSArray *supportList;
- (id)initWithDictionary:(NSDictionary *)dictionary;

- (BOOL)isDarkMode;

@end

NS_ASSUME_NONNULL_END
