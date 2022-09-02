//
//  CSJRewardedLiveAlertView.h
//  CSJAdSDK
//
//  Created by shenqichen on 2021/8/3.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^BURewardedLiveAlertCompletion)(BOOL isConfirm, BOOL countDownToZero);

@interface CSJRewardedLiveAlertView : UIView

- (instancetype)initWithFrame:(CGRect)frame
                         text:(NSString *)text
                     duration:(NSInteger)duration
                     autoJump:(BOOL)autoJump
                   completion:(BURewardedLiveAlertCompletion)completion;

- (void)showInView:(UIView *)parentView;

@end

NS_ASSUME_NONNULL_END
