//
//  CSJWebViewDynamicRenderOperation.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/2/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CSJWebViewDynamicRenderDelegate <NSObject>

@required
- (void)webViewWillRenderInImplementation:(id)implementation;
- (void)webViewDidRenderInImplementation:(id)implementation;

@end

@protocol CSJWebViewDynamicRenderInterface <NSObject>

@required
@property (nonatomic, weak) id<CSJWebViewDynamicRenderDelegate> implementation_delegate;
- (NSInteger)implementation_renderIndex;
- (void)implementation_render_really;
- (NSTimeInterval)implementation_timeOut;

@end



@interface CSJWebViewDynamicRenderOperation : NSOperation <CSJWebViewDynamicRenderDelegate>

@property (nonatomic, strong) id<CSJWebViewDynamicRenderInterface> implementation;

- (id)initWithImplementation:(id<CSJWebViewDynamicRenderInterface>)implementation;

@end

NS_ASSUME_NONNULL_END
