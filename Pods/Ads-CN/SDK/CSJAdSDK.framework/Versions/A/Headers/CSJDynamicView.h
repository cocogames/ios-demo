//
//  CSJDynamicView.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2020/7/28.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJDynamicViewProtocol.h"
#import "CSJAdInfoViewModel.h"
#import "CSJDynamicNativeViewModel.h"
#import "CSJDynamicViewGlobalModel.h"

NS_ASSUME_NONNULL_BEGIN







@interface CSJDynamicView : UIView


@property (nonatomic, weak) id<CSJDynamicViewDelegate> delegate;

@property (nonatomic, readonly) BOOL valid;
@property (nonatomic, strong) CSJDynamicViewGlobalModel *globalModel;

- (CSJDynamicView *)initWithInfoViewModel:(CSJAdInfoViewModel *)infoViewModel dynamicNativeViewModel:(CSJDynamicNativeViewModel *)dynamicNativeViewModel layoutInfoDictionary:(NSDictionary *)layoutInfoDictionary;

- (void)renderWithBeforeSuccessBlock:(void(^)(void))beforeSuccessBlock;

- (UIView *)videoView;

- (void)updateWithDarkMode:(BOOL)darkMode;



@end

NS_ASSUME_NONNULL_END
