//
//  CSJSplashZoomOutModel.h
//  CSJAdSDK
//
//  Created by wangyanlin on 2020/6/18.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BUSplashZoomOutIconStatus) {
    BUSplashZoomOutIconStatusSuccess = 0,
    BUSplashZoomOutIconStatusNotCompleted = 1,
    BUSplashZoomOutIconStatusError = 2
};

@interface CSJSplashZoomOutModel : NSObject <NSCoding>
@property (nonatomic, copy) NSString *splashIconUrl;
@property (nonatomic, assign) NSInteger splashIconWidth;
@property (nonatomic, assign) NSInteger splashIconHeight;
@property (nonatomic, assign) CGFloat splashIconVideoWidth;
@property (nonatomic, assign) CGFloat splashIconVideoHeight;
@property (nonatomic, assign) BUSplashZoomOutIconStatus status;
@property (nonatomic, assign) NSTimeInterval videoEndcardShowTime;
@property (nonatomic, copy) NSString *videoEndcardText;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
