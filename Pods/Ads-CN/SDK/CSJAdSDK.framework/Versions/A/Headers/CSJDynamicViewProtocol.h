//
//  CSJDynamicViewProtocol.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/19.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJDynamicView;
@protocol CSJDynamicViewDelegate <NSObject>

@optional


- (NSDictionary *)dynamicView_getCurrentVideoState;
- (void)dynamicView_skipVideo;
- (void)dynamicView_openPrivacy;
- (void)dynamicView_interstitial_webview_close;
- (void)dynamicView_muteVideoWithParams:(NSDictionary *)params;
- (void)dynamicView_changeVideoStateWithParams:(NSDictionary *)params;
- (void)dynamicView_clickEventWithParams:(NSDictionary *)params;
- (void)dynamicView_adAnalysisDataWithParams:(NSDictionary *)params;
- (void)dynamicView_renderDidFinishWithParams:(NSDictionary *)params;
- (void)dynamicView_show_SKOverlay;

@end

NS_ASSUME_NONNULL_END
