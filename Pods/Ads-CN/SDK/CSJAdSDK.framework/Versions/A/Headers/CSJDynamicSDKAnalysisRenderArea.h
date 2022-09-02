//
//  CSJDynamicSDKAnalysisRenderArea.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/7/9.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicLayoutUnitModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicSDKAnalysisRenderArea : NSObject

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

@property (nonatomic, copy) NSString *treeId;

@property (nonatomic, strong) CSJDynamicLayoutUnitModel *brick;

@property (nonatomic, strong) NSMutableArray <NSMutableArray <CSJDynamicSDKAnalysisRenderArea *> *> *children;
@property (nonatomic, weak) CSJDynamicSDKAnalysisRenderArea *parent;

@property (nonatomic, assign) CGFloat remainWidth;

- (void)updateResult;

@end

NS_ASSUME_NONNULL_END
