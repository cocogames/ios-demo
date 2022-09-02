//
//  CSJAnimationConfiguration.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/11/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, BUAnimationStyle) {
    BUAnimationStyle_Base,
    BUAnimationStyle_Keyframe,
    BUAnimationStyle_Group
};

@interface CSJAnimationConfiguration : NSObject
@property (nonatomic, assign) BUAnimationStyle animationStyle;
@property (nonatomic, copy) NSString *keyPath;
@property (nonatomic, assign) CGFloat totalDuration;
@property (nonatomic, assign) CGFloat subGroupDuration;
@property (nonatomic, copy) NSArray<NSValue *> *opacityValues;
@property (nonatomic, copy) NSArray<NSValue *> *scaleValues;
@property (nonatomic, copy) NSArray<NSValue *> *positionValues;
@property (nonatomic, copy) NSArray<NSValue *> *transformValues;
@property (nonatomic, copy) NSArray<NSValue *> *pathValues;
@property (nonatomic, copy) NSArray<NSNumber *> *keyTimes;
@property (nonatomic, copy) NSArray<NSValue *> *keyFrameValues;
@property (nonatomic, strong) id fromValue;
@property (nonatomic, strong) id toValue;
@property (nonatomic, assign) CGPoint startPoint;
@property (nonatomic, assign) CGPoint endPoint;
@property (nonatomic, assign) CGFloat lineWidth;
@property (nonatomic, assign) CGFloat speed;
@property (nonatomic, assign) CFTimeInterval beginTime;
@property (nonatomic, assign) float repeatCount;
@property (nonatomic, copy) CAMediaTimingFillMode fillMode;
@property (nonatomic, getter=isRemovedOnCompletion) BOOL removedOnCompletion;
@property (nonatomic, nullable, strong) CAMediaTimingFunction *timingFunction;
@property (nonatomic, nullable, copy) NSArray<CAAnimation *> *animations;
@end

NS_ASSUME_NONNULL_END
