//
//  BUInteractionMethodParas.h
//  CSJAdSDK
//
//  Created by Levi on 1/12/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJInteractionMethodParams : NSObject

// 默认加载文案
@property (nonatomic, copy) NSString *loadingText;

// 落地页展示最长时间，单位s
@property (nonatomic, assign) NSInteger onlylpLoadingMaxtime;

// 直出落地页展示时间，单位s
@property (nonatomic, assign) NSInteger straightLpShowtime;

- (instancetype)initWithDictionary:(NSDictionary *)dict;


@end

NS_ASSUME_NONNULL_END
