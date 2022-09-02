//
//  CSJTipsHUD.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/4/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJTipsHUD : NSObject
- (void)showHUDWithTips:(NSString *)tips;
- (void)hideHUD;
@end

NS_ASSUME_NONNULL_END
