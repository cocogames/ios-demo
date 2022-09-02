//
//  UIView+CSJSupContainerView.h
//  CSJAdSDK
//
//  Created by bytedance on 2021/3/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CSJSupContainerView)
- (UITableView *)csj_superContainerTableView;
- (UITableViewCell *)csj_superContainerTableViewCell;

- (UICollectionView *)csj_superContainerCollectionView;
- (UICollectionViewCell *)csj_superContainerCollectionCell;
@end

NS_ASSUME_NONNULL_END
