//
//  CSJFullScreenTransitioningDelegate.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJMaterialMeta;
@interface CSJFullScreenTransitioningDelegate : NSObject <UIViewControllerTransitioningDelegate>
- (instancetype)initWithAdSize:(CGSize)adSize materialMeta:(CSJMaterialMeta *)material;
@end

NS_ASSUME_NONNULL_END
