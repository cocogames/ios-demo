//
//  NSDictionary+BUCloudCommand.h
//  AWECloudCommand
//
//  Created by songxiangwu on 2018/1/3.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (BUCloudCommand)

- (int)bu_cc_intValueForKey:(NSString *)key;
- (NSInteger)bu_cc_integerValueForKey:(NSString *)key;
- (long long)bu_cc_longlongValueForKey:(NSString *)key;
- (NSString *)bu_cc_stringValueForKey:(NSString *)key;
- (NSArray *)bu_cc_arrayValueForKey:(NSString *)key;
- (NSDictionary *)bu_cc_dictionaryValueForKey:(NSString *)key;
- (id)bu_cc_objectForInsensitiveKey:(NSString *)key;

@end
