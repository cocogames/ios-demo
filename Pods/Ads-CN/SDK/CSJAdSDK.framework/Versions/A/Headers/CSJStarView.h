//
//  CSJStarView.h
//  AFNetworking
//
//  Created by bytedance on 2021/9/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJStarView : UIView

@property (nonatomic, assign) CGSize starSize;//星星尺寸 默认 {12,12}
@property (nonatomic, assign) CGFloat starMargin;//星星间的间距 默认 2
@property (nonatomic, assign) CGFloat score;//默认0

@end

NS_ASSUME_NONNULL_END
