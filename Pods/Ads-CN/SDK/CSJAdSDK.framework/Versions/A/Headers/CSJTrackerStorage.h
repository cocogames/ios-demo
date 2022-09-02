//
//  CSJTrackerStorage.h
//  CSJAdSDK
//
//  Created by 曹清然 on 2017/5/31.
//  Copyright © 2017年 chenren. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CSJTrackerStorage : NSObject

- (instancetype)initWithName:(NSString *)name;

- (NSString *)insertV1Track:(NSDictionary *)track;
//- (void)insertV1Track:(NSDictionary *)track trackID:(NSString *)trackID;
- (void)removeV1TracksByID:(NSArray *)trackIDs;
- (NSArray *)allV1Tracks;//applog3.0格式打点统计
- (void)deleteV1TrackCreatedBefore:(NSTimeInterval)timeInterval;
- (void)updateV1TrackOfIDs:(NSArray *)trackIDs sending:(BOOL)sending;

@end
