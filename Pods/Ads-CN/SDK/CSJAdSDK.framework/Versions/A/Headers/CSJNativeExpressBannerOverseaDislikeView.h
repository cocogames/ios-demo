//
//  CSJNativeExpressBannerOverseaDislikeView.h
//  Pods
//
//  Created by Levi Duan on 9/7/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJNativeExpressBannerOverseaDislikeView;

@protocol CSJNativeExpressBannerOverseaDislikeViewDelegate <NSObject>

- (void)clickAdLogoOnTheBannerofOverseaDislikeView:(CSJNativeExpressBannerOverseaDislikeView *)bannerDislikeView;

@end

@interface CSJNativeExpressBannerOverseaDislikeView : UIView

@property (nonatomic, weak) id<CSJNativeExpressBannerOverseaDislikeViewDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
