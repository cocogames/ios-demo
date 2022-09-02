//
//  CSJRewardAgainTipsView.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/5/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^CSJRewardAgainTipsTapActionBlock)(void);

@interface CSJRewardAgainEntranceTipsView : UIView
@property (nonatomic, copy) CSJRewardAgainTipsTapActionBlock tapActionBlock;
@end

NS_ASSUME_NONNULL_END
