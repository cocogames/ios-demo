//
//  CSJRenderEngineViewModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/1/11.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"
#import "CSJFullLinkTrackInfo.h"
#import "CSJDynamicNativeViewModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJRenderEngineViewModel : NSObject

// xzj_todo 优化做的提前准备
@property (nonatomic, strong) CSJAdInfoViewModel *infoViewModel;
@property (nonatomic, strong, readonly) CSJDynamicNativeViewModel *dynamicNativeViewModel;
@property (nonatomic, strong) CSJFullLinkTrackInfo *fullLinkTrackInfo;
@property (nonatomic, assign) NSInteger renderIndex;


#pragma mark - init
- (id)initWithInfoViewModel:(CSJAdInfoViewModel *)infoViewModel size:(CGSize)size renderIndex:(NSInteger)renderIndex NS_DESIGNATED_INITIALIZER;

- (id)init NS_UNAVAILABLE;
+ (id)new NS_UNAVAILABLE;


#pragma mark - Public(FullTrackInfo)
- (void)addTrackInfoWithKey:(NSString *)key userInfo:(NSDictionary * _Nullable)userInfo;


#pragma mark - originInfoDictionary
- (NSDictionary *)originInfoDictionary;
#pragma mark - jsCallNative
- (NSDictionary *)jsCallNative_getTemplateInfoWithValid:(BOOL * _Nullable)valid;
- (NSDictionary *)jsCallNative_adInfoWithValid:(BOOL * _Nullable)valid;
- (NSDictionary *)jsCallNative_appInfo;

@end

NS_ASSUME_NONNULL_END
