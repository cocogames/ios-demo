//
//  CSJAdBannerSlot.h
//  CSJAdSDK
//
//  Created by Levi Duan on 21/4/21.
//

#import <Foundation/Foundation.h>

@interface CSJAdBannerSlot : NSObject

// 1为轮播，0为未开启轮播banner
@property (nonatomic, assign) NSInteger isRotateBanner;

// 轮播时间间隔
@property (nonatomic, assign) NSInteger rotateTime;

// 当前在轮播内容的第几位,从1开始
@property (nonatomic, assign) NSInteger rotateOrder;

- (NSDictionary *)dictionaryValue;

@end
