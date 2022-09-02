//
//  CSJDislikePersonalPromptsView.h
//  CSJAdSDK
//
//  Created by bytedance on 2020/11/18.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class CSJPersonalizationPrompts;
@class CSJDislikePersonalPromptsView;

@protocol CSJDislikePersonalPromptsDelegate <NSObject>

@optional
- (void)dislikePersonalPromptsDidSelected:(CSJDislikePersonalPromptsView *)promptsView;

@end

@interface CSJDislikePersonalPromptsView : UIView

@property (nonatomic, weak) id<CSJDislikePersonalPromptsDelegate> delegate;

- (void)configureWith:(CSJPersonalizationPrompts *)personalPrompts;
@end

NS_ASSUME_NONNULL_END
