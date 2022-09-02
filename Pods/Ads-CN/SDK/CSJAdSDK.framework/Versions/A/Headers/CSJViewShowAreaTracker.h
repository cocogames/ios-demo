//
//  CSJViewShowAreaTracker.h
//  CSJAdSDK
//
//  Created by Willie on 2020/12/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^BUViewShowAreaTrackBlock)(UIView *view, CGFloat area, CGFloat ratio);

@interface CSJViewShowAreaTracker : NSObject

- (void)trackWithView:(UIView *)view
        showAreaBlock:(BUViewShowAreaTrackBlock)showAreaBlock;

- (void)stopTrackWithView:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
