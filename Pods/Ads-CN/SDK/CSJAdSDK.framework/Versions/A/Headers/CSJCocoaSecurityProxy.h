//
//  CSJCocoaSecurityProxy.h
//  CSJAdSDK
//
//  Created by Willie on 2020/8/26.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJFoundationProxy.h"

@interfaceProxy(CSJCocoaSecurityResult)

@property (strong, nonatomic, readonly) NSData *data;
@property (strong, nonatomic, readonly) NSString *utf8String;
@property (strong, nonatomic, readonly) NSString *hex;
@property (strong, nonatomic, readonly) NSString *hexLower;
@property (strong, nonatomic, readonly) NSString *base64;

- (instancetype)initWithBytes:(unsigned char[])initData length:(NSUInteger)length;

@end

@interfaceProxy(CSJCocoaSecurity)

#pragma mark - AES Encrypt
+ (CSJCocoaSecurityResultProxy *)bu_aesEncrypt:(NSString *)data key:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_aesEncrypt:(NSString *)data hexKey:(NSString *)key hexIv:(NSString *)iv;
+ (CSJCocoaSecurityResultProxy *)bu_aesEncrypt:(NSString *)data key:(NSData *)key iv:(NSData *)iv;
+ (CSJCocoaSecurityResultProxy *)bu_aesEncryptWithData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;
+ (CSJCocoaSecurityResultProxy *)bu_aesEncryptWithData:(NSData *)data key:(NSData *)key iv:(NSData *)iv error:(NSError **)error;
#pragma mark AES Decrypt
+ (CSJCocoaSecurityResultProxy *)bu_aesDecryptWithBase64:(NSString *)data key:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_aesDecryptWithBase64:(NSString *)data hexKey:(NSString *)key hexIv:(NSString *)iv;
+ (CSJCocoaSecurityResultProxy *)bu_aesDecryptWithBase64:(NSString *)data key:(NSData *)key iv:(NSData *)iv;
+ (CSJCocoaSecurityResultProxy *)bu_aesDecryptWithData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;

+ (CSJCocoaSecurityResultProxy *)bu_aesDecryptWithData:(NSData *)data key:(NSData *)key iv:(NSData *)iv error:(NSError **)error;

#pragma mark - MD5
+ (CSJCocoaSecurityResultProxy *)bu_md5:(NSString *)hashString;
+ (CSJCocoaSecurityResultProxy *)bu_md5WithData:(NSData *)hashData;
#pragma mark HMAC-MD5
+ (CSJCocoaSecurityResultProxy *)bu_hmacMd5:(NSString *)hashString hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacMd5WithData:(NSData *)hashData hmacKey:(NSString *)key;

#pragma mark - SHA
+ (CSJCocoaSecurityResultProxy *)bu_sha1:(NSString *)hashString;
+ (CSJCocoaSecurityResultProxy *)bu_sha1WithData:(NSData *)hashData;
+ (CSJCocoaSecurityResultProxy *)bu_sha224:(NSString *)hashString;
+ (CSJCocoaSecurityResultProxy *)bu_sha224WithData:(NSData *)hashData;
+ (CSJCocoaSecurityResultProxy *)bu_sha256:(NSString *)hashString;
+ (CSJCocoaSecurityResultProxy *)bu_sha256WithData:(NSData *)hashData;
+ (CSJCocoaSecurityResultProxy *)bu_sha384:(NSString *)hashString;
+ (CSJCocoaSecurityResultProxy *)bu_sha384WithData:(NSData *)hashData;
+ (CSJCocoaSecurityResultProxy *)bu_sha512:(NSString *)hashString;
+ (CSJCocoaSecurityResultProxy *)bu_sha512WithData:(NSData *)hashData;
#pragma mark HMAC-SHA
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha1:(NSString *)hashString hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha1WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha224:(NSString *)hashString hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha224WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha256:(NSString *)hashString hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha256WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha384:(NSString *)hashString hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha384WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha512:(NSString *)hashString hmacKey:(NSString *)key;
+ (CSJCocoaSecurityResultProxy *)bu_hmacSha512WithData:(NSData *)hashData hmacKey:(NSString *)key;

@end

@interfaceProxy(CSJCocoaSecurityDecoder)

- (NSData *)bu_base64:(NSString *)data;
- (NSData *)bu_hex:(NSString *)data;

@end
