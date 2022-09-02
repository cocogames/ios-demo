//
//  NSObject+BUCN.h
//  BUCNAuxiliary
//
//  Created by Rush.D.Xzj on 2020/10/19.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (BUCN)


// 目前这两个函数只适合返回值是id或者void，返回值是基本类型，可能有些异常的问题
+ (id)bucn_safePerformWithInstance:(id)instance selectorString:(NSString *)selectorString isVoidReturnType:(BOOL)isVoidReturnType error:(NSError ** _Nullable)error;
+ (id)bucn_safePerformWithInstance:(id)instance selectorString:(NSString *)selectorString object:(id _Nullable)object isVoidReturnType:(BOOL)isVoidReturnType error:(NSError ** _Nullable)error;
+ (id)bucn_safePerformWithInstance:(id)instance selectorString:(NSString *)selectorString object:(id _Nullable)object object2:(id _Nullable)object2 isVoidReturnType:(BOOL)isVoidReturnType error:(NSError ** _Nullable)error;

@end

NS_ASSUME_NONNULL_END
