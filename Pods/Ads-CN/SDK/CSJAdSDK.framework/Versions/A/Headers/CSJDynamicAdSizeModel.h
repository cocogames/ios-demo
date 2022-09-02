//
//  CSJDynamicAdSizeModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/8/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicAdSizeModel : NSObject


@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger isLandscape;
@property (nonatomic, assign) NSInteger width;

- (id)initWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
