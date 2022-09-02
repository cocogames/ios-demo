//
//  CSJNormalVideoFinishViewAutoResize.h
//  CSJAdSDK
//
//  Created by ByteDance on 2022/6/20.
//

#import <UIKit/UIKit.h>
#import "CSJVideoFinishView.h"

NS_ASSUME_NONNULL_BEGIN

// 根据父视图大小自动适应
@interface CSJNormalVideoFinishViewAutoResize : UIView<CSJNormalVideoFinishViewProtocol>

- (void)setupFinshMode:(BUVideoFinshMode)finshMode;

@end

NS_ASSUME_NONNULL_END
