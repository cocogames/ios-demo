//
//  CSJLoadingInfo.h
//  CSJAdSDK
//
//  Created by yujie on 2022/2/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger,BUPlayableLoadingStyle) {
    BUPlayableLoadingStyle_Default = 0,   // 默认样式
    BUPlayableLoadingStyle_Struct = 1,    // 结构化loading
    BUPlayableLoadingStyle_Custom = 2     // 自定义底图loading
};

@interface CSJLoadingInfo : NSObject<NSCoding>
/** 纯playable是否展示loading
 *  0：代表playable页面没有loading，端上展示loading
 *  1：代表playable页面有loading，端上不展示loading
 */
@property (nonatomic, assign) NSInteger if_playable_loading_show;

/** 控制撤掉loading时机的方式：
 *  0：代表load finish回调后延时1s为loading撤掉时机（新版sdk&老版js-sdk兼容，以及后续可能的问题兜底）
 *  1：代表前端通过js-bridge给客户端回调loading撤掉时机。兜底：10s后js-sdk未给出回调，则撤掉loading
 */
@property (nonatomic, assign) NSInteger remove_loading_page_type;

/// playable loading样式
@property (nonatomic, assign) BUPlayableLoadingStyle playable_loading_style;

/// loading底图url , playable_loading_type = 2时下发
@property (nonatomic, copy) NSString * playable_loading_img_url;
/// loading进度条 icon url, playable_loading_type = 2时下发
@property (nonatomic, copy) NSString * playable_loading_icon_url;

/// pl loading页面提示文字
@property (nonatomic, copy) NSString *playable_loading_tips;

- (instancetype)initWithDictionary:(NSDictionary *)dict
                             error:(NSError *__autoreleasing *)error;
@end

NS_ASSUME_NONNULL_END
