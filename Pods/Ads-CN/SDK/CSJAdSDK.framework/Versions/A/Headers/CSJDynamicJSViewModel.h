//
//  CSJDynamicJSViewModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/24.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicLayoutUnitModel.h"
#import "CSJDynamicImageInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicJSViewModel : NSObject
@property (nonatomic, strong) CSJDynamicLayoutUnitModel *dynamicLayoutModel;
@property (nonatomic, assign) BOOL isDarkMode;

#pragma mark - Public

// js的frame，是相当于左上角的，需要进行转换
- (CGRect)buDynamic_frame;



#pragma mark - View Property
- (UIColor *)buDynamic_backgroundColor;
- (UIColor *)buDynamic_layerBorderColor;
- (UIColor *)buDynamic_textColor;
- (UIFont *)buDynamic_textFont;
- (NSTextAlignment)buDynamic_textAlignment;
- (CGFloat)buDynamic_layerBorderRadius;
- (CGFloat)buDynamic_layerBorderWidth;


#pragma mark - Image
- (UIViewContentMode)buDynamic_viewContentMode;
#pragma mark - Padding
- (CGFloat)buDynamic_paddingLeft;
- (CGFloat)buDynamic_paddingRight;
- (CGFloat)buDynamic_paddingTop;
- (CGFloat)buDynamic_paddingBottom;

#pragma mark - Label
- (NSInteger)buDynamic_numberOfLines;

#pragma mark - TextFlow
- (BOOL)buDynamic_allowTextFlow;
- (BUDynamicTextFlowType)buDynamic_textFlowType;
- (NSInteger)buDynamic_textFlowDuration;

#pragma mark - click & slide
- (BOOL)buDynamic_isTap;

#pragma mark - ValuesModel
- (CSJDynamicBrickValuesModel *)currentValuesModel;


#pragma mark - Property
- (BUDynamicClickAreaType)clickAreaType;
- (BUDynamicClickAreaCategory)clickAreaCategory;
- (BOOL)isVideoClick;
- (BOOL)isVideoCreative;
- (BUDynamicTimingPolicy)timingPolicy;
- (BOOL)supportViewClickAction;
- (BOOL)supportTimingPolicy;
- (BOOL)supportTimeProgress;
- (BOOL)supportBgGradient;
- (BOOL)supportCalcuColor;
- (BOOL)supportInteraction;
- (BOOL)isSplashAd;


#pragma mark - ImageInfo
- (CSJDynamicImageInfoModel *)imageInfoModel;



@end

NS_ASSUME_NONNULL_END
