//
//  CSJRuntimeUtilProxy.h
//  CSJAdSDK
//
//  Created by Willie on 2020/9/4.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJFoundationProxy.h"

@interfaceProxy(CSJRuntimeUtil)

///当originClass不存在originSEL时，该方法会自动添加一个imp为targetSEL的实现并替换targetSEL为原方法。调用该方法不需要再调用前做任何添加方法操作。
+ (void)bu_exchangeClassSEL:(SEL)originClassSEL
                originClass:(Class)originClass
             targetClassSEL:(SEL)targetClassSEL
                targetClass:(Class)targetClass;

+ (void)bu_exchangeInstanceSEL:(SEL)originInstanceSEL
                   originClass:(Class)originClass
             targetInstanceSEL:(SEL)targetInstanceSEL
                   targetClass:(Class)targetClass;

+ (void)bu_exchangeClassSEL:(SEL)originClassSEL
             targetClassSEL:(SEL)targetClassSEL
                     aClass:(Class)aClass;

+ (void)bu_exchangeInstanceSEL:(SEL)originSEL
             targetInstanceSEL:(SEL)targetSEL
                        aClass:(Class)aClass;
//判断当前类是否重写了方法
+ (BOOL)bu_hasImpletionClass:(Class)targetClass sel:(SEL)sel;

@end
