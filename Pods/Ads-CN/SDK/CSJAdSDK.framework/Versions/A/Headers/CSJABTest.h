//
//  CSJABTest.h
//  CSJAdSDK
//
//  Created by Siwant on 2019/6/13.
//  Copyright © 2019 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSJAdSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJABTest : NSObject <NSCoding, CSJToDictionary>
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *param;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;

- (nullable NSDictionary *)dictionaryValue;
@end

NS_ASSUME_NONNULL_END
