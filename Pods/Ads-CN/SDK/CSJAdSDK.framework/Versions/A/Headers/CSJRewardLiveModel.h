//
//  CSJRewardLiveModel.h
//  CSJAdSDK
//
//  Created by shenqichen on 2021/8/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define BURewardLiveAlertDefaultDuration 5

/// 激励直播广告
typedef NS_ENUM(NSInteger, BURewardLiveType) {
    BURewardLiveTypeReserve         = 0,  // 小于等于该值无效
    BURewardLiveTypeOnlySDK      = 1,  // 默认方案，时长为穿山甲SDK内广告观看时间
    BURewardLiveTypeSDKAndDouyin = 2,  // 穿山甲SDK内广告观看时间+抖音端内观看时间
    BURewardLiveTypeLimit           = 3,  // 大于等于该值无效
};

/// 激励直播广告
typedef NS_ENUM(NSInteger, BURewardLiveStyle) {
    BURewardLiveStyleReserve        = 0,  // 小于等于该值无效
    BURewardLiveStyleNoAlert        = 1,  // 无弹窗
    BURewardLiveStyleManualJump     = 2,  // 出弹窗，不自动跳转
    BURewardLiveStyleAutoJump       = 3,  // 出弹窗，用户不操作5s后自动跳转
    BURewardLiveStyleLimit          = 4,  // 大于等于该值无效
};

@interface CSJRewardLiveModel : NSObject <NSCoding>
 
// 激励场景直播广告奖励判断逻辑
@property (nonatomic, assign) BURewardLiveType rewardLiveType;

// 激励跳转弹窗交互方案
@property (nonatomic, assign) BURewardLiveStyle rewardLiveStyle;

// 激励弹窗文案，默认为“观看完整直播间精彩内容”
@property (nonatomic, copy) NSString *rewardLiveText;

// 控制引导弹窗自动出现时间，单位s
@property (nonatomic, assign) NSInteger rewardStartTime;

// 控制引导弹窗自动消失时间，单位s
@property (nonatomic, assign) NSInteger rewardCloseTime;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

- (NSDictionary *)dictionaryValue;

@end

NS_ASSUME_NONNULL_END
