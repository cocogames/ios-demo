//
//  CSJDislikeWordsViewModel.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/4/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJDislikeWords.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDislikeWordsViewModel : NSObject

@property (nonatomic, strong, readonly) CSJDislikeWords *dislikeWords;

- (instancetype)initWithDislikeWords:(CSJDislikeWords *)dislikeWords;

@property (nonatomic, readonly) CGFloat cellHeight;

@end

NS_ASSUME_NONNULL_END
