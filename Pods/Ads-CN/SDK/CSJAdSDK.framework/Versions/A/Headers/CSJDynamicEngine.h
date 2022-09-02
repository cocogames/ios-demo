//
//  CSJDynamicEngine.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2021/7/5.
//

#import <Foundation/Foundation.h>
#import "CSJDynamicView.h"
#import "CSJAdInfoViewModel.h"
#import "CSJRenderEngineViewModel.h"
#import "CSJDynamicEngineAdapter.h"
NS_ASSUME_NONNULL_BEGIN
@class CSJDynamicEngine;




@protocol CSJDynamicEngineDelegate <NSObject>

- (void)beginParseInDynamicEngine:(CSJDynamicEngine *)dynamicEngine;
- (void)endParseInDynamicEngine:(CSJDynamicEngine *)dynamicEngine layoutInfo:(NSDictionary *)layoutInfo error:(NSError *)error;
- (void)beginRenderInDynamicEngine:(CSJDynamicEngine *)dynamicEngine;
- (void)middleRenderInDynamicEngine:(CSJDynamicEngine *)dynamicEngine dynamicView:(CSJDynamicView *)dynamicView error:(NSError *)error;
- (void)endRenderInDynamicEngine:(CSJDynamicEngine *)dynamicEngine error:(NSError *)error;

@end


@interface CSJDynamicEngine : NSObject
@property (nonatomic, weak) id<CSJDynamicEngineDelegate> delegate;
@property (nonatomic, strong) CSJRenderEngineViewModel *renderEngineViewModel;

- (id)initWithDynamicEngineVersion:(BUDynamicEngineVersion)dynamicEngineVersion renderEngineViewModel:(CSJRenderEngineViewModel *)renderEngineViewModel;

- (void)parseWithOriginInfo:(NSDictionary *)originInfo;
- (void)renderWithLayoutInfo:(NSDictionary *)layoutInfo;

@end

NS_ASSUME_NONNULL_END
