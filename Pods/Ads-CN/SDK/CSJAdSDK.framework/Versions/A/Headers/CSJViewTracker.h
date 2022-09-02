//
//  CSJViewTracker.h
//  CSJAdSDK
//
//  Created by carl on 2017/8/9.
//  Copyright © 2017年 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSJAdSDKDefines+Private.h"

typedef NS_ENUM(NSInteger, BUViewTrackerRepeatType) {
    BUViewTrackerRepeatType_none         = 1,    //上报一次
    BUViewTrackerRepeatType_repeat       = 2,    //重复检测上报
};

typedef NS_ENUM(NSInteger, BUViewTrackerLastPresentation) {
    BUViewTrackerLastPresentation_outScreen     = 0,    //上次检测的上报时在屏幕外
    BUViewTrackerLastPresentation_inScreen      = 1,    //上次检测的上报时在屏幕上
};

@protocol CSJViewTracker <NSObject>
@property (nonatomic, assign) BOOL isWitness;
@property (nonatomic, assign) BUViewTrackerRepeatType repeatType;
@property (nonatomic, assign) BUViewTrackerLastPresentation lastPresentation;
@property (nonatomic, assign) NSTimeInterval showTimestamp;
//出现了EXD_BAD_ACCESS KERN_INVALID_ADDRESS,所以改为atomic
@property (atomic, copy) void(^showEvent)(id<CSJViewTracker>);
/// 4700自渲染摇一摇检测使用,BUViewTrackerRepeatType_repeat类型
/// 其他业务要使用需要查看一下具体逻辑
@property (atomic, copy) void(^dismissEvent)(id<CSJViewTracker>);
@property (nonatomic, strong) NSDictionary *extra;
@property (nonatomic, strong) id<CSJAd> admodel;

- (BOOL)invalid;
- (BOOL)checkIfViewInScreen;
@end

/*
 BUViewTracker用于单个view
 */
@interface CSJViewTracker : NSObject <CSJViewTracker>
@property (nonatomic, weak) UIView *view;
@property (nonatomic, strong) id<CSJAd> admodel;
@property (nonatomic, strong) NSDictionary *extra;
@property (nonatomic, assign) BOOL isWitness;
@property (nonatomic, assign) BUViewTrackerRepeatType repeatType;
@property (nonatomic, assign) BUViewTrackerLastPresentation lastPresentation;
@property (atomic, copy) void(^showEvent)(id<CSJViewTracker>);
@property (atomic, copy) void(^dismissEvent)(id<CSJViewTracker>);
@property (nonatomic, assign) NSTimeInterval showTimestamp;
@property (nonatomic, copy) NSString *source;
@property (nonatomic, copy) NSString *tag;

- (BOOL)checkIfViewInScreen;
- (BOOL)invalid;
@end

/*
 BUNativeViewTracker用于多个view
 */
@interface CSJNativeViewTracker : NSObject  <CSJViewTracker>
@property (nonatomic, strong) NSPointerArray *views;
@property (nonatomic, strong) id<CSJAd> admodel;
@property (nonatomic, strong) NSDictionary *extra;
@property (nonatomic, assign) BOOL isWitness;
@property (nonatomic, assign) BUViewTrackerRepeatType repeatType;
@property (nonatomic, assign) BUViewTrackerLastPresentation lastPresentation;
@property (atomic, copy) void(^showEvent)(id<CSJViewTracker>);
@property (atomic, copy) void(^dismissEvent)(id<CSJViewTracker>);
@property (nonatomic, assign) NSTimeInterval showTimestamp;
@property (nonatomic, copy) NSString *tag;

- (BOOL)checkIfViewInScreen;
- (BOOL)invalid;

@end

