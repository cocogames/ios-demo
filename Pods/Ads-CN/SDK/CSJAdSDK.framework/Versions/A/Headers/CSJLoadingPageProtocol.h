//
//  CSJLoadingPageProtocol.h
//  loadingPageTest
//
//  Created by bytedance on 2021/11/2.
//
#import <Foundation/Foundation.h>

@class CSJMaterialMeta;
@protocol CSJLoadingPageProtocol <NSObject>

@property (nonatomic, assign) BOOL isPortrait;//是否竖屏
- (void)startLoading;/// 开始加载动画

@optional

@property (nonatomic, copy) void(^adButtonClickBlock)(void);
- (void)setMaterialMeta:(CSJMaterialMeta *)materialMeta;

@end
