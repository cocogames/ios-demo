//
//  CSJDislikeNewBaseCell.h
//  CSJAdSDK
//
//  Created by xzj on 2020/4/21.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJDislikeWordsViewModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSJDislikeNewBaseCell : UITableViewCell

- (void)refreshWithDislikeWordsViewModel:(CSJDislikeWordsViewModel *)viewModel;
@end

NS_ASSUME_NONNULL_END
