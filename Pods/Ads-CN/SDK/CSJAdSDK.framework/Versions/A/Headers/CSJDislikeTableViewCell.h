//
//  CSJDislikeTableViewCell.h
//  CSJAdSDK
//
//  Created by iCuiCui on 2018/12/11.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class CSJDislikeWords;

@interface CSJDislikeTableViewCell : UITableViewCell
- (void)refleshUIWithModel:(CSJDislikeWords *)model hiddenSep:(BOOL)hiddenSep;
@end

@interface CSJDislikeHeaderViewForTwo : UIView
@property (nonatomic, copy, nullable) void(^dislikeBack)(void);

@end

NS_ASSUME_NONNULL_END
