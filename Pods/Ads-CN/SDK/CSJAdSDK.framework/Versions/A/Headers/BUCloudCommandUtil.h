
#import <Foundation/Foundation.h>

@interface BUCloudCommandUtil : NSObject

+ (id)payloadWithDecryptData:(NSData *)data withKey:(NSString *)key;

@end
