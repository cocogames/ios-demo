//
//  CSJRewardBrowseAlertView.h
//  CSJAdSDK
//
//  Created by yujie on 2021/9/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^BURewardBrowseAlertViewConfirmBlock)(void);
typedef void (^BURewardBrowseAlertViewCancelBlock)(void);
@interface CSJRewardBrowseAlertView : UIView
@property (nonatomic, copy) BURewardBrowseAlertViewConfirmBlock confirmBlock;
@property (nonatomic, copy) BURewardBrowseAlertViewCancelBlock cancelBlock;
- (instancetype)initWith:(NSString *)title msg:(NSString *)msg;
- (void)show;
- (void)hide;
@end

NS_ASSUME_NONNULL_END
