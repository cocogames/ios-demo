//
//  CSJLandingPageConfModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// "swipe_back_type":1 // 表示向右滑动返回时的实际效果（0-返回宿主app、1-返回落地页、...）

typedef NS_ENUM(NSInteger, BUSwipeBackType) {
    BUSwipeBackType_App                 =           0,
    BUSwipeBackType_Page                =           1,
};
@interface CSJLandingPageConfModel : NSObject

@property (nonatomic, assign) BUSwipeBackType swipeBackType;

- (id)initWithDictionary:(NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
