//
//  CSJFoundationProxy.h
//  CSJAdSDK
//
//  Created by Willie on 2020/8/27.
//  Copyright © 2020 bytedance. All rights reserved.
//

/**
 * 这个类是为了在 CSJAdSDK 中调用 BUFoundation 中未暴露出的方法。
 * 如果 BUFoundation 暴露所有的方法会有安全风险。
 *
 * 使用方式：
 *
 * 1. 在 CSJAdSDK 中使用 `@interfaceProxy` 声明想要调用的类，并将需要调用的方法声明复制过来，比如：
 *
 * ```
 * @interfaceProxy(CSJCocoaSecurityDecoder)
 *
 * - (NSData *)bu_base64:(NSString *)data;
 * - (NSData *)bu_hex:(NSString *)data;
 *
 * @end
 * ```
 *
 * 2. 使用 `@implementationProxy` 标记声明的类，不需要实现上面声明的方法，比如：
 *
 * ```
 * @implementationProxy(CSJCocoaSecurityDecoder)
 *
 * @end
 * ```
 *
 * 3. 在场景中使用 `ClassProxy` 即可，比如：
 *
 * ```
 * CSJCocoaSecurityDecoderProxy *decode = [CSJCocoaSecurityDecoderProxy alloc];
 * NSData *decodeData = [decode bu_base64:dataString];
 * ```
 */

#import <Foundation/Foundation.h>

#define interfaceProxy(class)                                       \
interface class##Proxy : CSJFoundationProxy                          \

#define implementationProxy(class)                                  \
_Pragma("clang diagnostic push")                                    \
_Pragma("clang diagnostic ignored \"-Wincomplete-implementation\"") \
implementation class##Proxy                                         \
_Pragma("clang diagnostic pop")


NS_ASSUME_NONNULL_BEGIN

@interface CSJFoundationProxy : NSProxy

- (void)attachTarget:(id)target;

#pragma mark - Override

+ (Class)proxyClass;

@end

NS_ASSUME_NONNULL_END
