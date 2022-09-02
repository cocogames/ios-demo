//
//  BURaptorTrackMonitorManager.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/5/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


static NSString *const BURaptorTrackMonitor_ExceptionTracker =  @"BURaptorTrackMonitor_ExceptionTracker";


//static NSString *const BURaptorTrackMonitor_HttpBodyIsEmpty =  @"BURaptorTrackMonitor_HttpBodyIsEmpty";
//static NSString *const BURaptorTrackMonitor_ApplogReportFailed =  @"BURaptorTrackMonitor_ApplogReportFailed";
//static NSString *const BURaptorTrackMonitor_FilePathIsNil =  @"BURaptorTrackMonitor_FilePathIsNil";



@interface BURaptorTrackMonitorManager : NSObject
- (void)setup;
#pragma mark - Signal
+ (instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
