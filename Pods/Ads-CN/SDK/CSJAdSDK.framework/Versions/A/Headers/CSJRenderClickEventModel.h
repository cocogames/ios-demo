//
//  CSJRenderClickEventModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUAreaType) {
    BUAreaTypeNone = 0, // js不会下发，这里是相当于默认值
    BUAreaTypeLandscape = 1,
    BUAreaTypeLandCreative = 2,
    BUAreaTypeLandDislike = 3,
    BUAreaTypeLandVideoDetail = 4,
};
// 模板clickEvent点击的区域类型
// 4300链路优选需要判断点击的区域做相应的跳转逻辑
typedef NS_ENUM(NSInteger, BUExpressClickAreaCategory) {
    BUExpressClickAreaCategoryUnknow = -1,
    /// 视频区域
    BUExpressClickAreaCategoryVideo = 1,
    /// 图片区域
    BUExpressClickAreaCategoryImage = 2,
};

@interface CSJRenderClickEventModel : NSObject

// 默认值是BUAreaTypeNone
@property (nonatomic, assign) BUAreaType areaType;
@property (nonatomic, copy) NSString *clickAreaType;
@property (nonatomic, copy) NSDictionary *clickInfo;
@property (nonatomic, assign) BUAdUserBehaviorType userBehaviorType;
@property (nonatomic, assign) BUExpressClickAreaCategory clickAreaCategory;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
