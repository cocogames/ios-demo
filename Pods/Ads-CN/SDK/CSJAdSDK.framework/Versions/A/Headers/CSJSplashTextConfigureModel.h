//
//  CSJSplashTextConfigureModel.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/7/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 开屏合规底部按钮文字样式
@interface CSJSplashTextConfigureModel : NSObject<NSCoding>
@property (nonatomic, assign) NSInteger font_size;

/// 文字样式配置
/// @param configure 服务端配置
/// @param fontSize 默认字体大小
- (instancetype)initWithConfigure:(NSDictionary *)configure defaultFontSize:(CGFloat)fontSize;
@end

NS_ASSUME_NONNULL_END
