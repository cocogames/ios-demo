//
//  CSJNativeExpressVideoAdContext.h
//  CSJAdSDK
//
//  Created by yujie on 2021/12/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^SkipBlock)(BOOL skiped);
@interface CSJNativeExpressVideoAdContext : NSObject
@property (nonatomic, strong) CSJAdSlot *slot;
@property (nonatomic, strong) CSJMaterialMeta *materialMeta;
@property (nonatomic, weak) id sender;
@property (nonatomic, copy) SkipBlock skipBlock;
@property (nonatomic, copy) NSString *rewardAlertTitle;
@property (nonatomic, copy) NSString *rewardAlertConfirm;
@property (nonatomic, copy) NSString *rewardAlertCancel;
@end


NS_ASSUME_NONNULL_END
