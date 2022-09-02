//
//  NSObject+CSJAd.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/5/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (CSJAd)


+ (void)csj_async_main_gaosiViewWithURLString:(NSString *)urlString size:(CGSize)size completion:(void(^)(UIImage *image, UIView *gaosiView))completion;


- (NSString *)csj_stringWithPropertyArray:(NSArray <NSString *>*)propertyArray;



- (BOOL)csj_instanceof_Object;
- (BOOL)csj_instanceof_Array;
- (BOOL)csj_instanceof_Dictionary;
- (BOOL)csj_instanceof_JSONObject;
- (NSArray *)csj_as_Array;
- (NSDictionary *)csj_as_Dictionary;
- (NSDictionary *)csj_as_JSONObject;

// object == nil; array.count == 0; dic.allKeys.count == 0; string.length == 0;
+ (BOOL)csj_isEmpty_object:(id)object;


@end

NS_ASSUME_NONNULL_END
