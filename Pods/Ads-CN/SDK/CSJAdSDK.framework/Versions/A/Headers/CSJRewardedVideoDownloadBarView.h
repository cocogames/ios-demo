//
//  CSJRewardedVideoDownloadBarView.h
//  CSJAdSDK
//
//  Created by gdp on 2018/1/23.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJMaterialMeta;
@class CSJAdSlot;

typedef NS_ENUM(NSUInteger, BURewardedDownloadBarStyle) {
    BURewardedDownloadBarStyleNew,
    BURewardedDownloadBarStyleOld,
    BURewardedDownloadBarStyleNewWithDesc,
};

@protocol CSJRewardedVideoDownloadBarDelegate;

@interface CSJRewardedVideoDownloadBarView : UIView

@property (nonatomic, weak, nullable) id<CSJRewardedVideoDownloadBarDelegate> delegate;

- (instancetype)initDownloadBarWith:(CSJMaterialMeta *)materialMeta slot:(CSJAdSlot *)slot barStyle:(BURewardedDownloadBarStyle)downloadBarStyle;

@end

@protocol CSJRewardedVideoDownloadBarDelegate <NSObject>

@optional

- (void)downloadBarTapped:(id)sender extraDic:(NSDictionary *)extraDic;

- (void)downloadButtonTapped:(id)sender extraDic:(NSDictionary *)extraDic;

@end

NS_ASSUME_NONNULL_END
