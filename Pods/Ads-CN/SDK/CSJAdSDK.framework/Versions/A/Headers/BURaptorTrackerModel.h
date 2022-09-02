//
//  BURaptorTrackerModel.h
//  CSJAdSDK
//
//  Created by Rush.D.Xzj on 2022/5/16.
//

#import <Foundation/Foundation.h>
#import "BUDB.h"

NS_ASSUME_NONNULL_BEGIN

@interface BURaptorTrackerModel : NSObject<BUDBAutoModel>


@property (nonatomic, copy) NSString *trackID;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, copy) NSString *value;
@property (nonatomic, copy) NSString *gen_time;
@property (nonatomic, assign) NSInteger encrypt;
// 0 未发送， 1 正在发送中
@property (nonatomic, assign) NSInteger sending;

@property (nonatomic, copy) NSDictionary *eventDataDict;



- (id)initWithEventDataDict:(NSDictionary *)eventDataDict index:(NSInteger)index;


#pragma mark - Public
- (NSString *)keyDictionayValue;
- (NSString *)keyDictionayKey;
- (BOOL)isRealTimeTracker;
- (BOOL)isDebugTracker;
- (NSString *)customDebugInfo;
- (NSString *)keyValueInfo;

- (NSString *)eventExtraInfoKey;
- (NSDictionary *)eventExtraInfoDict;
- (NSArray *)realTimeTrackerArray;
- (NSArray *)debugTrackerArray;

- (void)updateEventDataDict_custom_extra_ad_data_WithDict:(NSDictionary *)dict;
- (void)appendEventDataDict_custom_extra_ad_data_WithDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
