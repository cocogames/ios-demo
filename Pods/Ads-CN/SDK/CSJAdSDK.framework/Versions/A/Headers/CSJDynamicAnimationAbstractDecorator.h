//
//  CSJDynamicAnimationAbstractDecorator.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/9/17.
//

#import "CSJDynamicAbstractDecorator.h"
#import "CSJDynamicAnimationModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUDynamicAnimationStyle) {
    BUDynamicAnimationStyle_Layer,
    BUDynamicAnimationStyle_Animation,
};

@interface CSJDynamicAnimationAbstractDecorator : CSJDynamicAbstractDecorator

@property (nonatomic, strong) CSJDynamicAnimationModel *animationModel;

- (CAMediaTimingFunctionName)timingFuntionNamefromDynamicAnimationModel:(NSString *)animationTimeFunction;

+ (instancetype)animationDecoratorWithAnimationModel:(CSJDynamicAnimationModel *)animationModel;

- (BUDynamicAnimationStyle)animationStyle;

@end

NS_ASSUME_NONNULL_END
