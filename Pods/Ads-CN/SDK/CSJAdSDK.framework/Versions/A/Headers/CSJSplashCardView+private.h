//
//  CSJSplashCardView+private.h
//  CSJAdSDK
//
//  Created by ByteDance on 2022/3/21.
//

#import "CSJSplashCardView.h"
#import "CSJMaterialMeta+Private.h"
#import "CSJSplashViewModel.h"
#import "CSJMaterialMeta.h"

NS_ASSUME_NONNULL_BEGIN

@protocol CSJSplashCardViewDelegate;

@interface CSJSplashCardView ()

@property (nonatomic, weak) id<CSJSplashCardViewDelegate> delegate;

- (instancetype)initWithViewModel:(CSJSplashViewModel *)viewModel;

- (void)showSplashCardInRootVC:(UIViewController *)rootVC;

@end

@protocol CSJSplashCardViewDelegate <NSObject>
/**
 This method is called when splash card is clicked.
 */
- (void)splashCardViewAdDidClick:(CSJSplashCardView *)splashCard;

/**
 This method is called when splash card is closed.
 */
- (void)splashCardViewAdDidClose:(CSJSplashCardView *)splashCard;


@end

NS_ASSUME_NONNULL_END
