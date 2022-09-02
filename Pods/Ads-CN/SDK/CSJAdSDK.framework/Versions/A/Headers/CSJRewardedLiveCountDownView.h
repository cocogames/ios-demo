//
//  CSJRewardedLiveCountDownView.h
//  CSJAdSDK
//
//  Created by shenqichen on 2021/8/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define BURewardedLiveCountDownViewSize 72

@protocol CSJRewardedLiveCountDownViewDelegate <NSObject>

- (void)onCountDownToZero;

@end


@interface CSJRewardedLiveCountDownView : UIView

- (instancetype)initWithFrame:(CGRect)frame
                     delegate:(nullable id<CSJRewardedLiveCountDownViewDelegate>)delegate;

/**
 更新播放时间
 */
- (void)updateCountDown:(long)leftTime duration:(long)duration;

@end

NS_ASSUME_NONNULL_END
