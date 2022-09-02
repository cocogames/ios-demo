//
//  CSJVideoFinishView.h
//  CSJAdSDK
//
//  Created by 崔亚楠 on 2018/9/21.
//  Copyright © 2018年 bytedance. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSJMaterialMeta.h"
#import "CSJAdSlot+Private.h"

typedef NS_ENUM(NSUInteger, BUVideoFinshMode) {
    BUVideoFinshModeFeed    = 0,    // 信息流视频页
    BUVideoFinshModeDetail  = 1,    // 视频详情页(视频+落地页)
    BUVideoFInshModeImageOnly = 2,  // 只有cover图片
};


@protocol CSJVideofinishViewProtocol <NSObject>
@property (nonatomic, copy)dispatch_block_t detailClick;
@property (nonatomic,strong) CSJMaterialMeta *materialMeta;
@property (nonatomic, strong) CSJAdSlot *adSlot;

- (void)setFinishViewDataWithMaterialMeta:(CSJMaterialMeta *)materialMeta;
- (void)reSetFrameWithsuperFrame:(CGRect)frame;

@end

@protocol CSJNormalVideoFinishViewProtocol <CSJVideofinishViewProtocol>

@property (nonatomic, copy)dispatch_block_t replayClick;
- (void)setupFinshMode:(BUVideoFinshMode)finshMode;

@end


@interface CSJNormalVideoFinishView : UIView<CSJNormalVideoFinishViewProtocol>

- (void)setupFinshMode:(BUVideoFinshMode)finshMode;

@end


@interface CSJDrawVideoFinishView : UIView<CSJVideofinishViewProtocol>

@property (nonatomic, copy)dispatch_block_t replayClick;

@end
