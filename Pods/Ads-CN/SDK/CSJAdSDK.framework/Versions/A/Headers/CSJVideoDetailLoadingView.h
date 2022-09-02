//
//  CSJVideoDetailLoadingView.h
//  CSJAdSDK
//
//  Created by Levi on 14/11/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJVideoDetailLoadingView : UIView

@property (nonatomic, strong) UILabel *loadingLabel;

- (void)startLoading;

@end

NS_ASSUME_NONNULL_END
