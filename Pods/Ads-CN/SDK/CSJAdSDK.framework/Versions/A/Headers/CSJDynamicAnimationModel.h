//
//  CSJDynamicAnimationModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/9/17.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUDynamicAnimationType) {
    BUDynamicAnimationType_None = 0,
    BUDynamicAnimationType_Translate = 1,
    BUDynamicAnimationType_Scale = 2,
    BUDynamicAnimationType_Ripple = 3,
    BUDynamicAnimationType_Marquee = 4,
    BUDynamicAnimationType_Waggle = 5,
    BUDynamicAnimationType_Shine = 6,
    BUDynamicAnimationType_Swing = 7,
    BUDynamicAnimationType_Fade = 8,
};

typedef NS_ENUM(NSInteger, BUDynamicAnimationDirection) {
    BUDynamicAnimationDirection_None = 0,
    BUDynamicAnimationDirection_Normal = 1,
    BUDynamicAnimationType_Reverse = 2,
    BUDynamicAnimationType_Alternate = 3,
    BUDynamicAnimationType_AlternateReverse = 4,
};

typedef NS_ENUM(NSInteger, BUDynamicAnimationScaleDirection) {
    BUDynamicAnimationScaleDirection_left = 0,
    BUDynamicAnimationScaleDirection_right = 1,
    BUDynamicAnimationScaleDirection_center = 2,
};

@interface CSJDynamicAnimationModel : NSObject
// 记录一下，方便开发用
@property (nonatomic, copy) NSDictionary *originDictionary;
@property (nonatomic, copy) NSString *animationType;
@property (nonatomic, assign) CGFloat animationBorderWidth;
@property (nonatomic, assign) CGFloat animationEffectWidth;
@property (nonatomic, assign) CGFloat animationDuration;
@property (nonatomic, assign) CGFloat animationScaleX;
@property (nonatomic, assign) CGFloat animationScaleY;
@property (nonatomic, assign) CGFloat animationTranslateX;
@property (nonatomic, assign) CGFloat animationTranslateY;
@property (nonatomic, copy) NSString *animationRippleBackgroundColor;
@property (nonatomic, copy) NSString *animationTimeFunction;
@property (nonatomic, assign) CGFloat animationDelay;
@property (nonatomic, assign) NSInteger animationIterationCount;
@property (nonatomic, copy) NSString *animationDirection;
@property (nonatomic, assign) CGFloat animationInterval;
@property (nonatomic, assign) CGFloat animationSwing;
@property (nonatomic, assign) CGFloat animationFadeStart;
@property (nonatomic, assign) CGFloat animationFadeEnd;
@property (nonatomic, copy) NSString *animationScaleDirection;

- (BUDynamicAnimationDirection)dynamicAnimationDirection;

- (BUDynamicAnimationType)dynamicAnimationType;

- (BUDynamicAnimationScaleDirection)dynamicAnimationScaleDirection;

- (id)initWithDictionary:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryValue;
@end

NS_ASSUME_NONNULL_END
