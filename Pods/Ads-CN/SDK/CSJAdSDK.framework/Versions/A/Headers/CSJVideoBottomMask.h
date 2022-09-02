//
//  CSJVideoBottomMask.h
//  CSJAdSDK
//
//  Created by 李盛 on 2019/5/15.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJMaterialMeta,CSJAdSlot,CSJVideoBottomMask;

@protocol CSJCSJVideoBottomMaskClickDelegate <NSObject>
- (void)videoBottomMaskTapped:(CSJVideoBottomMask *)videoTopMask
                  extraDic:(NSDictionary *)extraDic;
- (void)videoBottomMaskSubViewsTapped:(CSJVideoBottomMask *)videoTopMask
                          extraDic:(NSDictionary *)extraDic;
@end

@interface CSJVideoBottomMask : UIView

@property (nonatomic, weak) id<CSJCSJVideoBottomMaskClickDelegate>delegate;

- (instancetype)initWithMaterialMeta:(CSJMaterialMeta *)materialMeta
                                slot:(CSJAdSlot *)slot;

@end

NS_ASSUME_NONNULL_END
