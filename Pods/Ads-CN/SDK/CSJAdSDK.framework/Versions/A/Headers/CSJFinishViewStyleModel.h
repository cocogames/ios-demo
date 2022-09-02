//
//  CSJFinishViewStyleModel.h
//  CSJAdSDK
//
//  Created by ByteDance on 2022/6/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJFinishViewStyleModel : NSObject

@property (nonatomic, assign) NSInteger iconWidth;
@property (nonatomic, assign) NSInteger labelWidth;
@property (nonatomic, assign) NSInteger labelHeight;
@property (nonatomic, assign) NSInteger buttonWidth;
@property (nonatomic, assign) NSInteger buttonHeight;
@property (nonatomic, assign) NSInteger labelButtonGap;

@property (nonatomic, assign) NSInteger labelFontSize;
@property (nonatomic, assign) NSInteger buttonFontSize;

@property (nonatomic, assign) BOOL showButton;

+ (CSJFinishViewStyleModel *)styleModelWithFrame:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END
