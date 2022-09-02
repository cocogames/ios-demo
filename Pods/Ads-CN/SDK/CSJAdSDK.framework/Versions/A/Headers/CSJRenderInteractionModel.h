//
//  CSJRenderInteractionModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/9.
//

#import <Foundation/Foundation.h>
#import "CSJRenderClickEventModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BURenderInteractionType) {
    BURenderInteractionTypeNone = 0,
    // jsbridge
    BURenderInteractionType_clickEvent,
    BURenderInteractionType_openPrivacy,
    BURenderInteractionType_preventTouchEvent,
    BURenderInteractionType_muteVideo,
    BURenderInteractionType_changeVideoState,
    BURenderInteractionType_getCurrentVideoState,
    BURenderInteractionType_skipVideo,
    BURenderInteractionType_immersiveVideoPageBack,
    BURenderInteractionType_getMaterialMeta,
    BURenderInteractionType_openPlayable,
    BURenderInteractionType_interstitial_webview_close,
    BURenderInteractionType_startVideoTransform,
    BURenderInteractionType_rewardPlayAgain,
    // cover
    BURenderInteractionType_click   =       1000,
    BURenderInteractionType_clickVideo,
    BURenderInteractionType_clickClose,
    BURenderInteractionType_clickAdLogo,
    BURenderInteractionType_clickDownload,
    BURenderInteractionType_interactiveFinished, //轻互动完成 抵消激励时长
    BURenderInteractionType_adAnalysisData, //传递埋点数据
    BURenderInteractionType_requestPauseVideo // 请求精准暂停视频
};


@interface CSJRenderInteractionModel : NSObject
@property (nonatomic, assign) BURenderInteractionType renderInteractionType;
@property (nonatomic, strong) CSJRenderClickEventModel *renderClickEventModel;

@property (nonatomic, copy) NSDictionary *js2NativeParams;
@property (nonatomic, copy) NSDictionary *native2JSParams;

@end

NS_ASSUME_NONNULL_END
