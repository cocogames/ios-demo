//
//  CSJRewardedVideoWebDefaultView.h
//  CSJAdSDK
//
//  Created by cuiyanan on 2019/6/26.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJMaterialMeta;
@class CSJAdSlot;
@protocol CSJRewardedVideoWebDefaultViewDelegate;

@interface CSJRewardedVideoWebDefaultView : UIView
@property (nonatomic, weak, nullable) id<CSJRewardedVideoWebDefaultViewDelegate> delegate;
- (instancetype)initViewWithSlot:(CSJAdSlot *)slot ad:(CSJMaterialMeta *)materialMeta;
@end

@protocol CSJRewardedVideoWebDefaultViewDelegate <NSObject>
@optional
- (void)downloadButtonTapped:(id)sender extraDic:(NSDictionary *)extraDic;

- (void)logoImageViewTapped:(id)sender;
@end


NS_ASSUME_NONNULL_END
