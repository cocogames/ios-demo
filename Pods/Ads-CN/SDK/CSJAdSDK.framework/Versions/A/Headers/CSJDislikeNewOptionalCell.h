//
//  CSJDislikeNewOptionalCell.h
//  CSJAdSDK
//
//  Created by xzj on 2020/4/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import "CSJDislikeNewBaseCell.h"

NS_ASSUME_NONNULL_BEGIN

@class CSJDislikeNewOptionalCell;

@protocol CSJDislikeNewOptionalCellDelegate <NSObject>

- (void)dislikeNewOptionalCell:(CSJDislikeNewOptionalCell *)dislikeNewOptionalCell selectedDislikeWords:(CSJDislikeWords *)dislikeWords;

@end

@interface CSJDislikeNewOptionalCell : CSJDislikeNewBaseCell

@property (nonatomic, weak) id<CSJDislikeNewOptionalCellDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
