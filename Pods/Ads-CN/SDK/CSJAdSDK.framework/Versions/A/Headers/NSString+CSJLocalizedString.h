//
//  NSString+CSJLocalizedString.h
//  CSJAdSDK
//
//  Created by 李盛 on 2019/1/29.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const Testads;
extern NSString * const CSJ_Click;
extern NSString * const CSJ_AD;
extern NSString * const CSJ_PlayConsumed;
extern NSString * const CSJ_Evaluation;
extern NSString * const CSJ_Score;
extern NSString * const CSJ_Select;
extern NSString * const CSJ_Wan;
extern NSString * const CSJ_Back;
extern NSString * const CSJ_Replay;
extern NSString * const CSJ_Continue;
extern NSString * const CSJ_Skip;
extern NSString * const CSJ_Feedback;
extern NSString * const CSJ_FeedbackStr1;
extern NSString * const CSJ_FeedbackStr2;
extern NSString * const CSJ_FeedbackStr3;
extern NSString * const CSJ_FeedbackStr4;
extern NSString * const CSJ_ViewNow;
extern NSString * const CSJ_Download;
extern NSString * const CSJ_LoadFailure;
extern NSString * const CSJ_GetRewardAfterWatching;
extern NSString * const CSJ_GiveUpReward;
extern NSString * const CSJ_ContinueWatching;
extern NSString * const CSJ_CanbeTurnedOffAfter;
extern NSString * const CSJ_CanbeSkipAfter;
extern NSString * const CSJ_Get;
extern NSString * const CSJ_View;
extern NSString * const CSJ_ViewDetail;
extern NSString * const CSJ_ContinuePlaying;
extern NSString * const CSJ_GetRewardAfterPlaying;
extern NSString * const CSJ_CommitScore;
extern NSString * const CSJ_AdsClosed;
extern NSString * const CSJ_PrivacyPolicy;
@interface NSString (CSJLocalizedString)

+ (NSString *)csj_localizedStringForKey:(NSString *)key;

/// 包含服务端force_language 服务端下的force_language > local language
+ (NSString *)csj_currentLanguage;

//判断当前语言环境是否是简体中文
+ (BOOL)csj_isSimplifiedChinese;

@end

NS_ASSUME_NONNULL_END
