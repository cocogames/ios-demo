//
//  CSJDynamicViewGlobalModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/2/11.
//

#import <UIKit/UIKit.h>

#import "CSJAdInfoViewModel.h"
#import "CSJDynamicNativeViewModel.h"

NS_ASSUME_NONNULL_BEGIN

// 此类的作用是记录当原生动态化渲染成功后的一些结论性的数据
@interface CSJDynamicViewGlobalModel : NSObject

#pragma mark - Data before parse
// 物料信息
@property (nonatomic, strong) CSJAdInfoViewModel *infoViewModel;
// 动态布局需要用到的原始数据
@property (nonatomic, strong) CSJDynamicNativeViewModel *dynamicNativeViewModel;

#pragma mark - Data before render
// 解析成功后得到的布局数据
@property (nonatomic, copy) NSDictionary *layoutInfoDictionary;

#pragma mark - Data aftre render success
@property (nonatomic, assign, readonly) BOOL openPlayableLandingPage;
@property (nonatomic, strong, readonly) UIView *dislikeView;

- (void)updateOpenPlayableLandingPageIfNeed:(BOOL)openPlayableLandingPage;
- (void)updateDisLikeViewIfNeed:(UIView *)dislikeView;

@property (nonatomic, strong) UIView *rootView;
@property (nonatomic, assign) BOOL needToInsertPlayerViewIntoRootView;
@end

NS_ASSUME_NONNULL_END
