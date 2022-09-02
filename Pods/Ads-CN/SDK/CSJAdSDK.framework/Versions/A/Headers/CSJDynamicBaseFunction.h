//
//  CSJDynamicBaseFunction.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/6/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN









@protocol CSJDynamicAbstractViewContentLengthDelegate <NSObject>

@optional
+ (CGSize)sizeForContent:(NSString *)content brickType:(NSString *)brickType style:(NSDictionary *)style lineFeed:(BOOL)lineFeed lineLimit:(BOOL)lineLimit lineCount:(NSInteger)lineCount;

+ (NSString *)updateContentForSizeWithOriginContent:(NSString *)content;

@end


@interface CSJDynamicBaseFunction : NSObject


+ (CGSize)getDomSizeFromNative_content: (NSString *)content brickType:(NSString *)brickType style:(NSDictionary *)style lineFeed:(BOOL)lineFeed lineLimit:(BOOL)lineLimit lineCount:(NSInteger)lineCount;

#pragma mark - analysis
+ (NSDictionary *)dictionayAfterKeyFormatWithOriginDictionay:(NSDictionary *)originDictionay key:(NSString *)key value1:(id)value1 value2:(id)value2;


+ (NSDictionary *)dictionaryWithObject:(id)object;

+ (NSDictionary *)dictonaryWithFormatDictionary:(NSDictionary *)dict keyArray:(NSArray *)keyArray;


+ (NSDictionary *)brickValueConfigDictionaryWithType:(NSString *)type;



#pragma mark - color
+ (UIColor *)colorWithString:(NSString *)string;

#pragma mark - render
+ (NSInteger)numberOfLinesWithLineFeed:(BOOL)lineFeed lineLimit:(BOOL)lineLimit lineCount:(NSInteger)lineCount;

+ (NSString *)typeClassStringWithType:(NSString *)type error:(NSError **)error;


+ (UIFont *)textFontWithStyle:(NSDictionary *)style;
+ (UIFont *)textFontWithFontFamily:(NSString *)fontFamily fontSize:(CGFloat)fontSize fontWeight:(CGFloat)fontWeight;
@end

NS_ASSUME_NONNULL_END
