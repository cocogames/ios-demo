//
//  BURelyFoundation.h
//  BURelyFoundation
//
//  Created by zth on 2022/7/8.
//

#import <Foundation/Foundation.h>

/// 依赖层版本号
FOUNDATION_EXPORT NSString *_Nonnull const BURelyFoundationVersion;

/**
 @Warning 请注意. 在这里import的文件需要
                       (1) 是独立模块的header文件. 不应该是独立模块中某一个具体的.h文件
                       (2) 请添加__has_include的判断
 */
#ifndef BURelyFoundation_h
#define BURelyFoundation_h


#if __has_include(<BURelyFoundation/BURelyFoundation.h>)    //  CSJ

# pragma mark - NET

#if __has_include(<BURelyFoundation/BUNetWorkHeader.h>)
#import <BURelyFoundation/BUNetWorkHeader.h>
#endif

# pragma mark - Foundation

#if __has_include(<BURelyFoundation/BUFoundationHeader.h>)
#import <BURelyFoundation/BUFoundationHeader.h>
#endif

# pragma mark - AFN

#if __has_include(<BURelyFoundation/BUAFNetworkingHeader.h>)
#import <BURelyFoundation/BUAFNetworkingHeader.h>
#endif


# pragma mark - SDWebImage

#if __has_include(<BURelyFoundation/BUSDWebImageHeader.h>)
#import <BURelyFoundation/BUSDWebImageHeader.h>
#endif


# pragma mark - YYModel

#if __has_include(<BURelyFoundation/BUYYModelHeader.h>)
#import <BURelyFoundation/BUYYModelHeader.h>
#endif

# pragma mark - ZFPlayer

#if __has_include(<BURelyFoundation/BU_ZFPlayer.h>)
#import <BURelyFoundation/BU_ZFPlayer.h>
#endif


# pragma mark - Zip

#if __has_include(<BURelyFoundation/BUZipHeader.h>)
#import <BURelyFoundation/BUZipHeader.h>
#endif

# pragma mark - Gecko

#if __has_include(<BURelyFoundation/BUGeckoHeader.h>)
#import <BURelyFoundation/BUGeckoHeader.h>
#endif

# pragma mark - SVGKit

#if __has_include(<BURelyFoundation/BUSVGKitHeader.h>)
#import <BURelyFoundation/BUSVGKitHeader.h>
#endif

#elif __has_include(<BURelyFoundation_Global/BURelyFoundation.h>)  //  Pangle

# pragma mark - NET

#if __has_include(<BURelyFoundation_Global/BUNetWorkHeader.h>)
#import <BURelyFoundation_Global/BUNetWorkHeader.h>
#endif

# pragma mark - Foundation

#if __has_include(<BURelyFoundation_Global/BUFoundationHeader.h>)
#import <BURelyFoundation_Global/BUFoundationHeader.h>
#endif

# pragma mark - AFN

#if __has_include(<BURelyFoundation_Global/BUAFNetworkingHeader.h>)
#import <BURelyFoundation_Global/BUAFNetworkingHeader.h>
#endif


# pragma mark - SDWebImage

#if __has_include(<BURelyFoundation_Global/BUSDWebImageHeader.h>)
#import <BURelyFoundation_Global/BUSDWebImageHeader.h>
#endif


# pragma mark - YYModel

#if __has_include(<BURelyFoundation_Global/BUYYModelHeader.h>)
#import <BURelyFoundation_Global/BUYYModelHeader.h>
#endif

# pragma mark - ZFPlayer

#if __has_include(<BURelyFoundation_Global/BU_ZFPlayer.h>)
#import <BURelyFoundation_Global/BU_ZFPlayer.h>
#endif


# pragma mark - Zip

#if __has_include(<BURelyFoundation_Global/BUZipHeader.h>)
#import <BURelyFoundation_Global/BUZipHeader.h>
#endif

# pragma mark - Gecko

#if __has_include(<BURelyFoundation_Global/BUGeckoHeader.h>)
#import <BURelyFoundation_Global/BUGeckoHeader.h>
#endif

# pragma mark - SVGKit

#if __has_include(<BURelyFoundation_Global/BUSVGKitHeader.h>)
#import <BURelyFoundation_Global/BUSVGKitHeader.h>
#endif

#else                   // .a


# pragma mark - NET

#if __has_include("BUNetWorkHeader.h")
#import "BUNetWorkHeader.h"
#endif

# pragma mark - Foundation

#if __has_include("BUFoundationHeader.h")
#import "BUFoundationHeader.h"
#endif

# pragma mark - AFN

#if __has_include("BUAFNetworkingHeader.h")
#import "BUAFNetworkingHeader.h"
#endif

# pragma mark - SDWebImage

#if __has_include("BUSDWebImageHeader.h")
#import "BUSDWebImageHeader.h"
#endif


# pragma mark - YYModel

#if __has_include("BUYYModel.h")
#import "BUYYModel.h"
#endif

# pragma mark - ZFPlayer
#if __has_include("BU_ZFPlayer.h")
#import "BU_ZFPlayer.h"
#endif

# pragma mark - Zip

#if __has_include("BUZipHeader.h")
#import "BUZipHeader.h"
#endif

# pragma mark - Gecko

#if __has_include("BUGeckoHeader.h")
#import "BUGeckoHeader.h"
#endif

# pragma mark - SVGKit

#if __has_include("BUSVGKitHeader.h")
#import "BUSVGKitHeader.h"
#endif


#endif


#endif /* BURelyFoundation_h */

