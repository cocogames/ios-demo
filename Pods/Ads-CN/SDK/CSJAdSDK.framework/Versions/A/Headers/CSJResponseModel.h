//
//  CSJResponseModel.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/8.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CSJResponseModel <NSObject>
// requestID
@property (nonatomic, copy) NSString *requestID;
// 请求返回值
@property (nonatomic, assign) NSInteger returnValue;

- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;
@end

@interface CSJResponseModel : NSObject <CSJResponseModel>
// requestID
@property (nonatomic, copy) NSString *requestID;
// 请求返回值
@property (nonatomic, assign) NSInteger returnValue;
- (instancetype)initWithDictionary:(NSDictionary *)dict error:(NSError * __autoreleasing *)error;
@end


