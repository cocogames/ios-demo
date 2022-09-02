//
//  BUStaticPlugin.h
//  BURexxar
//
//  Created by muhuai on 2017/4/27.
//  Copyright © 2017年 muhuai. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BUJSBDefine.h"

@protocol BURexxarEngine;
@class BUJSBCommand;
typedef void(^BUJSBStaticHandler)(NSDictionary *params, BUJSBResponse completion);

@interface BUStaticPlugin : NSObject

- (void)registerHandlerBlock:(BUJSBStaticHandler)handler forMethodName:(NSString*)method;

- (BOOL)callHandlerWithCommand:(BUJSBCommand *)command engine:(id<BURexxarEngine>)engine completion:(BUJSBResponse)completion;
@end
