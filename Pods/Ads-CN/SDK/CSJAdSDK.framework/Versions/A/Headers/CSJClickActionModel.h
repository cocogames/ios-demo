//
//  CSJClickActionModel.h
//  CSJAdSDK
//
//  Created by Levi Duan on 16/7/21.
//

#import <Foundation/Foundation.h>
#import "UIView+CSJAd.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJClickActionModel : NSObject

/// 3900 控制 CTA button 的点击交互
@property (nonatomic, assign) BUAdUserBehaviorType cta;
/// 3900 控制其他创意区域的点击交互
@property (nonatomic, assign) BUAdUserBehaviorType other;

- (id)initWithDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
