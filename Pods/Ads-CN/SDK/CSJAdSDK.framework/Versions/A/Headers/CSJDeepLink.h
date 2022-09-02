//
//  CSJDeepLink.h
//  CSJAdSDK
//
//  Created by chenren on 10/05/2017.
//  Copyright © 2017 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BUDeepLinkFallbackType) {
    BUDeepLinkFallbackTypePage = 1,
    BUDeepLinkFallbackTypeDownload,
};

@interface CSJDeepLink : NSObject <NSCoding>

// 应用唤醒打开页面的地址
@property (nonatomic, copy) NSString *deepLinkURL;

// 应用唤醒不成功时候跳转的地址
@property (nonatomic, copy) NSString *fallbackURL;

// 应用唤醒不成功的链接类型
@property (nonatomic, assign) BUDeepLinkFallbackType fallbackType;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

@end

