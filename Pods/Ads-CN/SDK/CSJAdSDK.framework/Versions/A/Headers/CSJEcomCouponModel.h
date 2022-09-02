//
//  CSJEcomCouponModel.h
//  CSJAdSDK
//
//  Created by shenqichen on 2022/6/27.
//

#import <Foundation/Foundation.h>
#import "CSJModelSerialization.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJEcomCouponModel : NSObject <CSJModelSerialization>

@property (nonatomic, assign) NSInteger user_id;
@property (nonatomic, copy) NSString *coupon_meta_id;
@property (nonatomic, copy) NSString *unique_id;
@property (nonatomic, assign) NSInteger device_id;
@property (nonatomic, assign) BOOL has_coupon;
@property (nonatomic, assign) NSInteger coupon_scene;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, assign) NSInteger threshold;
@property (nonatomic, copy) NSString *scene_key;
@property (nonatomic, assign) NSInteger activity_id;
@property (nonatomic, assign) NSInteger amount;
@property (nonatomic, assign) NSInteger action;
@property (nonatomic, assign) NSInteger style;
@property (nonatomic, copy) NSString *start_time;
@property (nonatomic, copy) NSString *expire_time;
@property (nonatomic, copy) NSString *button_text;
@property (nonatomic, copy) NSString *extra;
@property (nonatomic, copy) NSString *toast;

- (BOOL)canApplyCoupon;
- (BOOL)canShowToast;

@end

NS_ASSUME_NONNULL_END
