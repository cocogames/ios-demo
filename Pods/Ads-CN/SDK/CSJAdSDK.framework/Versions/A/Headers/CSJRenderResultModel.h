//
//  CSJRenderResultModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/8.
//

#import <Foundation/Foundation.h>
#import "CSJRenderEngineDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJRenderResultModel : NSObject

@property (nonatomic, assign) CGSize adViewSize;

@property (nonatomic, assign) BOOL haveVideoInfo;
@property (nonatomic, assign) CGRect videoFrame;
@property (nonatomic, assign) BUFCornerRadii videoCornerRadii;
@property (nonatomic, assign) CGFloat maxRadius;
// 这里这个属性多余了，不要用这个
//@property (nonatomic, assign) BURenderEngineRenderType renderType;
// 当是兜底的情况下播放器的容器view，只有在兜底的情况下才有值
@property (nonatomic, weak) UIView *playerViewContainerView;

@end

NS_ASSUME_NONNULL_END
