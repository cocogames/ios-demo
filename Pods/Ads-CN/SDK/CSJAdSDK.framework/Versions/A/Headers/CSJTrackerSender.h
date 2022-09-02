//
//  CSJTrackerSender.h
//  Article
//
//  Created by fengyadong on 17/5/3.
//
//

#import <Foundation/Foundation.h>
#import "CSJTrackerHeader.h"

/**
 *  JSON网络请求回调
 *
 *  @param error    错误
 *  @param jsonObj  返回的json对象
 *  @param isPinAppLogUrl 是否固定了上报地址 (4300 海外 在广告响应中指定事件上报机房 )
 */

typedef void (^BUTrackerNetworkJSONFinishBlock)(NSError *error, id jsonObj, BOOL isPinAppLogUrl);

@interface CSJTrackerSender : NSObject

+ (void)asyncRequestForParams:(id)params
                  trackerType:(BUTrackerType)trackerType
                     callback:(BUTrackerNetworkJSONFinishBlock)callback;

@end
