//
//  CSJDynamicSDKAnalysisRenderCanvas.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/7/9.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicLayoutUnitModel.h"

NS_ASSUME_NONNULL_BEGIN


@interface CSJDynamicSDKAnalysisViewRect : NSObject

@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGFloat safeInstance;

@end



@interface CSJDynamicSDKAnalysisRenderCanvas : NSObject


@property (nonatomic, strong) CSJDynamicSDKAnalysisViewRect *viewRect;

- (void)repaint:(CSJDynamicLayoutUnitModel *)brick origin:(CGPoint)origin;

- (void)updateResult;
@end

NS_ASSUME_NONNULL_END
