//
//  CSJInterstitialCoverView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/9/20.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJCoverView.h"
#import "CSJNativeAdRelatedView.h"

NS_ASSUME_NONNULL_BEGIN

@class CSJInterstitialCoverView;
@protocol CSJInterstitialCoverViewDelegate <NSObject>

@optional
/**
 This method is called when videoadview failed to play.
 @param error : the reason of error
 */
- (void)interstitialCoverView:(CSJInterstitialCoverView *)interstitialCoverView videoDidLoadFailWithError:(NSError *_Nullable)error;

/**
 This method is called when videoadview playback status changed.
 @param playerState : player state after changed
 */
- (void)interstitialCoverView:(CSJInterstitialCoverView *)interstitialCoverView videoStateDidChanged:(BUPlayerPlayState)playerState;

/**
 This method is called when videoadview ready to play.
 */
- (void)playerReadyToPlay:(CSJInterstitialCoverView *)interstitialCoverView;

/**
 This method is called when videoadview end of play.
 */
- (void)playerDidPlayFinish:(CSJInterstitialCoverView *)interstitialCoverView;

/**
 This method is called when videoadview is clicked.
 */
- (void)videoAdViewDidClick:(CSJInterstitialCoverView *)interstitialCoverView;

/**
 This method is called when videoadview's finish view is clicked.
 */
- (void)videoAdViewFinishViewDidClick:(CSJInterstitialCoverView *)interstitialCoverView;

/**
 This method is called when another controller has been closed.
 @param interactionType : open appstore in app or open the webpage or view video ad details page.
 */
- (void)videoAdViewDidCloseOtherController:(CSJInterstitialCoverView *)interstitialCoverView interactionType:(BUInteractionType)interactionType;


@end


@interface CSJInterstitialCoverView : CSJCoverView
@property (nonatomic, assign) id<CSJInterstitialCoverViewDelegate> interstitialDelegate;
// 是否有视屏view
@property (nonatomic, readonly, assign) BOOL haveVideoView;
@property (nonatomic, strong) CSJNativeAdRelatedView *nativeAdRelatedView;

- (void)addVideoViewIfNeed;

@end

NS_ASSUME_NONNULL_END
