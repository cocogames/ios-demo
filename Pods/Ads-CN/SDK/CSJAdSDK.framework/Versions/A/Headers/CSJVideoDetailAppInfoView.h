//
//  CSJVideoDetailAppInfoView.h
//  CSJAdSDK
//
//  Created by Levi on 15/11/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJVideoDetailAppInfoView;

@protocol CSJVideoDetailAppInfoViewDelegate <NSObject>

@optional
/// 点击下载按钮
- (void)videoDetailAppInfoViewClickDownloadButton:(CSJVideoDetailAppInfoView *)appinfoView extraDic:(NSDictionary *_Nullable)extraDic;

@end

@interface CSJVideoDetailAppInfoView : UIView

@property (nonatomic, weak) id<CSJVideoDetailAppInfoViewDelegate> delegate;

- (instancetype)initWithMaterial:(CSJMaterialMeta *)materialMeta;

@end

NS_ASSUME_NONNULL_END
