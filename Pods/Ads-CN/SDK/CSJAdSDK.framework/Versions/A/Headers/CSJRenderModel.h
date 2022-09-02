//
//  CSJRenderModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUAdRenderSequence) {
    BUAdRenderSequence_templateDynamic                       =           0, // webview模板渲染
    BUAdRenderSequence_nativeDynamic                        =           1, // 原生动态化渲染
    BUAdRenderSequence_templateDynamic_and_nativeDynamic     =           2, // 使用webview渲染，如果失败采用原生动态化渲染
    BUAdRenderSequence_nativeDynamic2                       =           3, // 原生动态化2.0
    BUAdRenderSequence_Lynx                                 =           4, // Lynx渲染
    BUAdRenderSequence_brandingHtml                         =           5, // 品牌广告html渲染
    BUAdRenderSequence_none                                 =           99, // 不支持任何动态化渲染方式，服务端不会下发此值，同时这个字段是相当于把materialMeta中的renderControl字段给包含进去了
};

typedef NS_ENUM(NSInteger, BUAdBackupRenderControl) {
    BUAdBackupRenderControl_none                    =           0,      // 不执行端上原生兜底
    BUAdBackupRenderControl_native                  =           1,      // 执行端上原生兜底
};

// 原生动态化(1.0和2.0)的渲染线程控制 0子线程  1主线程 如果没有下发(其他非法值)那么默认就是0
typedef NS_ENUM(NSInteger, BUAdRenderThread) {
    BUAdRenderThread_Sub            =           0,
    BUAdRenderThread_Main           =           1,
};



@interface CSJRenderModel : NSObject <NSCoding>

@property (nonatomic, assign) BUAdRenderSequence renderSequence;
@property (nonatomic, assign) BUAdBackupRenderControl backupRenderControl;
@property (nonatomic, assign) BUAdRenderThread renderThread;
// 开屏自渲染的预留时间,单位是毫秒
@property (nonatomic, assign) NSInteger reserveTime;
@property (nonatomic, assign) NSInteger retryEnable;
@property (nonatomic, assign) float retryTimeout;

- (BOOL)enableRetry;

- (id)initWithDictionary:(NSDictionary *)dict;


@end

NS_ASSUME_NONNULL_END
