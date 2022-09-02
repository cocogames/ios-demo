//
//  BUActionWorker.h
//  BUFoundation
//
//  Created by bytedance on 2021/3/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BUActionWorker;
@class BUCacheAction;
@class BUMediaCacheWorker;
@class BUURLSessionDelegateObject;

@protocol BUActionWorkerDelegate <NSObject>

- (void)actionWorker:(BUActionWorker *)actionWorker didReceiveResponse:(NSURLResponse *)response;

- (void)actionWorker:(BUActionWorker *)actionWorker didReceiveData:(NSData *)data isLocal:(BOOL)isLocal;

- (void)actionWorker:(BUActionWorker *)actionWorker didReceiveLength:(NSInteger)receiveLength didFinishWithError:(nullable NSError *)error responseDesc:(NSString *)responseDesc;

@end

@class BUActionWorker;

@interface BUActionWorker : NSObject

@property (nonatomic, weak) id<BUActionWorkerDelegate> delegate;

/// 是否都是本地缓存
@property (nonatomic, assign) BOOL localCacheOnly;

- (instancetype)initWithActions:(NSArray<BUCacheAction *> *)actions url:(NSURL *)url cacheWorker:(BUMediaCacheWorker *)cacheWorker;

- (void)start;

- (void)cancel;

+ (void)test;
@end


NS_ASSUME_NONNULL_END
