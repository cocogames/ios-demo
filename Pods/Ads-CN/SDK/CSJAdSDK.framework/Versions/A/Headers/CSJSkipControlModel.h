//
//  CSJSkipControlModel.h
//  CSJAdSDK
//
//  Created by Willie on 2021/9/26.
//

#import <Foundation/Foundation.h>
#import "CSJModelSerialization.h"

NS_ASSUME_NONNULL_BEGIN

/// 跳过按钮位置
typedef enum : NSUInteger {
    BUSkipControlPositionTL = 1, ///< 上左
    BUSkipControlPositionTR = 2, ///< 上右
    BUSkipControlPositionBL = 3, ///< 下左
    BUSkipControlPositionBR = 4, ///< 下右
} BUSkipControlPosition;

/// 跳过按钮位置控制模型
@interface CSJSkipControlModel : NSObject <NSSecureCoding, CSJModelSerialization>

/// 跳过按钮位置，默认 `BUSkipControlPositionTR`
@property (nonatomic, assign) BUSkipControlPosition position;

/// 左边距或右边距，默认 16
@property (nonatomic, assign) NSInteger leftOrRightMargin;

/// 上边距或下边距
/// `position` 为 `BUSkipControlPositionTL` 或 `BUSkipControlPositionTR` 时，默认 16
/// `position` 为 `BUSkipControlPositionBL` 或 `BUSkipControlPositionBR` 时，默认 30
@property (nonatomic, assign) NSInteger topOrBottomMargin;

@end

NS_ASSUME_NONNULL_END
