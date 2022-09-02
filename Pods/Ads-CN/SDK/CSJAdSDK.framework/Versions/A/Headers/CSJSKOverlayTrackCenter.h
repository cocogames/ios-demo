//
//  CSJSKOverlayTrackCenter.h
//  CSJAdSDK
//
//  Created by Eason on 2021/7/1.
//

#import <Foundation/Foundation.h>
#import "CSJAdInfoViewModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface CSJSKOverlayTrackCenter : NSObject

@property (nonatomic, strong) CSJAdInfoViewModel *infoModel;

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
