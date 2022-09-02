//
//  CSJCustomNavigationBarView.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/1/10.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BUCustomNavigationBarStyle) {
    BUCustomNavigationBarStyleVideoLandingPage,
    BUCustomNavigationBarStyleNormalLandingPage,
    BUCustomNavigationBarStyleNormalLandingPageNew,
};

@class CSJMaterialMeta;
@class CSJCustomNavigationBarView;

@protocol CSJCustomNavigationBarDelegate <NSObject>
@optional
/// 点击了返回按钮回调
- (void)customNavigationBarDidClickBackButton:(CSJCustomNavigationBarView *)navigationBarView;

/// 点击关闭按钮回调
- (void)customNavigationBarDidClickCloseButton:(CSJCustomNavigationBarView *)navigationBarView;

/// 点击反馈按钮回调
- (void)customNavigationBarDidClickDislikeButton:(CSJCustomNavigationBarView *)navigationBarView;

@end

@interface CSJCustomNavigationBarView : UIView
/// 返回按钮
@property (nonatomic, strong) UIButton *backButton;
/// 关闭按钮，鲁班广告需要隐藏
@property (nonatomic, strong) UIButton *closeButton;
/// 反馈按钮
@property (nonatomic, strong) UIButton *dislikeButton;
/// 标题
@property (nonatomic, strong) UILabel *titleLabel;
/// 底部分割线
@property (nonatomic, strong) UIView *line;

@property (nonatomic, weak) id<CSJCustomNavigationBarDelegate> delegate;

/// 创建自定义导航栏view
/// @param material 广告物料，使用标题和dislikewords
/// @param navBarStyle 导航栏样式，普通落地页和视频落地页的导航栏有差异
- (instancetype)initWithMaterial:(CSJMaterialMeta *)material style:(BUCustomNavigationBarStyle)navBarStyle;
@end

NS_ASSUME_NONNULL_END
