//
//  CSJSplashControlSlideAreaModel.h
//  CSJAdSDK
//
//  Created by Willie on 2021/9/27.
//

#import <Foundation/Foundation.h>
#import "CSJModelSerialization.h"

NS_ASSUME_NONNULL_BEGIN

/// 开屏上滑动画时，可滑动范围的控制模型
@interface CSJSplashControlSlideAreaModel : NSObject <NSSecureCoding, CSJModelSerialization>

/// 默认 150
@property (nonatomic, assign) NSInteger topMargin;
/// 默认 30
@property (nonatomic, assign) NSInteger leftMargin;
/// 默认 30
@property (nonatomic, assign) NSInteger bottomMargin;
/// 默认 40
@property (nonatomic, assign) NSInteger rightMargin;

@end

NS_ASSUME_NONNULL_END
