//
//  BURaptorTrackerNetworkOperation.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/5/31.
//

#import <Foundation/Foundation.h>
#import "BURaptorTrackerModel.h"
#import "CSJAPIClient.h"

NS_ASSUME_NONNULL_BEGIN


@class BURaptorTrackerNetworkOperation;
@protocol BURaptorTrackerNetworkOperationDelegate <NSObject>
@required
- (void)operation:(BURaptorTrackerNetworkOperation *)operation sendWithModelArray:(NSArray *)modelArray completionHandler:(BUResponseCompletion)completionHandler;
@end

@interface BURaptorTrackerNetworkOperation : NSOperation
@property (nonatomic, weak) id<BURaptorTrackerNetworkOperationDelegate> delegate;
@property (nonatomic, assign) NSInteger sendIndex;

- (id)initWithModelArray:(NSArray *)modelArray;
@end

NS_ASSUME_NONNULL_END
