//
//  CSJWebViewBottomBar.h
//  CSJAdSDK
//
//  Created by Willie on 2022/2/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJWebViewBottomBar : UIView

@property (nonatomic, strong) UIButton *goBackButton;
@property (nonatomic, strong) UIButton *goForwardButton;
@property (nonatomic, strong) UIButton *reloadButton;
@property (nonatomic, strong) UIButton *safariButton;
@property (nonatomic, strong) UIView *line;

@end

NS_ASSUME_NONNULL_END
