//
//  CSJAdInfoViewModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/1/6.
//

#import <Foundation/Foundation.h>
#import "CSJAdSlot+Private.h"
#import "CSJMaterialMeta+Private.h"
#import "CSJMaterialMeta+Splash.h"
#import "CSJURitSettingModel.h"
#import "CSJAdFileCache.h"


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BUNativeExpressAdViewSource) {
    BUNativeExpressAdViewSourceNone                  =          -1,          // 其他
    BUNativeExpressAdViewSourceOrigin                =           0,          // 传统的动态布局
    BUNativeExpressAdViewSourceMiddle                =           1,          // 中间页,Banner&插屏的相关推荐
};

typedef NS_ENUM(NSUInteger, BUImagesPreloadType) {
    /// 普通模式
    BUImagesPreloadTypeNormal                  =    0,
    /// 全屏激励预加载时的图片预加载,需要同步之前icon加载失败的埋点
    BUImagesPreloadTypeFullScreenReward        =    1,
};

@interface CSJAdInfoViewModel : NSObject

@property (nonatomic, strong, readonly) CSJAdSlot *slot;
@property (nonatomic, strong, readonly) CSJMaterialMeta *materialMeta;
@property (nonatomic, assign) BUNativeExpressAdViewSource nativeExpressAdViewSource;

- (id)initWithSlot:(CSJAdSlot *)slot materialMeta:(CSJMaterialMeta *)materialMeta source:(BUNativeExpressAdViewSource)source;


#pragma mark - 动态布局相关
// 获取主模板和子模板的时候出现的错误，目前就只有102和103错误
@property (nonatomic, strong) NSError *fetchError;
/// 模板增量
@property (nonatomic, copy) NSString *tplPlug;
/// 这个属性可能用于两种情况： 1. 动态布局的子模板增量信息   2. 中间页的子模板信息
@property (nonatomic, copy) NSString *diffTplPlug;

#pragma mark - Public
- (CSJURitSettingModel *)currentRitSettingModel;


#pragma mark - Render Relate
// 这里是把动态布局需要用到的相关setting给收敛到一个地方，避免重复，避免零碎现象
- (NSDictionary *)templateRenderSetting;



#pragma mark - Dynamic Render

// 是否需要获取子模板信息
- (BOOL)needToGetTemplateDataInfo;

- (BUAdRenderSequence)renderSequence;
- (BUAdBackupRenderControl)backupRenderControl;

// webView/原生动态布局需要用到的信息
- (NSDictionary *)creativeDicForDynamicRender;


- (NSTimeInterval)renderDelayTimeSecond;

#pragma mark - Image
- (CSJImage *)mainImageModel;

#pragma mark - Image File Cache
- (BOOL)supportFileCache;
- (CSJAdFileCache *)fileCache;


#pragma mark - track tag
- (NSString *)track_tag_UsedIn_playalbeInExpress;

#pragma mark - image load
/// 4300 海外图片加载优化，存在image_key, 走FileCache获取图片
/// @param adImageView 图片视图容器
/// @param imageModel 对应的图片信息
- (void)fillDataWithImageView:(UIImageView * _Nullable)adImageView imageModel:(CSJImage * _Nullable)imageModel;

/// 4300 海外图片加载优化, 预加载物料里的所有图片(icon.url, image.url, video.cover_url)
/// @param preloadType 预加载的类型
- (void)preLoadAllAdImagesWithPreloadType:(BUImagesPreloadType)preloadType;

/// 4300 海外图片加载优化, 预加载物料里指定的图片
/// @param images 需要加载的图片
/// @param preloadType 预加载的类型
- (void)preLoadAdImagesWith:(NSArray<CSJImage *> * _Nullable)images withPreloadType:(BUImagesPreloadType)preloadType;
@end

NS_ASSUME_NONNULL_END
