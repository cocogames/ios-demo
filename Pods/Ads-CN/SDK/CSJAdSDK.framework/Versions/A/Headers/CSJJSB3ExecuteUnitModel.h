//
//  CSJJSB3ExecuteUnitModel.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/6/9.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// message type of native call js
FOUNDATION_EXTERN NSString *const CSJJSB3MessageTypeEvent;
// message type of js call native
FOUNDATION_EXTERN NSString *const CSJJSB3MessageTypeCall;
// message type of native callback js
FOUNDATION_EXTERN NSString *const CSJJSB3MessageTypeCallback;


@interface CSJJSB3ExecuteUnitModel : NSObject
@property (nonatomic, copy) NSString *JSSDKVersion;
@property (nonatomic, copy) NSString *msgType;
// native回调js的callback
@property (nonatomic, copy) NSString *callbackId;
// js需要调用的Native的方法名称
@property (nonatomic, copy) NSString *func;
// js2Native的参数
@property (nonatomic, copy) NSDictionary *params;

- (id)initWithDictionary:(NSDictionary *)dictionary;


@end

NS_ASSUME_NONNULL_END
