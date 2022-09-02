//
//  CSJModelSerialization.h
//  CSJAdSDK
//
//  Created by Willie on 2020/10/22.
//  Copyright © 2020 bytedance. All rights reserved.
//

#ifndef BUModelSerialization_h
#define BUModelSerialization_h

NS_ASSUME_NONNULL_BEGIN

@protocol CSJModelSerialization <NSObject>

+ (instancetype)fromDictionary:(NSDictionary *)dictionary;
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END

#endif /* BUModelSerialization_h */
