//
//  CSJDynamicSDKFlexiableInfoModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/9/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDynamicSDKFlexiableInfoModel : NSObject <NSCopying>
@property (nonatomic, assign) CGFloat size;
@property (nonatomic, assign) BOOL isFixed;
@property (nonatomic, assign) CGFloat flexMaxSize;
@end

NS_ASSUME_NONNULL_END
