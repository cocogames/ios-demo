//
//  CSJDynamicSkipCountdownsView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/8/24.
//

#import "CSJDynamicAbstractView.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicSkipCountdownsView : CSJDynamicAbstractView

- (BOOL)needChangeFrame;
- (BOOL)firstUpdateFrame;
- (BOOL)secondUpdateFrame;

@end

NS_ASSUME_NONNULL_END
