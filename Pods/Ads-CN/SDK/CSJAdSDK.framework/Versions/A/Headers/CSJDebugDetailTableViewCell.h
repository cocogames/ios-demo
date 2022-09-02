//
//  CSJDebugDetailTableViewCell.h
//  CSJAdSDK
//
//  Created by bytedance on 2022/2/17.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJDebugDetailTableViewCell : UITableViewCell

@property (nonatomic, strong, readonly) UILabel *titleLabel;
@property (nonatomic, strong, readonly) UILabel *detailLabel;

@end

NS_ASSUME_NONNULL_END
