//
//  CSJFullLinkTrackInfo.h
//  AFNetworking
//
//  Created by Rush.D.Xzj on 2021/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJFullLinkTrackInfo : NSObject


@property (nonatomic, strong) BUThreadSafeDictionary *logDict;

- (void)addWithLogKey:(NSString *)logKey extraDic:(NSDictionary * _Nullable)extraDic;

- (NSDictionary *)dictionaryValue;

@end

NS_ASSUME_NONNULL_END
