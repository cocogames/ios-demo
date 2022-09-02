//
//  CSJVideoTopMask.h
//  CSJAdSDK
//
//  Created by 李盛 on 2019/5/15.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJMaterialMeta,CSJAdSlot,CSJVideoTopMask;

@protocol CSJCSJVideoTopMaskClickDelegate <NSObject>
- (void)videoTopMaskTapped:(CSJVideoTopMask *)videoTopMask
                  extraDic:(NSDictionary *)extraDic;
- (void)videoTopMaskSubViewsTapped:(CSJVideoTopMask *)videoTopMask
                          extraDic:(NSDictionary *)extraDic
                   clickTypeString:(NSString *)clickType;
@end

@interface CSJVideoTopMask : UIView

@property (nonatomic, weak) id<CSJCSJVideoTopMaskClickDelegate>delegate;

- (instancetype)initWithMaterialMeta:(CSJMaterialMeta *)materialMeta
                                           slot:(CSJAdSlot *)slot;

@end

NS_ASSUME_NONNULL_END
