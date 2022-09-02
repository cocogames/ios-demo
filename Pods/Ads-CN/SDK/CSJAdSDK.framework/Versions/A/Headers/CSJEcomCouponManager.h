//
//  CSJEcomCouponManager.h
//  CSJAdSDK
//
//  Created by shenqichen on 2022/6/27.
//

#import <Foundation/Foundation.h>
#import "CSJMaterialMeta.h"
#import "CSJAdSlot.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJEcomCouponManager : NSObject

+ (void)appleCouponWithMaterial:(CSJMaterialMeta*)material slot:(CSJAdSlot*)slot completion:(void(^)(BOOL success))completion;

@end

NS_ASSUME_NONNULL_END
