//
//  BUDBCoder.h
//  BUAdSDK
//
//  Created by bytedance on 2021/7/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BUDBCoder : NSObject

- (instancetype)initWithDefaultFieldValues;

- (void)encoderText:(NSString *)text withField:(NSString *)field;

- (void)encoderFloat:(CGFloat)floatValue withField:(NSString *)field;

- (void)encoderInteger:(NSInteger)integerValue withField:(NSString *)field;

- (void)encoderObject:(id)object withField:(NSString *)field;

- (NSString *)decoderTextWithField:(NSString *)field;

- (CGFloat)decoderFloatWithField:(NSString *)field;

- (NSInteger)decoderIntegerWithField:(NSString *)field;

- (id)decoderObjectWithField:(NSString *)field;

@end

NS_ASSUME_NONNULL_END
