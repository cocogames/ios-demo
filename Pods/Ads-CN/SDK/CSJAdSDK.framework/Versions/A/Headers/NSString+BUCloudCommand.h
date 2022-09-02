
#import <Foundation/Foundation.h>

@interface NSString (BUCloudCommand)

- (NSString *)bu_urlStringByAddingComponentString:(NSString *)componentString;
- (NSString *)bu_urlStringByAddingComponentArray:(NSArray<NSString *> *)componentArray;
+ (NSString *)bu_queryStringWithParamDictionary:(NSDictionary *)param;

@end

