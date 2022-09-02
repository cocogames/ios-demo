//
//  CSJPlayableTagView.h
//  CSJAdSDK
//
//  Created by yujie on 2022/2/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSJPlayableTagCell: UIView
- (instancetype)initWith:(NSString *)tag;
@end

@interface CSJPlayableTagView : UIView
@property (nonatomic, assign) CGFloat length;
- (BOOL)addTag:(CSJPlayableTagCell *)tagCell;
@end

NS_ASSUME_NONNULL_END
